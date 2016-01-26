/*
 * 
 * parser.y
 *
 * This bison file contains the grammar for the subset of c
 * as well as the algorithm to build a abstract syntax tree from
 * the tokens passed from parse.l flex file. 
 * 
 * Written by Seok Jun Bing, Juan Torres.
 *
 * Please note that, in our AST, all the conditional statements are placed as a left child to a node
 *
 * Last modified date: 01/21/16
 *
*/


%{
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "ast.h"

#define YYSTYPE ast_node
#define YYDEBUG 1
//#define DEBUG //uncomment to see additional debugging printf

extern int yylex();
int yyerror(char *s);
extern char *yytext;
extern int YYRECOVERING();

extern int num_lines;
extern ast_node root;
extern int parseError;

extern char savedIdText[];
extern char savedLiteralText[];

//int yyerrstatus;

%}

%token ISEQUAL_T NOTEQUAL_T LESS_EQUAL_T GREATER_EQUAL_T INCREMENT_T DECREMENT_T AND_T OR_T
%token INT_T WHILE_T FOR_T IF_T ELSE_T RETURN_T VOID_T READ_T PRINT_T ID_T UMINUS_T
%token DO_T STRINGCONST_T INTCONST_T EOF_T OTHER_T

/* from flex&bison book: how to resolve if/then/else */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE_T

 /* top has the lowest precedence. bottom has the highest precedence. */
%right '='
%left OR_T /* || */
%left AND_T
%left NOTEQUAL_T ISEQUAL_T
%left '<' LESS_EQUAL_T '>' GREATER_EQUAL_T
%left '+' '-'
%left '*' '/' '%'
%right '!' INCREMENT_T DECREMENT_T %left UMINUS_T /* uminus... left or right assoc?? */




%%



 /* all these grammar was taken from the course home page.  */
 /* additional modifications to the grammar has been made to flat out ambiguities */

/* root is a global variable */

program : declarationList {
  ast_node t = create_ast_node(ROOT_N);
  t->left_child = $1;
  root = $$ = t; 
}
;

declarationList : declarationList declaration {
  ast_node t = $1;
  assert(t != NULL);
    while (t->right_sibling != NULL) { 
      t = t->right_sibling; 
    }
    t->right_sibling = $2;
    $$ = $1;
 }
|  declaration { 
   $$ = $1;
 }
|  declarationList error {$$ = NULL;}
|  error declaration {$$ = NULL;}
;

declaration : varDeclaration  {
  $$ = $1;
  }
|  funcDeclaration {
  $$ = $1;
  }
;

varDeclaration : INT_T varDeclList ';' {
  /* replaced varTypeSpecifier to INT_T*/
  $2->return_type = INT_TYPE_N;
  ast_node temp_t = $2;
  assert($2 != NULL);
  while($2->right_sibling != NULL) {
      $2->return_type = INT_TYPE_N;
      $2 = $2->right_sibling;
    }
  $2->return_type = INT_TYPE_N;
  $$ = temp_t;
}
;


varDeclList: varDeclList ',' varDecl  {
  ast_node t = $1;
  assert(t != NULL);
    while (t->right_sibling != NULL) { 
      t = t->right_sibling; 
    }
    t->right_sibling = $3;
    $$ = $1;
 }
|  varDecl {$$ = $1;}
|  varDeclList ',' error {$$ = NULL;}
|  error '.' varDecl {$$ = NULL;}
;

varDecl : ID_T  {
    ast_node t = create_ast_node(ID_N);
    t->value_string = strdup(savedIdText);
    $$ = t;
  }
|  ID_T { /* embedded action needed to prevent savedidtext from being overwritten */
    ast_node t = create_ast_node(ID_N);
    t->value_string = strdup(savedIdText);
    $1 = t;
  }  '=' expression {
    ast_node t2 = create_ast_node(OP_ASSIGN_N);
    t2->left_child = $1;
    $1->right_sibling = $4;
    $$ = t2;
  }
