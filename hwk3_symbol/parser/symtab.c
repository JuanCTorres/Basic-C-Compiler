/* symtab.c
 * Functions for the symbol table.
 * Written by THC for CS 57.
 *
 * extended and changed by sws
 *
 * You should extend the functions as appropriate.
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "assert.h"
#include "ast.h"
#include "symtab.h"





#define NOHASHSLOT -1

int siblings[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
/*
 * Functions for symnodes.
 */



/*
 * Functions for symhashtables.
 */




/*
 * Functions for symboltables.
 */

static const int HASHSIZE = 211;

/* Create an empty symbol table. */
symboltable_t  *create_symboltable() {
  symboltable_t *symtab = malloc(sizeof(symboltable_t));
  assert(symtab);

  symhashtable_t *hashtable=create_symhashtable(HASHSIZE);
  hashtable->level = 0;
  hashtable->name = "0";

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
  symhashtable_t *hashtable = malloc(sizeof(symhashtable_t));
  assert(hashtable);
  hashtable->size = entries;
  hashtable->table = calloc(entries, sizeof(symnode_t));

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

symnode_t *create_symnode(char *name, symhashtable_t *hashtable) {
  symnode_t *node = calloc(1, sizeof(symnode_t));
  assert(node != NULL);

  node->name = strdup(name);
  node->parent = hashtable;

  return node;
}

/* Insert a new entry into a symhashtable, but only if it is not
   already present. */
symnode_t *insert_into_symhashtable(symhashtable_t *hashtable, char *name) {

  assert(hashtable);

  int slot = hashPJW(name, hashtable->size);
  symnode_t *node = lookup_symhashtable(hashtable, name, slot);

  /* error check if node already existed! */

  if (node == NULL) {
    node = create_symnode(name,hashtable);
    node->next = hashtable->table[slot];
    hashtable->table[slot] = node;
  }

  return node;
}

/* Insert an entry into the innermost scope of symbol table.  First
   make sure it's not already in that scope.  Return a pointer to the
   entry. */
symnode_t *insert_into_symboltable(symboltable_t *symtab, char *name) {

  assert(symtab);
  assert(symtab->leaf);
  
  symnode_t *node = lookup_symhashtable(symtab->leaf, name, NOHASHSLOT);

  /* error check!! */
  
  if (node == NULL) {
    node = insert_into_symhashtable(symtab->leaf, name);
    return node;
  } else {
    return NULL;
  }
   
}






/* Lookup an hashtable with given lvl and sibno in a symbol table.  
  If found return a pointer to it.
  Otherwise, return NULL */
symhashtable_t *find_hashtable(symhashtable_t  *root, int lvl, int sib) {


  // assert(symtab);
  // assert(symtab->leaf != NULL);

  // for(hashtable = symtab->leaf; hashtable != NULL; hashtable = hashtable->parent) {
  //   for(hashtable2 = hashtable; hashtable2 != NULL; hashtable2 = hashtable2->rightsib) {
  //     if(hashtable2->level == lvl && hashtable2->sibno == sib) {
  //       assert(hashtable2 != NULL);
  //       return hashtable2;
  //     }

  //   }

  // }

  // return NULL;


    if (lvl == root->level && sib == root->sibno) {
      return(root);
    } 
 
    symhashtable_t *res, *child;
    res = NULL;
    for(child = root->child; child != NULL  && res == NULL; child = child->rightsib) {
      res = find_hashtable(child, lvl, sib);
    }

    return res;
    
}






symhashtable_t *make_insert_hashtable(symhashtable_t  *root, int lvl, int sibno, int parent_lvl, int parent_sibno) {
  symhashtable_t *hashtable, *parent_hashtable, *temp;


  hashtable = create_symhashtable(HASHSIZE);
  assert(hashtable != NULL);

  parent_hashtable = find_hashtable(root, parent_lvl, parent_sibno);  //parent must have been created
  assert(parent_hashtable != NULL);

  hashtable->parent = parent_hashtable;
  hashtable->level = lvl;
  hashtable->sibno = sibno;

  //insert as rightmost child of parent
  if(parent_hashtable->child != NULL) {
    for(temp = parent_hashtable->child ; temp->rightsib != NULL; temp = temp->rightsib) {
      temp->rightsib = hashtable;
    }
  }
  else {
    parent_hashtable->child = hashtable;
  }

  return hashtable;
}












void build_symbol_table(ast_node root, int level, int sibno, symboltable_t *symtab) {
  //calculate the scope for the variable/func declaration
  //calculate the parent for that variable/func declaration
  //need function to take as input 

  symhashtable_t *hash;



  /* Print attributes specific to node types. */
  switch (root->node_type) {
    case SEQ_N:     // change main level when see a new sequence
      level++;
      break;

    case FORMAL_PARAMS_N:
      level++;
      break;

    case FUNC_DECLARATION_N:
      //does hashtable exist with given lvl, siblvl (use find_hashtable)
      hash = find_hashtable(symtab->root, level, sibno);
      if(hash != NULL) {
        insert_into_symhashtable(hash, root->value_string);

      }
        //if yes
          // return point to that hashtable
        //if no
          // return null
      //if it does not exist, make that hashtable and attach to appropriate parent
      //insert the node appropriatly
      break;
    case CALL_N:
      //need to check if it has been previously declared.
    case ID_N:      /* print the id */
      if(root->return_type != 0) {  //declaration

      }
      else {  //don't know if previously declared

      }
      break;
    
    default:
      //printf("at default of switch\n");
      break;
  }

  printf("(%d, %d) ", level, sibno);
  printf("(Child of %d, %d)", MAX(level - 1, 0), siblings[level - 1]);
  printf("\n");

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














