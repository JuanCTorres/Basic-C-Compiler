/* symtab.c
 * Functions for the symbol table.
 * Written by THC for CS 57.
 *
 * extended and changed by sws
 *
 * Extended by Juan C. Torres, SeokJun Bing
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "symtab.h"


#define DELTA 10
#define ELEMSIZE 4
#define DEFAULT_ARRAY_PARAM_SIZE 20

extern int symtabError;
extern int typeError;
extern int returnError;
extern int funcError;
extern int exprTypeError;

// int siblings[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int *siblings;
static int *trash_array;
static unsigned arraylen = 0;
static unsigned arraylen_trash = 0;

static const int HASHSIZE = 211;
//static const int MAXINTSIZE = 4;  // for now
static const int DEFAULTSTRSIZE = 100;

/* Create an empty symbol table. */
 symboltable_t  *create_symboltable() {
  symboltable_t *symtab = calloc(sizeof(symboltable_t),1);
  assert(symtab);

  symhashtable_t *hashtable=create_symhashtable(HASHSIZE);
  assert(hashtable != NULL);
  hashtable->level = 0;
  hashtable->name = "0";

  symhashtable_t *collection = create_symhashtable(HASHSIZE);
  assert(collection != NULL);
  symtab->literal_collection = collection;

  symtab->root = hashtable;
  symtab->leaf = hashtable;
  return symtab;
}


/* Peter Weinberger's hash function, from Aho, Sethi, & Ullman
   p. 436. */
static int hashPJW(char *s, int size) {
  unsigned h = 0, g;
  char *p;

  for (p = s; *p != '\0'; p++) {
    h = (h << 4) + *p;
    if ((g = (h & 0xf0000000)) != 0)
      h ^= (g >> 24) ^ g;
  }

  return h % size;
}

int name_is_equal(symnode_t *node, char *name) {
  return !strcmp(node->name, name);

}


void set_node_name(symnode_t *node, char *name) {
  node->name = name;
}


/* Create an empty symhashtable and return a pointer to it.  The
   parameter entries gives the initial size of the table. */
symhashtable_t *create_symhashtable(int entries) {
  symhashtable_t *hashtable = calloc(sizeof(symhashtable_t), 1);
  assert(hashtable);
  hashtable->size = entries;
  hashtable->table = calloc(entries, sizeof(symnode_t *));

  assert(hashtable->table);

  /* anything else ? */

  return hashtable;
}


/* Look up an entry in a symhashtable, returning either a pointer to
   the symnode for the entry or NULL.  slot is where to look; if slot
   == NOHASHSLOT, then apply the hash function to figure it out. */
   symnode_t *lookup_symhashtable(symhashtable_t *hashtable, char *name, int slot) {
    symnode_t *node;

    assert(hashtable);

    if (slot == NOHASHSLOT)
      slot = hashPJW(name, hashtable->size);

    for (node = hashtable->table[slot];
     node != NULL && !name_is_equal(node, name);
     node = node->next)
      ;

    return node;
  }

/* hashtable input is for the symnode to point back to */
  symnode_t *create_symnode(char *name, symhashtable_t *hashtable) {
    symnode_t *node = calloc(1, sizeof(symnode_t));
    assert(node != NULL);

    node->name = strdup(name);
    node->parent = hashtable;
    node->num_parameters = 0;

    return node;
  }

  symnode_t *create_const_symnode(char* name, int val){
    symnode_t *node = calloc(1, sizeof(symnode_t));
    assert(node != NULL);

    node->name = strdup(name);
    node->num_parameters = 0;
    node->num_val = val;
    node->abnode = create_int_astnode(val);

    return node;
  }

  ast_node create_int_astnode(int val){

    assert(val < 1000);
    ast_node node = create_ast_node(INT_LITERAL_N);
    char *name = calloc(100, sizeof(char));
    sprintf(name, "__%d", val);
    node->value_string = name;
    node->value_int = val;

    return node;
  }


/* Insert a new entry into a symhashtable, but only if it is not
   already present. Return*/
  symnode_t *insert_into_symhashtable(symhashtable_t *hashtable, ast_node astnode) {

    char* name = astnode->value_string;

    assert(hashtable);

    int slot = hashPJW(name, hashtable->size);
    symnode_t *node = lookup_symhashtable(hashtable, name, slot);

  /* error check if node already existed! */
   if (node == NULL) {

      node = create_symnode(name, hashtable);

      node->abnode = astnode;
      astnode->snode = node;

      if(astnode->node_type == INT_LITERAL_N){
        node->num_val = astnode->value_int;
      }

      if(astnode->node_type == ARRAY_TYPE_N) {
        if(astnode->left_child != NULL ){
          astnode->array_length = astnode->left_child->value_int;
          node->array_length = astnode->array_length;
        }
      }

      if(astnode->node_type == STRING_LITERAL_N){
        node->type = STRING_T;
      }

      if(astnode->node_type == FUNC_DECLARATION_N) {
      //printf("FUNC_DEC detected!");
        if(astnode->return_type == INT_TYPE_N) {
          node->type = FUNC_INT_T;
          //printf(" %s\n", TYPE_NAME(node->type));
        }
        else if(astnode->return_type == VOID_TYPE_N) {
          node->type = FUNC_VOID_T;
          //printf(" %s\n", TYPE_NAME(node->type));
        }

        ast_node anode;
        int i = 0;
        assert(astnode->left_child != NULL);

        for(anode = astnode->left_child->left_child; anode != NULL; anode = anode->right_sibling) {
          i++;
        }

        node->num_parameters = i;
        node->parameters = calloc(sizeof(decl_type), i);
        assert(node->parameters);

        i = 0;

        for(anode = astnode->left_child->left_child; anode != NULL; anode = anode->right_sibling) {
          if(anode->return_type == INT_TYPE_N) {
            node->parameters[i] = VAR_INT_T;
          }
          else if(anode->return_type == ARRAY_TYPE_N){
            node->parameters[i] = VAR_ARRAY_INT_T;
          }
          i++;
        }
      }

      else if(astnode->node_type == ID_N) {
        //printf("VAR detected!");
        if(astnode->return_type == INT_TYPE_N) {
          node->type = VAR_INT_T;
          //printf(" %s\n", TYPE_NAME(node->type));
        }
      }
      else if(astnode->node_type == ARRAY_TYPE_N){
        if(astnode->return_type == INT_TYPE_N) {
          node->type = VAR_ARRAY_INT_T;
          //printf(" %s\n", TYPE_NAME(node->type));
        }
      }

      node->next = hashtable->table[slot];
      hashtable->table[slot] = node;
    }
    else{
      if(node->abnode->node_type == ARRAY_TYPE_N || node->abnode->return_type == ARRAY_TYPE_N) {
        node->abnode->array_length = node->array_length;
      }
    }

    return node;
  }