|  ID_T '[' INTCONST_T ']' { /* array[number] */
    ast_node t1 = create_ast_node(ARRAY_TYPE_N);
    ast_node  t2 = create_ast_node(INT_LITERAL_N);
    t1->value_string = strdup(savedIdText);
    t1->left_child = t2;
    t2->value_int = atoi(savedLiteralText);

    $$ = t1; /* <later> catch negative array length here? */
  }
;

funcDeclaration : INT_T ID_T { /* embedded action required to prevent savedIDtext from being overwritten */
  ast_node t1 = create_ast_node(FUNCTION_N);
  t1->value_string = strdup(savedIdText);
  t1->return_type = INT_TYPE_N;
  $2 = t1; 
  }'(' formalParams ')' compoundStatement {
/* removed functypespecifier, replaced with INT_T */
  ast_node t = $2;
  t->left_child = $5;
  t->left_child->right_sibling = $7;
  $$ = t;
}
| VOID_T ID_T { /* embedded action required to prevent savedIDtext from being overwritten */
  ast_node t1 = create_ast_node(FUNCTION_N);
  t1->value_string = strdup(savedIdText);
  t1->return_type = VOID_TYPE_N;
  $2 = t1; 
  } '(' formalParams ')' compoundStatement {
/* removed functypespecifier, replaced with INT_T */
  ast_node t = $2;
  t->left_child = $5;
  t->left_child->right_sibling = $7;
  $$ = t;
}
; 



formalParams : formalList  {
    ast_node t = create_ast_node(FORMAL_PARAMS_N);
    t->left_child = $1;
    $$ = t;
  }
|  VOID_T {
  ast_node t = create_ast_node(FORMAL_PARAMS_N);
  $$ = t; /* <later> */
} 
|  /* empty */ {
  ast_node t = create_ast_node(FORMAL_PARAMS_N);
  $$ = t;
}
;

formalList : formalList ',' formalParam {
    ast_node t = $1;
    while(t->right_sibling != NULL){
      t = t->right_sibling;
    }
    t->right_sibling = $3;
    $$ = $1;
  } 
|  formalParam {$$ = $1; }
|   formalList ',' error {$$ = NULL;}
;

formalParam : INT_T ID_T { /* replaced varTypeSpecifier to INT_T*/
     /* error handling <later>? */
    ast_node t = create_ast_node(ID_N);
    t->value_string = strdup(savedIdText);
    t->return_type = INT_TYPE_N;
    $$ = t;
  }
|  INT_T ID_T '[' ']' { /* replaced varTypeSpecifier to INT_T*/
    /*<later*/
    ast_node t = create_ast_node(ARRAY_TYPE_N);
    t->return_type = INT_TYPE_N;
    t->value_string = strdup(savedIdText);
    $$ = t;
  }
| INT_T error {$$ = NULL;}
;

compoundStatement : '{' localDeclarations statementList '}' {
  ast_node t = create_ast_node(SEQ_N);
  ast_node temp = t;
  t->left_child = $2;
  t = t->left_child;
  while(t->right_sibling != NULL){
    t = t->right_sibling;
  }
  t->right_sibling = $3; /* local declarations before code */
  $$ = temp;
}
; /* SEQ_N? (see lec 7 slide, ast diagram) */

localDeclarations : localDeclarations varDeclaration {
  ast_node t = $1;

  if(t->left_child == NULL) {
    t->left_child = $2;
  }
  else {
    t = t->left_child;
    while(t->right_sibling != NULL) {
      t = t->right_sibling;
    }
    t->right_sibling = $2;
  }

  $$ = $1;
 }  
|  /* empty */ {
  ast_node t = create_ast_node(LOCAL_DECLARATIONS_N);
  $$ = t;
}
;

statementList : statementList statement  {
  ast_node t = $1;

  if(t->left_child == NULL) {
    t->left_child = $2;
  }
  else {
    t = t->left_child;
    while(t->right_sibling != NULL) {
      t = t->right_sibling;
    }
    t->right_sibling = $2;
  }

  $$ = $1;
 }
|  /* empty */ {
  ast_node t = create_ast_node(STATEMENT_LIST_N);
  $$ = t;

  }
 /* | statementList error {$$ = NULL;} */
 /* enabling error token for statementList causes segfaults by ast preorder walk print out */
