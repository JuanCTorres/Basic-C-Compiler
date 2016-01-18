%{
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ast.h"

#define YYSTYPE ast_node
#define YYDEBUG 1

extern int yylex();
int yyerror(char *s);
extern char *yytext;

extern int num_lines;
extern ast_node root;
extern int parseError;

extern char savedIdText[];
extern char savedLiteralText[];

%}

%token ISEQUAL_T NOTEQUAL_T SHL_T ARROW_T LESS_EQUAL_T GREATER_EQUAL_T INCREMENT_T DECREMENT_T AND_T OR_T
%token INCLUDE_T EXTERN_T INT_T CHAR_T WHILE_T FOR_T IF_T ELSE_T RETURN_T VOID_T READ_T PRINT_T ID_T UMINUS_T
%token DO_T, STRINGCONST_T

/* from flex&bison book: how to resolve if/then/else */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE_T


%left OR_T /* || */
%left AND
%left NOTEQUAL_T ISEQUAL_T
%left '<' LESS_EQUAL_T '>' GREATER_EQUAL_T
%left '+' '-'
%left '*' '/' '%'
%right '!' INCREMENT_T DECREMENT_T %left UMINUS_T /* uminus... left or right assoc?? */




%%

code : stmtList {
  ast_node t = create_ast_node(ROOT_N);
  t->left_child = $1;
  root = $$ = t; }
;

stmtList : /* empty */ { $$ = NULL; }
| stmtList stmt {
  ast_node t = $1;
  if (t != NULL) {
    while (t->right_sibling != NULL)
      t = t->right_sibling;
    t->right_sibling = $2;
    $$ = $1;
  }
  else
    $$ = $2;
 }
;

stmt : exprStmt { $$ = $1; }
| compoundStmt  { $$ = $1; }
| ifStmt        { $$ = $1; }
;

exprStmt : expr ';' { $$ = $1; }
| ';'               { $$ = NULL; }
| error ';'         { $$ = NULL; }
;

compoundStmt : '{' stmtList '}' {
  ast_node t = create_ast_node(SEQ_N);
  t->left_child = $2;
  $$ = t; }
;

ifStmt : IF_T '(' expr ')' stmt   %prec LOWER_THAN_ELSE {
  ast_node t = create_ast_node(IF_STMT_N);
  t->left_child = $3;
  t->left_child->right_sibling = $5;
  $$ = t; }
| IF_T '(' expr ')' stmt ELSE_T stmt {
  ast_node t = create_ast_node(IF_ELSE_STMT_N);
  t->left_child = $3;
  t->left_child->right_sibling = $5;
  t->left_child->right_sibling->right_sibling = $7;
  $$ = t; }
| IF_T '(' error ')' stmt %prec LOWER_THAN_ELSE
{ $$ = NULL; }
| IF_T '(' error ')' stmt ELSE_T stmt { $$ = NULL; }
;


expr :
IDENT_T {
  ast_node t1 = create_ast_node(ID_N);
  t1->value_string = strdup(savedIdText);
  $1 = t1;
 } '=' expr {
  ast_node t2 = create_ast_node(OP_ASSIGN_N);
  t2->left_child = $1;
  t2->left_child->right_sibling = $4;
  $$ = t2; }
| expr '+' expr {
  ast_node t = create_ast_node(OP_PLUS_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
| expr '-' expr {
  ast_node t = create_ast_node(OP_MINUS_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
| expr '*' expr {
  ast_node t = create_ast_node(OP_TIMES_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
| '-' expr %prec UMINUS_T {
  ast_node t = create_ast_node(OP_NEG_N);
  t->left_child = $2;
  $$ = t; }
| '(' expr ')' { $$ = $2; }
| NUM_T {
  ast_node t = create_ast_node(INT_LITERAL_N);
  t->value_int = atoi(savedLiteralText);
  $$ = t; }
| IDENT_T {
  ast_node t = create_ast_node(ID_N);
  t->value_string = strdup(savedIdText);
  $$ = t; }
| '(' error ')' { $$ = NULL; }
;





%%

int yyerror(char *s) {
  parseError = 1;
  fprintf(stderr, "%s at line %d\n", s, num_lines);
  return 0;
}
