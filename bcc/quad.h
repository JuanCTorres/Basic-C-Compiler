#ifndef QUAD_H_
#define QUAD_H_

#include "ast.h"
#include "symtab.h"

symnode_t* NewLabel(ast_node anode, char *text, symhashtable_t *hashtable);

 typedef struct {
  int val;
  char *name;
} val_name_pair3;


 typedef enum{
  Q_ASSIGN,
  Q_ADD,
  Q_SUB,
  Q_MULT,
  Q_DIV,
  Q_INC,
  Q_DEC,
  Q_IFF,
  Q_IFT,
  Q_GOTO,
  Q_LABEL,
  Q_READ,
  Q_PRINT,
  Q_HALT,
  Q_EQ,
  Q_GT,
  Q_LT,
  Q_GTEQ,
  Q_LTEQ,
  Q_NEG,
  Q_NEQ,
  Q_MOD,
  Q_CALL,
  Q_PUSH,
  Q_RETURN,
  Q_ADDR,
  Q_DEREF,
  Q_PRECALL,
  Q_POSTCALL
 } quad_op_type;

 static val_name_pair3 token_table3[] = {
    {Q_ASSIGN, "ASSIGN"},
    {Q_ADD, "ADD"},
    {Q_SUB, "SUB"},
    {Q_MULT, "MULT"},
    {Q_DIV, "DIV"},
    {Q_INC, "INC"},
    {Q_DEC, "DEC"},
    {Q_IFF, "ifFalse"},
    {Q_IFT, "ifTrue"},
    {Q_GOTO, "GOTO"},
    {Q_LABEL, "LABEL"},
    {Q_READ, "READ"},
    {Q_PRINT, "PRINT"},
    {Q_HALT, "HALT"},
    {Q_EQ, "EQ"},
    {Q_GT, "GT"},
    {Q_LT, "LT"},
    {Q_GTEQ, "GTEQ"},
    {Q_LTEQ, "LTEQ"},
    {Q_NEG, "NEG"},
    {Q_NEQ, "NEQ"},
    {Q_MOD, "MOD"},
    {Q_CALL, "CALL"},
    {Q_PUSH, "PUSH"},
    {Q_RETURN, "RETURN"},
    {Q_ADDR, "ADDR"},
    {Q_DEREF, "DEREF"},
    {Q_PRECALL, "PRECALL"},
    {Q_POSTCALL, "POSTCALL"},
    {0, NULL}
 };

 #define OP_INDEX(X)    ( (X) - Q_ASSIGN)
#define OP_NAME(X)     ( token_table3[ OP_INDEX((X)) ].name)

 typedef struct temp {
     int id;
     int other;
 } temp_type;


 typedef struct quad {
     quad_op_type op;
     symnode_t *dest;
     symnode_t *src1;
     symnode_t *src2;
 } quad_type;

void print_quad_array(quad_type **array);

symnode_t* NewTemp(symhashtable_t *hashtable);

void CG(ast_node x, symhashtable_t *hashtable);

void preorder_print(ast_node root);

void make_insert_quad(quad_op_type op, symnode_t *dest, symnode_t *src1, symnode_t *src2);

void add_temps_to_ast(ast_node root, symhashtable_t *hashtable);

/*~~~~~ Helper functions ~~~~~*/

void set_constants(symhashtable_t *hashtable);

symnode_t *get_symnode(ast_node anode, symhashtable_t *hashtable);

void insert_binary_op_quad(ast_node anode, quad_op_type quad_op, symhashtable_t *hashtable);

void insert_unary_op_quad(ast_node anode, quad_op_type quad_op, symnode_t *temp, symhashtable_t *hashtable);

/*
   Returns a temporary node holding the _address_ of the array at the index specified
   as the left child of anode in the abstract syntax tree.
*/
symnode_t *get_array_slot_addr(ast_node anode, symhashtable_t *hashtable);


/*
   Returns a temporary node holding the _value_ of the array at the index specified
   as the left child of anode in the abstract syntax tree.
*/
symnode_t *get_array_slot_val(ast_node anode, symhashtable_t *hashtable);

/*
Returns 1 if var is global, i.e., was declared in scope (0-0)
*/
int is_var_global(symnode_t *var);

/* */
void set_global_int_const();

void insert_index_astnode(ast_node root, int i);

/* pushes a parameter */
//void push_param(ast_node root, symhashtable_t *hashtable);
int push_param(ast_node root, symhashtable_t *hashtable, symnode_t *temp, int param_offset);

#endif
