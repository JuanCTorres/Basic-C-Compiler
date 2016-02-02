/*
 * parser_driver.c
 *
 * Driver program for a parser that builds an abstract syntax tree, and a symbol
 * table containing the identifiers of functions and variables declared in the
 * program to be compiled.
 *
 * Written by THC for CS 57; massaged by SWS; modified by Seok Jun Bing, Juan Torres.
 *
 * root node is a global variable that is needed by parser.y
 *
 * Last modified date: 01/31/16
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "symtab.h"
#include "ast.h"





 ast_node root = NULL;

 extern int yyparse();
 extern int yydebug;
 int parseError = 0;
 int symtabError = 0;


 int main() {
 int noRoot = 0;		/* 0 means we will have a root */

  //yydebug = 1; 	//uncomment to enable tracing
 	noRoot = yyparse();

 	if (parseError)	{
 		fprintf(stderr, "WARNING: There were parse errors.\nParse tree may be ill-formed.\n\n");
 	}
 	// else {
 	// printf("\nNo syntatical errors detected.\n\n");
 	//}
 	if (!noRoot) {
 		
 		symboltable_t *symtab = create_symboltable();
 		build_symbol_table(root, 0, 0, symtab);
 		
 		printf("\n\nPrint hashtables (level-sibno) according to their hierarchy\n");
 		pretty_print(symtab->root, 0);
 		if(symtabError) {
 			fprintf(stderr, "WARNING: There were symtab creation errors. Halting!\n");
 		}
 		else {
	 			record_var_type_in_ast(root, symtab); //must come after build_symbol_table
	 			check_function(root, symtab); //must come after record_var_type_in_ast
	 			printf("\n\n");
	 			print_ast(root, 0, 0, 0);	//uncomment to print the ast structure and the scope relations
				//print_ast relies on data inserted from build_symbol_table above;
 		}
 	}

 	else
 		fprintf(stderr,"Error: NO root!\n");

 	return 0;
 }