/* Insert an entry into the innermost scope of symbol table.  First
   make sure it's not already in that scope.  Return a pointer to the
   entry. */
  symnode_t *insert_into_symboltable(symboltable_t *symtab, ast_node astnode) {

    char *name = astnode->value_string;
    assert(symtab);
    assert(symtab->leaf);

    symnode_t *node = lookup_symhashtable(symtab->leaf, name, NOHASHSLOT);

    /* error check!! */

    if (node == NULL) {
      node = insert_into_symhashtable(symtab->leaf, astnode);
      return node;
    } else {
      return NULL;
    }

  }


/* Lookup a hashtable with given lvl and sibno in a symbol table.
  If found return a pointer to it.
  Otherwise, return NULL */
  symhashtable_t *find_hashtable(symhashtable_t  *root, int lvl, int sib) {

    if(root != NULL) {
      if (lvl == root->level && sib == root->sibno) {
        return(root);
      }
    }

    symhashtable_t *res, *child;
    res = NULL;
    for(child = root->child; child != NULL  && res == NULL; child = child->rightsib) {
      //if(child != NULL) {printf("in find) lvl: %d, sibno: %d\n", child->level,child->sibno);}
      res = find_hashtable(child, lvl, sib);
    }
    return res;
  }


/*
 * This function creates a hashtable and then appropriately attaches it to its parent,
 * whose identifier is given to us in the form of its identifier (parent_lvl, parent_sibno)
 */
  symhashtable_t *make_insert_hashtable(symhashtable_t  *root, int lvl, int sibno, int parent_lvl, int parent_sibno) {
    symhashtable_t *hashtable, *parent_hashtable, *temp;

    hashtable = create_symhashtable(HASHSIZE);
    assert(hashtable != NULL);

    parent_hashtable = find_hashtable(root, parent_lvl, parent_sibno);  //parent must have been created
    assert(parent_hashtable != NULL);

    // Fill the appropriate values for our hash table.
    hashtable->parent = parent_hashtable;
    hashtable->level = lvl;
    hashtable->sibno = sibno;

    //insert as rightmost child of parent
    if(parent_hashtable->child != NULL) {
      for(temp = parent_hashtable->child ; temp->rightsib != NULL; temp = temp->rightsib) {
        ;}
        temp->rightsib = hashtable;
    }
    else {
      parent_hashtable->child = hashtable;
    }

    return hashtable;
  }


/*
 * Checks if a particular variable has already been declared.
 */
  int check_if_declared(ast_node anode, symboltable_t *symtab ,int lvl, int sibno) {

    symhashtable_t *hash = find_hashtable(symtab->root, lvl, sibno);

    assert(hash != NULL);
    assert(anode != NULL);

    /* Set node to NULL so that, if no match is found, it will be NULL and we can
     * act accordingly.
     */
    symnode_t *node = NULL;

    /*
     * Recurse up until hash table with matching identifier, or the root, is found.
     */
    for(;hash != NULL && node == NULL; hash = hash->parent) {
      node = lookup_symhashtable(hash, anode->value_string, NOHASHSLOT);
    }

    /* If not found, variable or function is undeclared. */
    if(node == NULL) {
      symtabError = 1;
      if(anode->node_type == FUNCTION_N) {
        fprintf(stderr, "line: %d | error: use of undeclared function %s\n", anode->line_num, anode->value_string);
      }
      else if(anode->node_type == ID_N || anode->node_type == ARRAY_TYPE_N) {
        fprintf(stderr, "line: %d | error: use of undeclared identifier %s\n", anode->line_num, anode->value_string);
      }

      return 0;
    }
    else { /* Otherwise, declaration for variable or function has been found */
      return 1;
    }

  }

/*
 * Function to check if a particular variable or function identifier
 * has been redefined.
 */
int check_if_redef(ast_node anode, symboltable_t *symtab ,int lvl, int sibno) {
  symhashtable_t *hash = find_hashtable(symtab->root, lvl, sibno);

  /* If scope with (lvl, sibno) identifier could be found, start search */
  if(hash != NULL) {
    /* node = NULL in case we don't find anything */
    symnode_t *node = NULL;
    node = lookup_symhashtable(hash, anode->value_string, NOHASHSLOT);

    /* Found a match in current or parent scope? */
    if(node != NULL){
      /* If abstract syntax node has a type, it was previously defined */
      if(anode->return_type != ROOT_N && anode->isDecl == 1) {
        symtabError = 1;
        if(anode->node_type == FUNC_DECLARATION_N) {
          fprintf(stderr, "line: %d | error: redefinition of function %s\n", anode->line_num ,anode->value_string);
        }
        if(anode->node_type == ID_N || anode->node_type == ARRAY_TYPE_N) {
          fprintf(stderr, "line: %d | error: redefinition of identifier %s\n", anode->line_num ,anode->value_string);
        }

        return 0;
      }
    }
  }
  /* Not found */
  return 1;
}


