/*
 * parser_driver.c
 *
 * Driver program for a parser that builds an abstract syntax tree.
 *
 * Written by THC for CS 57; massaged by SWS; modified by Seok Jun Bing, Juan Torres.
 *
 * root node is a global variable that is needed by parser.y
 *
 * Last modified date: 01/21/16
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ast.h"
#include "symtab.h"





 ast_node root = NULL;

 extern int yyparse();
 extern int yydebug;
 int parseError = 0;

 int main() {
  int noRoot = 0;		/* 0 means we will have a root */

  //yydebug = 1; 	//uncomment to enable tracing
 	noRoot = yyparse();

 	if (parseError)	{
 		fprintf(stderr, "WARNING: There were parse errors.\nParse tree may be ill-formed.\n\n");
	}
	else {
		printf("No syntatical errors detected.\n\n");
	}
 	if (!noRoot) {
 		print_ast(root, 0, 0, 0);
 		symboltable_t *something = create_symboltable();
 		build_symbol_table(root, 0, 0, something);
 		pretty_print(something->root, 0);
 	}

 	else
 		fprintf(stderr,"Error: NO root!\n");

 	return 0;
 }