;
 /* for all the statements requiring a condition input, the conditions are inserted in ast as left child */
statement : expressionStatement  {$$ = $1; }
|  compoundStatement    {$$ = $1; }
|  ifStatement          {$$ = $1; }
|  whileStatement       {$$ = $1; }
|  doWhileStatement     {$$ = $1; }
|  forStatement         {$$ = $1; }
|  returnStatement      {$$ = $1; }
|  readStatement        {$$ = $1; }
|  printStatement       {$$ = $1; }
;

expressionStatement : expression ';'  { $$ = $1; }
|  ';' { $$ = NULL; }
;

/*  ifStatement : IF_T '(' expression ')' statement         */
/*  |  IF_T '(' expression ')' statement ELSE_T statement   */
/*  ;                                                       */

 /* implementation followed from flex and bison book */

ifStatement : IF_T '(' expression ')' statement   %prec LOWER_THAN_ELSE {
  ast_node t = create_ast_node(IF_STMT_N);
  t->left_child = $3;
  t->left_child->right_sibling = $5;
  $$ = t; }
| IF_T '(' expression ')' statement ELSE_T statement {
  ast_node t = create_ast_node(IF_ELSE_STMT_N);
  t->left_child = $3;
  t->left_child->right_sibling = $5;
  t->left_child->right_sibling->right_sibling = $7;
  $$ = t; }
| IF_T '(' error ')' statement %prec LOWER_THAN_ELSE
{ $$ = NULL; }
| IF_T '(' error ')' statement ELSE_T statement { $$ = NULL; }
;


whileStatement : WHILE_T '(' expression ')' statement {
  ast_node t = create_ast_node(WHILE_N);
  t->left_child = $3;
  t->left_child->right_sibling = $5;
  $$ = t; }
| WHILE_T '(' error ')' error {$$ = NULL;}
;

doWhileStatement : DO_T statement WHILE_T '(' expression ')' ';' {
    ast_node t = create_ast_node(DO_WHILE_N);
    t->left_child = $5;
    t->left_child->right_sibling = $2;
    $$ = t;
  }
| DO_T error WHILE_T '(' error ')' ';' {$$ = NULL;}
;

forStatement : FOR_T '(' forHeaderExpression ';' forHeaderExpression ';' forHeaderExpression ')' statement {
    ast_node t = create_ast_node(FOR_N);
    t->left_child = $3;
    t->left_child->right_sibling = $5;
    t->left_child->right_sibling->right_sibling = $7;
    t->left_child->right_sibling->right_sibling->right_sibling = $9;

    $$ = t;
  }
|   FOR_T '(' error ';' error ';' error ')' error {$$ = NULL;}
|   FOR_T '(' error ')' error {$$ = NULL;}
; 

forHeaderExpression : expression  { $$ = $1; }
|  /* empty */ { 
    ast_node t = create_ast_node(FOR_HEADER_EMPTY_N);
  }
;

returnStatement : RETURN_T ';' {
   ast_node t = create_ast_node(RETURN_N);
   $$ = t;
  }
|  RETURN_T expression ';' {
    ast_node t = create_ast_node(RETURN_N);
    t->left_child = $2;
    $$ = t;
  }
|  RETURN_T error ';' {$$ = NULL;}
;

readStatement : READ_T var ';' {
    ast_node t = create_ast_node(READ_N);
    t->left_child = $2;
    $$ = t;
  }
| READ_T error ';' {$$=NULL;}
; 

printStatement : PRINT_T expression ';'  {
  ast_node t = create_ast_node(PRINT_N);
  t->left_child = $2;
  $$ = t;
}
|  PRINT_T STRINGCONST_T ';' {
  ast_node t1 = create_ast_node(PRINT_N);
  ast_node t2 = create_ast_node(STRING_LITERAL_N);
  t2->value_string = strdup(savedLiteralText);
  t1->left_child = t2;
  $$ = t1;
}
| PRINT_T error ';' {$$ = NULL;}
;

expression : var '=' expression {
    assert($1 != NULL);
    assert($3 != NULL);
    ast_node t = create_ast_node(OP_ASSIGN_N);
    t->left_child = $1;
    t->left_child->right_sibling = $3;
    $$ = t; 
  }