/*
* Returns appropriate sibling number
*/
int getSibling(int level) {
  if(level == 0) {
    return 0;
  }
  else {
    return siblings[level - 1];
  }
}




/*
 * Builds the symbol table, creating scopes as needed, and linking them together.
 * Adds variable and function identifiers to scopes appropriately.
 */
void build_symbol_table(ast_node root, int level, int sibno, symboltable_t *symtab) {
  //calculate the scope for the variable/func declaration
  //calculate the parent for that variable/func declaration
  //need function to take as input
  //printf("here \n");
  symhashtable_t *hash;

  /* Depending on node types, go deeper, create sibling scopes, add to hashtable,
   * or take other appropriate action.
   */
  switch (root->node_type) {
    ast_node param;
    int param_offset = 4;
    int param_count = 0;

    case SEQ_N:     // change main level when see a new sequence
      level++;
      break;

    case FORMAL_PARAMS_N:
      level++;
      param_count = 0;
      insert_scope_info(root, level, sibno, MAX(level - 1, 0), getSibling(level) );
    //   for(param = root->left_child; param != NULL; param = param->right_sibling){
    //     if(param->node_type == ARRAY_TYPE_N || param->return_type == ARRAY_TYPE_N){
    //      param_count += DEFAULT_ARRAY_PARAM_SIZE;
    //    }
    //    else{
    //      param_count++;
    //    }
    //  }
    //  printf("PARAM COUNT!!!!! = %d\n", param_count);
    //
    //  for(param = root->left_child; param != NULL; param = param->right_sibling){
    //    if(param->node_type == ARRAY_TYPE_N || param->return_type == ARRAY_TYPE_N){
    //      param->snode->offset = param_count * 4;
    //      param->snode->offset -= DEFAULT_ARRAY_PARAM_SIZE;
    //    }
    //    else{
    //     param->snode->offset = param_count-- * 4;
    //    }
    // }


      break;

    case FUNC_DECLARATION_N: // function declaraions
      //does hashtable exist with given lvl, siblvl (use find_hashtable)
      check_if_redef(root, symtab ,level, sibno);
      hash = find_hashtable(symtab->root, level, sibno);
      if(hash == NULL) {
        hash = make_insert_hashtable(symtab->root, level, sibno, MAX(level - 1, 0), getSibling(level) );

      }
      insert_into_symhashtable(hash, root); // will only insert if it is empty.
      insert_scope_info(root, level, sibno, MAX(level - 1, 0), getSibling(level) );
      break;

    case FUNCTION_N:
      check_if_declared(root, symtab ,level, sibno);
      insert_scope_info(root, level, sibno, MAX(level - 1, 0), getSibling(level) );
      break;

    case ID_N:      /* print the id */

        check_if_redef(root, symtab ,level, sibno);

      //if(root->return_type != 0) {  // a non-zero value means that it is a declaration, since only declarations
                                    // are assigned a return type when building the abstract syntax tree.
      if(root->isDecl){

        hash = find_hashtable(symtab->root, level, sibno);
        if(hash == NULL) {
          hash = make_insert_hashtable(symtab->root, level, sibno, MAX(level - 1, 0), getSibling(level) );
        }
        insert_into_symhashtable(hash, root);
      }
      else {  // don't know if previously declared
        check_if_declared(root, symtab , level, sibno);
      }
      insert_scope_info(root, level, sibno, MAX(level - 1, 0), getSibling(level) );
      break;

    case ARRAY_TYPE_N:             // check for return types!

        check_if_redef(root, symtab ,level, sibno);

      //cif(root->return_type != 0) {
      if(root->isDecl){
        hash = find_hashtable(symtab->root, level, sibno);
        if(hash == NULL) {
          hash = make_insert_hashtable(symtab->root, level, sibno, MAX(level - 1, 0), getSibling(level) );
          }
        insert_into_symhashtable(hash, root);
      }
      else {
        check_if_declared(root, symtab , level, sibno);
      }
      insert_scope_info(root, level, sibno, MAX(level - 1, 0), getSibling(level) );
      break;

    case RETURN_N:
      insert_scope_info(root, level, sibno, MAX(level - 1, 0), getSibling(level) );
      break;

    default:
      // printf("at default of switch\n");
      assert(symtab->root != NULL);
      hash = find_hashtable(symtab->root, level, sibno);
      if(hash == NULL) {
        hash = make_insert_hashtable(symtab->root, level, sibno, MAX(level - 1, 0), getSibling(level) );
      }
      //note: cannot use insert_scope_info here because siblings[level - 1] causes invalid read as level-1 can go negative
      break;
  }

  if(arraylen == level) {
    arraylen = arraylen + DELTA;
    siblings = realloc(siblings, sizeof(int) * arraylen);

    assert(siblings != NULL);

    for(int k=0; k < DELTA; k++) {
      siblings[arraylen - (DELTA-k)] = 0;
    }
  }

  /* Recurse on each child of the subtree root, with a depth one
     greater than the root's depth. */
  ast_node child;
  for (child = root->left_child; child != NULL; child = child->right_sibling)
    build_symbol_table(child, level, siblings[level], symtab);

  if(root->node_type == SEQ_N){//} || root->node_type == FORMAL_PARAMS_N){
    siblings[level]++;  // change sibling level after you're done printing all
                      // subtrees, i.e., after done recursing.
  }
}


/*
 * Print symbol table, with indentation to denote parent-child relations.
 */
