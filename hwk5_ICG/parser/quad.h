 #include "ast.h"



#ifndef QUAD_H_
#define QUAD_H_

 char* NewLabel(int node_num, char *text);
 
 
 typedef enum{
  Q_ASSIGN,
  Q_ADD,
  Q_SUB,
  Q_MULT,
  Q_DIV,
  Q_INC,
  Q_DEC,
  Q_IFF,
  Q_GOTO,
  Q_LABEL,
  Q_READ,
  Q_PRINT,
  Q_HALT,
  Q_EQ,
  Q_GT,
  Q_LT,
  Q_GTEQ,
  Q_LTEQ
 } quad_op_type;
 
 typedef struct temp {
     int id;
     int other;
 } temp_type;
 
 typedef struct quad {
     quad_op_type op;
     temp_type dest;
     temp_type src1;
     temp_type src2;
 } quad_type;


void CG(ast_node root);


#endif