|  rValue {$$ = $1; }
|  var '=' error {$$ = NULL;}
;

var : ID_T  {
   ast_node t = create_ast_node(ID_N);
   t->value_string = strdup(savedIdText);
   $$ = t;
 }
|  ID_T {
     ast_node t1 = create_ast_node(ARRAY_TYPE_N);
     t1->value_string = strdup(savedIdText);
     $1 = t1; 
  } '[' expression ']' {
     /*<later*/
   ast_node t2 = $1;
    t2->left_child = $4;
    $$ = t2;
 }
;


 /* define grammar for standard unary and binary operators */
rValue : expression '+' expression  {
ast_node t = create_ast_node(OP_PLUS_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t;
  }
|  expression '-' expression  {
  ast_node t = create_ast_node(OP_MINUS_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  expression '*' expression  {
  ast_node t = create_ast_node(OP_TIMES_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  expression '/' expression  {
  ast_node t = create_ast_node(OP_DIVIDE_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  expression '%' expression  {
  ast_node t = create_ast_node(OP_MODULUS_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  expression '<' expression  {
  ast_node t = create_ast_node(OP_LESS_THAN_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  expression LESS_EQUAL_T expression  {
  ast_node t = create_ast_node(OP_LESS_EQUAL_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  expression '>' expression  {
  ast_node t = create_ast_node(OP_GREATER_THAN_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  expression GREATER_EQUAL_T expression  {
  ast_node t = create_ast_node(OP_GREATER_EQUAL_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  expression ISEQUAL_T expression  {
  ast_node t = create_ast_node(OP_EQUALS_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  expression NOTEQUAL_T expression  {
  ast_node t = create_ast_node(OP_NOT_EQUAL_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  expression AND_T expression  {
  ast_node t = create_ast_node(OP_AND_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  expression OR_T expression  {
  ast_node t = create_ast_node(OP_OR_N);
  t->left_child = $1;
  t->left_child->right_sibling = $3;
  $$ = t; }
|  '!' expression  {
  ast_node t = create_ast_node(OP_NOT_N);
  t->left_child = $2;
  $$ = t; }
|  '-' expression %prec UMINUS_T {
  ast_node t = create_ast_node(OP_NEG_N);
  t->left_child = $2;
  $$ = t; }
|  var  { $$ = $1; }
|  INCREMENT_T var  {
  ast_node t = create_ast_node(OP_INCREMENT_N);
  t->left_child = $2;
  $$ = t; }
|  DECREMENT_T var  {
  ast_node t = create_ast_node(OP_DECREMENT_N);
  t->left_child = $2;
  $$ = t; }
|  '(' expression ')'  { $$ = $2; }
|  call  { $$ = $1; }
|  INTCONST_T  {
  ast_node t = create_ast_node(INT_LITERAL_N);
  t->value_int = atoi(savedLiteralText);
  $$ = t;

  #ifdef DEBUG
  printf("value_int = %d\n", t->value_int);
  #endif

   }
;

/* embedded action is required to retain the string val of id_t */
call : ID_T {
    ast_node t1 = create_ast_node(FUNCTION_N);
    t1->value_string = strdup(savedIdText);
    $1 = t1;
  } '(' args ')' {
   ast_node t2 = create_ast_node(CALL_N);
   $1->left_child = $4;
   
   t2->left_child = $1;
   $$ = t2;
 }
;

args : argList  {$$ = $1; }
|  /* empty */ {$$ = NULL; }
;

argList : argList ',' expression  {
  ast_node t = $1;
  assert(t != NULL);
    while (t->right_sibling != NULL) { 
      t = t->right_sibling; 
    }
    t->right_sibling = $3;
    $$ = $1;
 }
|  expression {$$ = $1; }
|  error ',' error {$$ = NULL;}
;







%%
 /* this function redefinition prints out line number as well */

int yyerror(char *s) {
  parseError = 1;
  
  //if( YYRECOVERING() )
    fprintf(stderr, "%s at line %d\t yytext = '%s'\n", s, num_lines, yytext);
  return 0;
}