void pretty_print(symhashtable_t *root, int depth) {

 /* Print two spaces for every level of depth. */
  int i;
  for (i = 0; i < depth; i++)
    printf("  ");

  /* Print the node type. */
  printf("(%d-%d) contains:\n", root->level, root->sibno);

  for(int j = 0; j < HASHSIZE; j++ ) {
    for(symnode_t *node = root->table[j]; node != NULL; node = node->next) {
      for (i = 0; i < depth + 1; i++) {
        printf("  ");
      }
      printf("%s %s", TYPE_NAME(node->type), node->name);

      if(node->type == FUNC_VOID_T || node->type == FUNC_INT_T) {
        printf(" (%d params:", node->num_parameters);
        for(int k = 0; k < node->num_parameters; k++) {
          printf(" %s ", TYPE_NAME(node->parameters[k]));
        }
          printf(")");
          printf("space needed: %d", node->needed_space);
      }
      if(node->type == VAR_INT_T){
        // printf(" (val: %d, offset: %d)", node->num_val, node->offset);
        printf(" (offset: %d or addr: %d)", node->offset, node->addr);
      }
      if(node->type == VAR_ARRAY_INT_T) {
        printf(" (length: %d, offset: %d or addr: %d), sym_length = %d ",
          node->abnode->array_length, node->offset, node->addr, node->array_length);
      }

        printf("\n");
      }
    }

  /* Recurse on each child of the subtree root, with a depth one
     greater than the root's depth. */
    symhashtable_t *child;
    for (child = root->child; child != NULL; child = child->rightsib)
      pretty_print(child, depth + 1);

  }

void insert_scope_info(ast_node root, int curr_level, int curr_sib, int parent_level, int parent_sib) {

  assert(root != NULL);

  root->curr_level = curr_level;
  root->curr_sib = curr_sib;
  root->parent_level = parent_level;
  root->parent_sib = parent_sib;
}

/*
* Works on an assumption that build hashtable as already been run. (i.e. no errors generated from building hashtable)
*/
void record_var_type_in_ast(ast_node root, symboltable_t *symtab) {
  symhashtable_t *hash = NULL;
  symnode_t *node = NULL;


  /* Depending on node types, go deeper, create sibling scopes, add to hashtable,
   * or take other appropriate action.
   */
  switch (root->node_type) {

    case FUNC_DECLARATION_N:
        hash = find_hashtable(symtab->root, root->curr_level, root->curr_sib);
        for(;hash != NULL && node == NULL; hash = hash->parent) {
          node = lookup_symhashtable(hash, root->value_string, NOHASHSLOT);
        }
        assert(node != NULL); //as hashtable was built prev, it must be found for func_n
        if(node->type == FUNC_VOID_T) {
          root->return_type = VOID_TYPE_N;
        } else if(node->type == FUNC_INT_T) {
          root->return_type = INT_TYPE_N;
        }
        root->line_declared = node->abnode->line_num;
      break;

    case FUNCTION_N: //all function_n nodes are calls not declarations
        hash = find_hashtable(symtab->root, root->curr_level, root->curr_sib);
        for(;hash != NULL && node == NULL; hash = hash->parent) {
          node = lookup_symhashtable(hash, root->value_string, NOHASHSLOT);
        }
        assert(node != NULL); //as hashtable was built prev, it must be found for func_n
        if(node->type == FUNC_VOID_T) {
          root->return_type = VOID_TYPE_N;
        } else if(node->type == FUNC_INT_T) {
          root->return_type = INT_TYPE_N;
        }
        root->line_declared = node->abnode->line_num;
      break;

    case ID_N:

      hash = find_hashtable(symtab->root, root->curr_level, root->curr_sib);
      assert(hash != NULL);
      for(;hash != NULL && node == NULL; hash = hash->parent) {
          //printf("  \n\n value string is %s\n\n", root->value_string);
        node = lookup_symhashtable(hash, root->value_string, NOHASHSLOT);
      }
      assert(node != NULL); //as hashtable was built prev, it must be found for ID_N

      if(root->return_type == 0) {  // a zero value means that it is not a declaration, since only declarations
                                    // are assigned a return type when building the abstract syntax tree.
        if(node->type == VAR_INT_T) {
          root->return_type = INT_TYPE_N;
        }
      }
      root->line_declared = node->abnode->line_num;
      break;

    case ARRAY_TYPE_N:             // check for return types!
      hash = find_hashtable(symtab->root, root->curr_level, root->curr_sib);
      for(;hash != NULL && node == NULL; hash = hash->parent) {
        node = lookup_symhashtable(hash, root->value_string, NOHASHSLOT);
      }
      assert(node != NULL); //as hashtable was built prev, it must be found for array_type_n
      if(root->return_type == 0) {
        if(node->type == VAR_ARRAY_INT_T){
          if(root->left_child == NULL){
            root->return_type = ARRAY_TYPE_N;
          }
          else{
            root->return_type = INT_TYPE_N;
          }
        }

      }
      root->line_declared = node->abnode->line_num;
      break;

    case INT_LITERAL_N:
      root->return_type = INT_TYPE_N;
      break;

    case RETURN_N: //not sure if we deal with this here...
      assert(symtab->root != NULL);
      break;

    default:
      // printf("at default of switch\n");
      assert(symtab->root != NULL);

      break;
  }


  /* Recurse on each child of the subtree root, with a depth one */
  ast_node child;
  for (child = root->left_child; child != NULL; child = child->right_sibling)
    record_var_type_in_ast(child, symtab);
}



