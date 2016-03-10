/*
* ast.h
*
* File defining an enum and a struct for node types in an abstract
* syntax tree.
*
* Written by THC for CS 57; massaged by SWS; modified by Seok Jun Bing and Juan Torres.
*
*
*/
// #include "symtab.h"



#ifndef AST_H_
#define AST_H_
// struct symboltable_t;
// struct symnode_t;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// struct symboltable_t;

/* You should fill in the various AST node types.  The following are given
to you to start with.  You may add or remove node types as you
wish. */

/* Added a bunch of tokens */
typedef enum {
  ROOT_N,
  SEQ_N,
  OP_ASSIGN_N, OP_PLUS_N, OP_MINUS_N, OP_NEG_N, OP_TIMES_N, OP_DIVIDE_N,
  OP_EQUALS_N,
  IF_STMT_N, IF_ELSE_STMT_N,
  ID_N, INT_LITERAL_N,
  OP_MODULUS_N,
  OP_LESS_THAN_N,
  OP_LESS_EQUAL_N,
  OP_GREATER_THAN_N,
  OP_GREATER_EQUAL_N,
  OP_NOT_EQUAL_N,
  OP_AND_N,
  OP_OR_N,
  OP_NOT_N,
  OP_INCREMENT_N,
  OP_DECREMENT_N,
  WHILE_N,
  DO_WHILE_N,
  PRINT_N,
  STRING_LITERAL_N,
  INT_TYPE_N,
  VOID_TYPE_N,
  ARRAY_TYPE_N,
  FUNCTION_N,
  FORMAL_PARAMS_N,
  RETURN_N,
  READ_N,
  FOR_N,
  FOR_HEADER_EMPTY_N,
  STATEMENT_LIST_N,
  LOCAL_DECLARATIONS_N,
  CALL_N,
  FUNC_DECLARATION_N,
  LABEL_N,
  TEMP_N
} ast_node_type;


typedef struct {
  int val;
  char *name;
} val_name_pair;


/* Define a table of nd associated strings.  You
should modify this table as appropriate.  The order of entries
should match the order of enumerated values in ast_node_type. */
static val_name_pair token_table[] = {
  { ROOT_N, "ROOT" },
  { SEQ_N, "SEQ" },
  { OP_ASSIGN_N, "=" },
  { OP_PLUS_N, "+" },
  { OP_MINUS_N, "-" },
  { OP_NEG_N, "UNARY -" },
  { OP_TIMES_N, "*" },
  { OP_DIVIDE_N, "/" },
  { OP_EQUALS_N, "==" },
  { IF_STMT_N, "IF_STMT" },
  { IF_ELSE_STMT_N, "IF_ELSE_STMT" },
  { ID_N, "ID" },
  { INT_LITERAL_N, "INT_LITERAL"},
  { OP_MODULUS_N, "%"},
  { OP_LESS_THAN_N, "<"},
  { OP_LESS_EQUAL_N, "<="},
  { OP_GREATER_THAN_N, ">"},
  { OP_GREATER_EQUAL_N, ">="},
  { OP_NOT_EQUAL_N, "!="},
  { OP_AND_N, "&&"},
  { OP_OR_N, "||"},
  { OP_NOT_N, "!"},
  { OP_INCREMENT_N, "++"},
  { OP_DECREMENT_N, "--"},
  { WHILE_N, "WHILE"},
  { DO_WHILE_N, "DO_WHILE"},
  { PRINT_N, "PRINT"},
  { STRING_LITERAL_N, "STRING_LITERAL"},
  { INT_TYPE_N, "INT_TYPE" },
  { VOID_TYPE_N, "VOID_TYPE" },
  { ARRAY_TYPE_N, "ARRAY_TYPE"},
  { FUNCTION_N, "FUNCTION" },
  { FORMAL_PARAMS_N, "FORMAL_PARAMS" },
  { RETURN_N, "RETURN"},
  { READ_N, "READ"},
  { FOR_N, "FOR"},
  { FOR_HEADER_EMPTY_N, "FOR_HEADER_EMPTY"},
  { STATEMENT_LIST_N, "STATEMENT_LIST"},
  { LOCAL_DECLARATIONS_N, "LOCAL_DECLARATIONS"},
  { CALL_N, "CALL"},
  { FUNC_DECLARATION_N, "FUNC_DECLARATION"},
  { LABEL_N, "LABEL"},
  { TEMP_N, "TEMP"},
  { 0, NULL}
};

#define NODE_INDEX(X)    ( (X) - ROOT_N)
#define NODE_NAME(X)     ( token_table[ NODE_INDEX((X)) ].name)


/* Structure for nodes of the abstract syntax tree.  Uses the
left-child/right-sibling representation, so that each node can have
a variable number of children.  You should add or remove fields as
appropriate. */
typedef struct ast_node_struct *ast_node;
struct ast_node_struct {
  ast_node_type node_type;
  ast_node left_child, right_sibling;

  // as most one of these would be nonzero
  char *value_string;		/* for ID */
  int value_int;		/* for INT_LITERAL */
  ast_node_type return_type; /* for declarations */
  int array_length;
  struct symnode *snode; //using void to avoid circular heaer issues
  int line_num; //when the token occurred in the input test file
  int curr_level;
  int curr_sib;
  int parent_level;
  int parent_sib;
  int line_declared; //line num of original declaration
  int node_no;
  ast_node return_to;
  struct symnode *temp_node;
  int isDecl;
  int ignore_sym;


};


/* Create a node with a given token type and return a pointer to the
node. */
ast_node create_ast_node(ast_node_type node_type);


/*
* Assigns a variable type to the node representing an array or function declaration.
*/
void assign_var_type(ast_node root);


/* Print the contents of a subtree of an abstract syntax tree, given
the root of the subtree and the depth of the subtree root. */
void print_ast(ast_node root, int depth, int lvl, int sublvl);

void insert_scope_info(ast_node root, int curr_level, int curr_sib, int parent_level, int parent_sib);

/* Assigns a unique identifier to every node in the ast */
void label_nodes(ast_node root);


void patch_return_types(ast_node root);

#endif
