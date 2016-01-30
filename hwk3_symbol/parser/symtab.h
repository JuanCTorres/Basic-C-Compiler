/* symtab.h
 * Declarations for the symbol table.
 * Written by THC for CS 57.
 * You should extend the structs and functions as appropriate.
 *
 * extended and changed muchly by sean
 */

#ifndef SYMTAB_H_
#define SYMTAB_H_

#include "ast.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

typedef struct scope {
  int level;
  int sib;

} scope_t;


/* Added a bunch of tokens */
typedef enum { 
  VAR_INT_T,
  FUNC_INT_T,
  FUNC_VOID_T
} decl_type;



/* Define a table of nd associated strings.  You
   should modify this table as appropriate.  The order of entries
   should match the order of enumerated values in var_type. */


static val_name_pair decl_table[] = {
  { VAR_INT_T, "VAR_INT" },
  { FUNC_INT_T, "FUNC_INT" },
  { FUNC_VOID_T, "FUNC_VOID"},
  { 0, NULL}
 };

#define TYPE_INDEX(X)    ( (X) - VAR_INT_T)
#define TYPE_NAME(X)     ( decl_table[ TYPE_INDEX((X)) ].name)





typedef struct symnode {
  char *name;	                    /* name in this symnode */
  decl_type type;
  struct symnode  *next;	    /* next symnode in list */
  struct symhashtable *parent;
  decl_type *parameters;
  int num_parameters;
  /* Other attributes go here. */
} symnode_t;

/* Set the name in this node. */
void set_node_name(symnode_t *node, char *name);

/* Does the identifier in this node equal name? */
int name_is_equal(symnode_t *node, char *name);


/* Hash table for a given scope in a symbol table. */

typedef struct symhashtable {
  char *name;
 // symtab_type type;
  int size;			/* size of hash table */
  symnode_t **table;		/* hash table, array of pointers! */ 
  int level;			/* level of scope, 0 is outermost */
  int sibno;                    /* 0 is leftmost */
  struct symhashtable *parent, *child, *rightsib;
  
} symhashtable_t;



/* Symbol table for all levels of scope. */
typedef struct {
  symhashtable_t *root, *leaf;
    
} symboltable_t;






/* Create an empty symbol table. */
symboltable_t *create_symboltable();

symnode_t *insert_into_symhashtable(symhashtable_t *hashtable, ast_node astnode);
/* Insert an entry into the innermost scope of symbol table.  First
   make sure it's not already in that scope.  Return a pointer to the
   entry. */
symnode_t *insert_into_symboltable(symboltable_t *symtab, ast_node astnode);

/* Lookup an entry in a symbol table.  If found return a pointer to it.
   Otherwise, return NULL */
symnode_t *lookup_in_symboltable(symboltable_t *symtab, char *name);

// /* Enter a new scope. */
// void enter_scope(symboltable_t *symtab, int type, ast_node node);

// /* Leave a scope. */
// void leave_scope(symboltable_t *symtab);

/* print the table in a nice way */
void print_symtab(symboltable_t *symtab);

symhashtable_t *create_symhashtable(int entries);

void build_symbol_table(ast_node root, int level, int sibno, symboltable_t *symtab);

void pretty_print(symhashtable_t *hash, int a);





#endif