/*declaration of func and identifiers is already checked during  build_symbol_table
* so here, we just check for paramter inputs into functions
*/
int check_function(ast_node root, symboltable_t *symtab) {
  symhashtable_t *hash = NULL;
  symnode_t *node = NULL;
  ast_node anode = NULL;

  switch (root->node_type) {

    case FUNCTION_N:
        hash = find_hashtable(symtab->root, root->curr_level, root->curr_sib);
        for(;hash != NULL && node == NULL; hash = hash->parent) {
          node = lookup_symhashtable(hash, root->value_string, NOHASHSLOT);
          //node is the original declaration stored in symbol table
        }
        assert(node != NULL); //as hashtable was built previously, it must be found for func_n

        // Count the number of parameters passed to the function
        int i = 0;
        for(anode = root->left_child; anode != NULL; anode = anode->right_sibling) {
          i++;
        }

        if(node->num_parameters != i) {
          funcError = 1;
          fprintf(stderr, "line: %d | Error: Number of parameters to function %s does not match number of parameters in declaration at line %d\n",
          root->line_num, root->value_string, root->line_declared);
        }
        else {
          int k = 0;
          for(anode = root->left_child; anode != NULL; anode = anode->right_sibling) {
            if(!((anode->return_type == INT_TYPE_N && node->parameters[k] == VAR_INT_T) ||
             (anode->return_type == ARRAY_TYPE_N && node->parameters[k] == VAR_ARRAY_INT_T)) ) {

            // if(!(anode->return_type == INT_TYPE_N && node->parameters[k] == VAR_INT_T)) {
              funcError = 1;
              //printf("\n\n  parm type is: %s return_type is: %s \n\n", TYPE_NAME(node->parameters[k]), NODE_NAME(anode->return_type));
              // fprintf(stderr, "\n\n %s return_type: %s but should be %s \n\n",anode->value_string ,NODE_NAME(anode->return_type), TYPE_NAME(node->parameters[k]));
              assert(anode != NULL);
              //assert(anode->snode
              //assert(anode->snode);
              fprintf(stderr, "%dth param. Expecting  %s, got (%s, %s)\n",
                k, TYPE_NAME(node->parameters[k]), NODE_NAME(anode->return_type), NODE_NAME(anode->node_type));
              //fprintf(stderr, "snode of ^ is %s ", anode->snode->name);
              fprintf(stderr, "line: %d | Error: Input parameters to function %s do not match the declaration at line %d\n",
                root->line_num, root->value_string, root->line_declared);
              return 1;
            }
            k++;
          }
        }
      break;



    default:
      // printf("at default of switch\n");
      assert(symtab->root != NULL);
      break;


  }

  /* Recurse on each child of the subtree root, with a depth one
     greater than the root's depth. */
  ast_node child;
  for (child = root->left_child; child != NULL; child = child->right_sibling)
    check_function(child, symtab);
  return 0;
}

/*
* calls check_return_helper()
*/
void check_return(ast_node root, symboltable_t *symtab) {

  ast_node funcnode = NULL;
  check_return_helper(root, symtab, funcnode);

  return;
}


/*
* Checks that there is appropriate return for functions
* Inserts an implicit return for void type functions
* For every return statement, records to which function it returns to
*/
void check_return_helper(ast_node root, symboltable_t *symtab, ast_node funcnode) {
  ast_node child2;

    switch (root->node_type) {
      case FUNC_DECLARATION_N:
        funcnode = root; //last function seen
        child2 = root->left_child->right_sibling; //to SEQ_N
        assert(child2->node_type == SEQ_N);
        child2 = child2->left_child->right_sibling; // to STATEMENT_LIST_N
        assert(child2->node_type == STATEMENT_LIST_N);
        // fprintf(stderr, "\n\n  before for %s at line %d \n\n", NODE_NAME(child2->node_type), child2->line_num);
        for (child2 = child2->left_child;
          child2 != NULL && child2->right_sibling != NULL;
          child2 = child2->right_sibling) {
          // fprintf(stderr, "\n\n  child2 %s at line %d \n\n", NODE_NAME(child2->node_type), child2->line_num);
        }

      // assert(child2 != NULL);
        if(child2 == NULL && funcnode->return_type == INT_TYPE_N) { //child2 is null when the func is empty
          returnError = 1;
          fprintf(stderr, "Error: Returning wrong type for function %s declared at line %d\n", funcnode->value_string, funcnode->line_declared);
        }
        else if (child2 == NULL) {} //need this! don't delete this line or else having empty funcs will gen error
        else if((child2->node_type != RETURN_N)){
          if(funcnode->return_type == INT_TYPE_N) {
            returnError = 1;
            fprintf(stderr, "1 line: %d | Error: No return statement in function %s\n", funcnode->line_num, funcnode->value_string);
          }
          else {
            child2->right_sibling = create_ast_node(RETURN_N); //insert implicit return for void functions
            child2->right_sibling->return_type = VOID_TYPE_N;
            child2->right_sibling->left_child = create_ast_node(VOID_TYPE_N);
            // fprintf(stderr, "\nIMPLICIT RETURN\n");
          }
        }
        else if( (child2->node_type == RETURN_N) && (funcnode->return_type == INT_TYPE_N) ) {
          //fprintf(stderr, "detected return! and int main\n");
          if(child2->left_child == NULL) {

              returnError = 1;
              fprintf(stderr, "2 line: %d | Error: Returning wrong type for function %s\n", child2->line_num, funcnode->value_string);

          }
          else {
            if(child2->left_child->return_type != INT_TYPE_N) {

              returnError = 1;
              fprintf(stderr, "3 line: %d | Error: Returning wrong type for function %s\n", child2->line_num, funcnode->value_string);
            }
          }
        }
        else if( (child2->node_type == RETURN_N) && (funcnode->return_type == VOID_TYPE_N) ) {
          //fprintf(stderr, "detected return! and void main\n");
          if(child2->left_child != NULL) { //returning something
            returnError = 1;
            fprintf(stderr, "4 line: %d | Error: Returning wrong type for function %s\n", child2->line_num, funcnode->value_string);
          }

        }



        break;

      case RETURN_N:
        assert(root != NULL);
        assert(funcnode != NULL);
        root->return_to = funcnode;
        // fprintf(stderr,"\nreturn to %s at line %d\n", root->return_to->value_string, root->return_to->line_declared);
        break;

      default:
        break;
    }

    ast_node child;
    for (child = root->left_child; child != NULL; child = child->right_sibling)
      check_return_helper(child, symtab, funcnode);



}

