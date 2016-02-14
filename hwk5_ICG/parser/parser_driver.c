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
int typeError = 0;
int returnError = 0;
int funcError = 0;

int main() {
 int noRoot = 0;		/* 0 means we will have a root */

  //yydebug = 1; 	//uncomment to enable tracing
 	noRoot = yyparse();

 	if (parseError)	{
 		fprintf(stderr, "\nWARNING: There were parse errors. Parse tree may be ill-formed.\n\n");
 	}
 	// else {
 	// printf("\nNo syntatical errors detected.\n\n");
 	//}
 	if (!noRoot) {

 		symboltable_t *symtab = create_symboltable();
 		build_symbol_table(root, 0, 0, symtab); //builds symbol table and checks for variable/func declaration and scope appropriate use

 		printf("\nPrint hashtables (level-sibno) according to their hierarchy\n");
 		pretty_print(symtab->root, 0);	//prints symbol table nicely
 		if(symtabError) {	//when we get var/func use without declaration, we cannot progress any further as we cannot build the sym table which later funcs depend on
 			fprintf(stderr, "\nWARNING: There were symtab creation errors. Halting!\n");
 		}
 		else {
	 		record_var_type_in_ast(root, symtab); //must come after build_symbol_table, records all variable types by using symbol table

	 		printf("\n\n");
 			
			infer_type(root); //must come after record_var_type_in_ast, infers types for OP and assign
			if(typeError ) {
				fprintf(stderr, "\nWARNING: There were type inconsistency errors. Data structure may be ill-formed.\n\n");
			}
			check_function(root, symtab); //must come after record_var_type_in_ast, checks for appriate function calls (no. of params, type of each param)
			if(funcError) {
				fprintf(stderr, "\nWARNING: There were function errors. Data structure may be ill-formed.\n\n");
			}
			check_return(root, symtab); //must be after infer, checks whether the return is a valid one for a function. implicit inserts return at the end of void 
			if(returnError) {
				fprintf(stderr, "\nWARNING: There were return errors. Data structure may be ill-formed.\n\n");
			}
      		print_ast(root, 0, 0, 0); //print ast tree with added information
			//print_ast relies on data inserted from build_symbol_table above;
			//print_ast relies on check_return

 		}
 	}

 	else
 		fprintf(stderr,"Error: NO root!\n");

 	return 0;
 }
