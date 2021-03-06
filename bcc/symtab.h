/* symtab.h
* Declarations for the symbol table.
* Written by THC for CS 57.
* You should extend the structs and functions as appropriate.
*
* extended and changed muchly by sean
* Added to by SeokJun Bing, Juan C. Torres
*/


#ifndef SYMTAB_H_
#define SYMTAB_H_

#include "ast.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define NOHASHSLOT -1
#define ELEMSIZE 4  // For now, only ints in our arrays

typedef struct scope {
  int level;
  int sib;

} scope_t;


/* Added a bunch of tokens */
typedef enum {
  VAR_INT_T,
  VAR_ARRAY_INT_T,
  FUNC_INT_T,
  FUNC_VOID_T,
  STRING_T,
  VOID_RET_T,
  INT_RET_T
} decl_type;

typedef struct {
  int val;
  char *name;
} val_name_pair_2;

/* Define a table of nd associated strings.  You
should modify this table as appropriate.  The order of entries
should match the order of enumerated values in var_type. */
static val_name_pair_2 decl_table[] = {
  { VAR_INT_T, "VAR_INT" },
  { VAR_ARRAY_INT_T, "VAR_ARRAY_INT"},
  { FUNC_INT_T, "FUNC_INT" },
  { FUNC_VOID_T, "FUNC_VOID"},
  { STRING_T, "STRING"},
  { VOID_RET_T, "VOID_RETURN"},
  { INT_RET_T, "INT_RETURN"},
  { 0, NULL}
};

#define TYPE_INDEX(X)    ( (X) - VAR_INT_T)
#define TYPE_NAME(X)     ( decl_table[ TYPE_INDEX((X)) ].name)


typedef struct symnode {
  char *name;	                /* name in this symnode */
  char *name_clean;
  int num_val;
  decl_type type;
  struct symnode  *next;	    /* next symnode in list */
  struct symhashtable *parent;
  decl_type *parameters;
  int num_parameters;
  struct ast_node_struct* abnode;
  int array_length;
  int offset;
  int num_variables;
  int addr;
  int needed_space;
  int is_array;
  /* Other attributes go here. */
} symnode_t;


/* Set the name in this node. */
void set_node_name(symnode_t *node, char *name);

/* Does the identifier in this node equal name? */
int name_is_equal(symnode_t *node, char *name);

/* Hash table for a given scope in a symbol table. */
typedef struct symhashtable {
  char *name;
  int size;			/* size of hash table */
  symnode_t **table;		/* hash table, array of pointers! */
  int level;			/* level of scope, 0 is outermost */
  int sibno;                    /* 0 is leftmost */
  struct symhashtable *parent, *child, *rightsib;

} symhashtable_t;


/* Symbol table for all levels of scope. */
typedef struct {
  symhashtable_t *root, *leaf, *literal_collection;

} symboltable_t;

/* Create an empty symbol table. */
symboltable_t *create_symboltable();

symnode_t *create_symnode(char *name, symhashtable_t *hashtable);

symnode_t *insert_into_symhashtable(symhashtable_t *hashtable, struct ast_node_struct* astnode);


/* Insert an entry into the innermost scope of symbol table.  First
make sure it's not already in that scope.  Return a pointer to the
entry. */
symnode_t *insert_into_symboltable(symboltable_t *symtab, struct ast_node_struct* astnode);


/* Lookup an entry in a symbol table.  If found return a pointer to it.
Otherwise, return NULL */
symnode_t *lookup_in_symboltable(symboltable_t *symtab, char *name);


// /* Enter a new scope. */
// void enter_scope(symboltable_t *symtab, int type, ast_node node);

// /* Leave a scope. */
// void leave_scope(symboltable_t *symtab);


/* print the table in a nice way */
void print_symtab(symboltable_t *symtab);


/* Creates a new hash table to insert into the symbol table. */
symhashtable_t *create_symhashtable(int entries);

symnode_t *lookup_symhashtable(symhashtable_t *hashtable, char *name, int slot);
/* Traverses the syntax tree, keeping track of the current scope
and its relations with other scopes. Adds new hashtables when it sees a new
scope, and inserts variable and function identifiers in the appropriate
hashtable for their scope, depending on their node type, which is contained
in the abstract syntax tree with pointer root*/
void build_symbol_table(struct ast_node_struct* root, int level, int sibno, symboltable_t *symtab);


/* Prints a representation of the symbol table, including representations of
hierarchical relations between different scopes, names of scopes, and variables
defined within each scope.
*/
void pretty_print(symhashtable_t *hash, int depth);

void record_var_type_in_ast(ast_node root, symboltable_t *symtab);

int check_function(ast_node root, symboltable_t *symtab);

/* Infers the type of operations with return types. For unary operators, such as
! and unary minus, the operator is assigned the return type of its child.
For binary operators, the operator is assigned the return type of its
children, only if both children have the same return type.
 */
void infer_type(ast_node root);


/* Returns 1 if the root is a unary operator, depending on its node_type */
int is_unary_operator(ast_node root);


/* Returns 1 is the root is a binary operator, depending on its node_type */
int is_binary_operator(ast_node root);

/* calls check_return_helper */
void check_return(ast_node root, symboltable_t *symtab);

/*Checks that there is appropriate return for functions
* Inserts an implicit return for void type functions
* For every return statement, records to which function it returns to
*/
void check_return_helper(ast_node root, symboltable_t *symtab, ast_node funcnode);


void insert_implicit_return(ast_node root, symboltable_t *symtab);

/* Returns appropriate sibling number */
int getSibling(int level);

/* Assumes a previous traversal confirmed variables are correctly declared */
void collect_literals(ast_node root, symboltable_t *symtab);

void link_ast_to_symnode(ast_node root, symboltable_t *symtab);

void correct_arrays(ast_node root);

symnode_t *create_const_symnode(char* name, int val);

ast_node create_int_astnode(int val);

/* ~~~~~~~~~~ Functions for checking type disagreements ~~~~~~~~~*/
int check_types_in_expr(ast_node root);

void check_binary(ast_node root);

void check_assignment(ast_node root);

void check_unary(ast_node root);

void redef_check(ast_node root, int level, int sibno, symboltable_t *symtab);

void patch_symbol_table(ast_node root, symhashtable_t *symtable);

void assign_param_offsets(ast_node root);

#endif