/* Infers the type of operations with return types. For unary operators, such as
! and unary minus, the operator is assigned the return type of its child.
For binary operators, the operator is assigned the return type of its
children, only if both children have the same return type.
 */
void infer_type(ast_node root){

  /* Note: post-order traversal, unlike most other traversals */
  ast_node child;
  for (child = root->left_child; child != NULL; child = child->right_sibling){
    infer_type(child);
  }

  /* Only assign a return type to nodes withouth one already */
  if(root->return_type == 0){

    if(is_unary_operator(root)){
      root->return_type = root->left_child->return_type;

    } else if(is_binary_operator(root)){
      /* Check that the types of both children are equal */
      /* Assignment operator is also checked here, since it is a binary operator */
      if(root->left_child->return_type == root->left_child->right_sibling->return_type){
        root->return_type = root->left_child->return_type;
      }
    }
  } else{
  }
}


void collect_literals(ast_node root, symboltable_t *symtab){

  ast_node child;
  symnode_t *node;
  symhashtable_t *collection = symtab->literal_collection;
  assert(collection != NULL);
  char* name;
  int slot = 0;

  /* Recursively call the function to traverse the tree in a preorder way */
  for(child = root->left_child; child != NULL; child = child->right_sibling){
    collect_literals(child, symtab);
  }

  switch (root->node_type) {
    case STRING_LITERAL_N:
      name = root->value_string;

      // Calculate slot for this node, try to find the current node in the symbol table
      slot = hashPJW(name, collection->size);
      node = lookup_symhashtable(collection, name, slot);

      if(node == NULL){
        insert_into_symhashtable(collection, root);
      }

      break;

    /* Need to hash the value differently so as to not to mistake strings and
    ints, (e.g. 1 vs "1") */
    case INT_LITERAL_N:

      name = calloc(DEFAULTSTRSIZE, sizeof(char));
      sprintf(name, "__%d", root->value_int);
      root->value_string = strdup(name);

      slot = hashPJW(name, collection->size);
      node = lookup_symhashtable(collection, name, slot);

      if(node == NULL){
        insert_into_symhashtable(collection, root);
      }
      break;

    case RETURN_N:
      // Empty return. Create a new symnode to add to
      // the collection because otherwise it will give us
      // trouble later when trying to create quads, since
      // the function to create quads takes symnodes and there
      // is currently no symnode for this empty return.

      if(root->left_child != NULL){
        if(root->left_child->node_type == VOID_TYPE_N){
          name = calloc(DEFAULTSTRSIZE, sizeof(char));
          sprintf(name, "__%s", "void");

          root->left_child->value_string = calloc(DEFAULTSTRSIZE, sizeof(char));
          strcpy(root->left_child->value_string, name);

          slot = hashPJW(name, collection->size);
          node = lookup_symhashtable(collection, name, slot);

          if(node == NULL){
            insert_into_symhashtable(collection, root->left_child);
          }
        }
      }
    default:
      break;
  }
}


void link_ast_to_symnode(ast_node root, symboltable_t *symtab) {
  symhashtable_t *hash = NULL;
  symnode_t *snode = NULL;

  /* Depending on node types, go deeper, create sibling scopes, add to hashtable,
   * or take other appropriate action.
   */
  switch (root->node_type) {
    case SEQ_N:     // change main level when see a new sequence
      break;

    case FORMAL_PARAMS_N:
      break;

    case FUNC_DECLARATION_N: // function declaraions
      break;

    case FUNCTION_N:
      hash = find_hashtable(symtab->root, root->curr_level, root->curr_sib);
      assert(hash != NULL);
      for(;hash != NULL && snode == NULL; hash = hash->parent) {
        snode = lookup_symhashtable(hash, root->value_string, NOHASHSLOT);
      }
      assert(snode != NULL);
      root->snode = snode;
      break;

    case ID_N:      /* print the id */
      hash = find_hashtable(symtab->root, root->curr_level, root->curr_sib);
      assert(hash != NULL);
      for(;hash != NULL && snode == NULL; hash = hash->parent) {
        snode = lookup_symhashtable(hash, root->value_string, NOHASHSLOT);
      }
      assert(snode != NULL);
      root->snode = snode;
      break;

    case ARRAY_TYPE_N:             // check for return types!
      hash = find_hashtable(symtab->root, root->curr_level, root->curr_sib);
      assert(hash != NULL);
      for(;hash != NULL && snode == NULL; hash = hash->parent) {
        snode = lookup_symhashtable(hash, root->value_string, NOHASHSLOT);
      }
      assert(snode != NULL);
      root->snode = snode;
      break;

    case INT_LITERAL_N:
      hash = symtab->literal_collection;
      assert(hash != NULL);
      assert(root->value_string != NULL);
      snode = lookup_symhashtable(hash, root->value_string, NOHASHSLOT);
      root->snode = snode;
      break;

    case STRING_LITERAL_N:
      hash = symtab->literal_collection;
      assert(hash != NULL);
      assert(root->value_string != NULL);
      snode = lookup_symhashtable(hash, root->value_string, NOHASHSLOT);
      root->snode = snode;
      break;

    case RETURN_N:

      hash = symtab->literal_collection;
      assert(hash != NULL);
      if(root->left_child->node_type == VOID_TYPE_N){
        snode = lookup_symhashtable(hash, root->left_child->value_string, NOHASHSLOT);
        root->left_child->snode = snode;
      }
      break;


    default:
      break;
  }

/* Recurse on each child of the subtree root */
  ast_node child;
  for (child = root->left_child; child != NULL; child = child->right_sibling)
    link_ast_to_symnode(child, symtab);
}

