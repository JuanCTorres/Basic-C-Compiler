/*
 * ast.h
 *
 * File defining an enum and a struct for node types in an abstract
 * syntax tree.
 *
 * Written by THC for CS 57; massaged by SWS; modified by Seok Jun Bing and Juan Torres.
 *
 * You should modify this file as appropriate.
 *
 */

#ifndef AST_H_
#define AST_H_

/* You should fill in the various AST node types.  The following are given
   to you to start with.  You may add or remove node types as you
   wish. */

/* Added a bunch of tokens */
typedef enum { ROOT_N,
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
         CALL_N
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
  { OP_NEG_N, "-" },
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
  { 0, NULL }
};

#define NODE_INDEX(X)    ( (X) - ROOT_N)
#define NODE_NAME(X)     ( token_table[ NODE_INDEX((X)) ].name)

#define MAX(x, y) (((x) > (y)) ? (x) : (y)) // For fixing one error in hash table creation



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

};

//int get_max_unused_index(int** table);

/* Create a node with a given token type and return a pointer to the
   node. */
ast_node create_ast_node(ast_node_type node_type);

/* Print the contents of a subtree of an abstract syntax tree, given
   the root of the subtree and the depth of the subtree root. */
void print_ast(ast_node root, int depth, int lvl, int sublvl);

#endif
