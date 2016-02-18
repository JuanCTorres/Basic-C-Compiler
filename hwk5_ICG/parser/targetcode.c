#include "string.h"
#include "assert.h"
#include "quad.h"
#include "ast.h"
#include "symtab.h"

#include <stdio.h>
#include <stdlib.h>




int gen_target_code (quad_type **array, char argv[]) {


	char *filename = calloc(sizeof(char), 100);
	if(NULL == strcat(filename, argv[1])) {
		assert(0);
	}
	if(NULL == strcat(filename, ".ys")) {
		assert(0);
	}

	FILE *ofile = fopen(filename, "w");

	fprintf(ofile, "sadsdsad")

	// switch() {

	// 	case
	// 	break




	// }
}