void correct_arrays(ast_node root){
  /* Correct the return type of this array, if necessary */
  symnode_t *symnode = root->snode;

  if(symnode != NULL){
    if(symnode->type == VAR_ARRAY_INT_T){
      if(root->node_type == ID_N){
        if(root->left_child == NULL){ // no array slot
          root->return_type = ARRAY_TYPE_N;
        }
      }
    }
  }

  /* Recurse on each child of the root */
  ast_node child;
  for (child = root->left_child; child != NULL; child = child->right_sibling){
    correct_arrays(child);
  }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~ Helper functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

/* Returns 1 is the root is a binary operator, depending on its node_type */
int is_binary_operator(ast_node root){

  if(root->node_type == OP_ASSIGN_N ||
     root->node_type == OP_PLUS_N ||
     root->node_type == OP_MINUS_N ||
     root->node_type == OP_TIMES_N ||
     root->node_type == OP_DIVIDE_N ||
     root->node_type == OP_EQUALS_N ||
     root->node_type == OP_MODULUS_N ||
     root->node_type == OP_LESS_THAN_N ||
     root->node_type == OP_LESS_EQUAL_N ||
     root->node_type == OP_GREATER_THAN_N ||
     root->node_type == OP_GREATER_EQUAL_N ||
     root->node_type == OP_NOT_EQUAL_N ||
     root->node_type == OP_AND_N ||
     root->node_type == OP_OR_N
   ){
     return 1;
   } else{
     return 0;
   }
}

/* Returns 1 if the root is a unary operator, depending on its node_type */
int is_unary_operator(ast_node root){
  if(root->node_type == OP_NEG_N ||
     root->node_type == OP_NOT_N ||
     root->node_type == OP_INCREMENT_N ||
     root->node_type == CALL_N ||
     root->node_type == OP_DECREMENT_N){
       return 1;
     } else{
       return 0;
     }
}


/* Special case for assignments. Only need to check that type(lhs) != type(rhs) */
void check_assignment(ast_node root){
  assert(root->left_child != NULL);
  assert(root->left_child->right_sibling != NULL);

  if(root->left_child->return_type != root->left_child->right_sibling->return_type){
    exprTypeError = 1;
      fprintf(stderr, "line: %d | Error: Type disagreement of variable(s) used with assignment operator\n", root->line_num);
  }
}


/* Check binary operations */
void check_binary(ast_node root) {
    assert(root->left_child != NULL);
    assert(root->left_child->right_sibling != NULL);
    // if (root->left_child->return_type != root->left_child->right_sibling->return_type) {
    //   exprTypeError = 1;
    // }
    if(root->left_child->return_type == VOID_TYPE_N || root->left_child->right_sibling->return_type == VOID_TYPE_N) {
      exprTypeError = 1;
      fprintf(stderr, "line: %d | Error: Type disagreement of variable(s) used with binary operator\n", root->line_num);
      fprintf(stderr, "%s\n", NODE_NAME(root->node_type));
    }

    if(root->left_child->node_type == CALL_N) {
      if(root->left_child->left_child->return_type == VOID_TYPE_N){
        exprTypeError = 1;
        fprintf(stderr, "line: %d | Error: Type disagreement of variable(s) used with binary operator\n", root->line_num);
        fprintf(stderr, "%s\n", NODE_NAME(root->node_type));
      }
    }
    if(root->left_child->right_sibling->node_type == CALL_N) {
      if(root->left_child->right_sibling->left_child->return_type == VOID_TYPE_N){
        exprTypeError = 1;
        fprintf(stderr, "line: %d | Error: Type disagreement of variable(s) used with binary operator\n", root->line_num);
        fprintf(stderr, "%s\n", NODE_NAME(root->node_type));
      }
    }
}

/* Check unary operations */
void check_unary(ast_node root) {
  //assert(root->left_child != NULL);
  if(root->node_type == RETURN_N) {
    if(root->left_child != NULL && root->left_child->node_type == CALL_N) {
      if(root->left_child->left_child->return_type == VOID_TYPE_N){
        exprTypeError = 1;
        fprintf(stderr, "line: %d | Error: Returning wrong type\n", root->line_num);
        fprintf(stderr, "%s\n", NODE_NAME(root->node_type));

      }
    }
  }
  else if (root->left_child->return_type == VOID_TYPE_N) {
    fprintf(stderr, "line: %d | Error: Type disagreement of variable used with unary operator\n", root->line_num);
    fprintf(stderr, "%s\n", NODE_NAME(root->node_type));

    exprTypeError = 1;
  }
  else if(root->left_child->node_type == CALL_N) {
    if(root->left_child->left_child->return_type == VOID_TYPE_N){
      fprintf(stderr, "line: %d | Error: Type disagreement of variable used with unary operator\n", root->line_num);
      fprintf(stderr, "%s\n", NODE_NAME(root->node_type));

      exprTypeError = 1;
    }
  }

}

int check_types_in_expr(ast_node root) {
  symhashtable_t *hash = NULL;
  symnode_t *node = NULL;
  ast_node anode = NULL;

  switch (root->node_type) {
    case OP_ASSIGN_N:
    //check_binary(root);
    check_assignment(root);
    break;

    case OP_PLUS_N:
    check_binary(root);
    break;

    case OP_MINUS_N:
    check_binary(root);
    break;

    case OP_NEG_N:
    check_unary(root);
    break;

    case OP_TIMES_N:
        check_binary(root);
    break;

    case OP_DIVIDE_N:
        check_binary(root);
    break;

    case OP_EQUALS_N:
        check_binary(root);
    break;

    case OP_INCREMENT_N:
        check_unary(root);
    break;

    case OP_DECREMENT_N:
        check_unary(root);
    break;

    case OP_MODULUS_N:
        check_binary(root);
    break;

    case OP_LESS_THAN_N:
        check_binary(root);
    break;

    case OP_LESS_EQUAL_N:
        check_binary(root);
    break;

    case OP_GREATER_THAN_N:
        check_binary(root);
    break;

    case OP_GREATER_EQUAL_N:
        check_binary(root);
    break;

    case OP_NOT_EQUAL_N:
        check_binary(root);
    break;

    case OP_AND_N:
        check_binary(root);
    break;

    case OP_OR_N:
        check_binary(root);
    break;

    case OP_NOT_N:
        check_unary(root);
    break;

    case RETURN_N:
        check_unary(root);
    break;

    default:
      // printf("at default of switch\n");
      break;


  }

  /* Recurse on each child of the subtree root, with a depth one
     greater than the root's depth. */
  ast_node child;
  for (child = root->left_child; child != NULL; child = child->right_sibling)
    check_types_in_expr(child);
  return 0;
}


void redef_check(ast_node root, int level, int sibno, symboltable_t *symtab) {
  //calculate the scope for the variable/func declaration
  //calculate the parent for that variable/func declaration
  //need function to take as input
  //printf("here \n");
  symhashtable_t *hash;

  /* Depending on node types, go deeper, create sibling scopes, add to hashtable,
   * or take other appropriate action.
   */
  switch (root->node_type) {
    case SEQ_N:     // change main level when see a new sequence
      level++;
      break;

    case FORMAL_PARAMS_N:
      level++;
      break;

    case FUNC_DECLARATION_N: // function declaraions
      //does hashtable exist with given lvl, siblvl (use find_hashtable)
      if(root->snode != NULL)
        check_if_redef(root, symtab ,level, sibno);
      break;

    case FUNCTION_N:
      check_if_declared(root, symtab ,level, sibno);
      break;

    case ID_N:      /* print the id */
      if(root->snode != NULL)
        check_if_redef(root, symtab ,level, sibno);
      break;

    case ARRAY_TYPE_N:             // check for return types!
      if(root->snode != NULL)
        check_if_redef(root, symtab ,level, sibno);
      break;

    case RETURN_N:
      break;

    default:
      // printf("at default of switch\n");
      assert(symtab->root != NULL);
      break;
  }

  if(arraylen_trash == level) {
    arraylen_trash = arraylen_trash + DELTA;
    trash_array = realloc(trash_array, sizeof(int) * arraylen_trash);

    assert(trash_array != NULL);

    for(int k=0; k < DELTA; k++) {
      trash_array[arraylen_trash - (DELTA-k)] = 0;
    }
  }

  /* Recurse on each child of the subtree root, with a depth one
     greater than the root's depth. */
  ast_node child;
  for (child = root->left_child; child != NULL; child = child->right_sibling)
    redef_check(child, level, trash_array[level], symtab);

  if(root->node_type == SEQ_N){//} || root->node_type == FORMAL_PARAMS_N){
    trash_array[level]++;  // change sibling level after you're done printing all
                      // subtrees, i.e., after done recursing.
  }
}

void patch_symbol_table(ast_node root, symhashtable_t *symtable){

  symhashtable_t *hashtable;
  symnode_t *snode = NULL;

  switch(root->node_type){

    case ID_N:

      hashtable = find_hashtable(symtable, root->curr_level, root->curr_sib);
      if(hashtable != NULL){
        //snode = lookup_symhashtable(hashtable, root->value_string, NOHASHSLOT);
        assert(hashtable != NULL);
        assert(snode == NULL);
        for(;hashtable != NULL && snode == NULL; hashtable = hashtable->parent) {
          snode = lookup_symhashtable(hashtable, root->value_string, NOHASHSLOT);
        }
        if(snode != NULL){
          if(snode->type == VAR_ARRAY_INT_T && root->left_child == NULL){
            root->return_type = ARRAY_TYPE_N;
//           root->node_type = ARRAY_TYPE_N; // change in the future
          }
        }
      break;

    case ARRAY_TYPE_N:
      hashtable = find_hashtable(symtable, root->curr_level, root->curr_sib);
      if(hashtable != NULL){
        snode = lookup_symhashtable(hashtable, root->value_string, NOHASHSLOT);
        if(snode != NULL){
          if(snode->type == VAR_INT_T){
            snode->type = VAR_ARRAY_INT_T;
          }
        }
      }
      break;

    default:
      break;
    }
  }


  ast_node child;

  for(child = root->left_child; child != NULL; child = child->right_sibling){
    patch_symbol_table(child, symtable);
  }
}

void assign_param_offsets(ast_node root){

  if(root->node_type == FORMAL_PARAMS_N){
    int param_count = 0;
    ast_node param;

    for(param = root->left_child; param != NULL; param = param->right_sibling){
      if(param->node_type == ARRAY_TYPE_N || param->return_type == ARRAY_TYPE_N){
        param_count += DEFAULT_ARRAY_PARAM_SIZE;
      }
      else{
        param_count++;
      }
    }

    for(param = root->left_child; param != NULL; param = param->right_sibling){
      if(param->node_type == ARRAY_TYPE_N || param->return_type == ARRAY_TYPE_N){
        param->snode->offset = param_count * 4;
        param_count -= DEFAULT_ARRAY_PARAM_SIZE;
      }
      else{
        param->snode->offset = param_count-- * 4;
      }
    }
  }

  ast_node child;
  for(child = root->left_child; child != NULL; child = child->right_sibling){
    assign_param_offsets(child);
  }
}
