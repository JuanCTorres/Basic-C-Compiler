#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "targetcode.h"
#include "symtab.h"

extern int temp_counter;

/* In our memory space, first will come the program instructions, then the
temps, then strings, then variables, and later functions. Anything else? */
int endoftemp;
int endofstr;

FILE *ofile = NULL;


int gen_target_code (quad_type **array, char argv[]) {


	char *filename = calloc(sizeof(char), 100);
	if(NULL == strcat(filename, "./ys/")) {
		assert(0);
	}

	if(NULL == strcat(filename, argv)) {
		assert(0);
	}
	if(NULL == strcat(filename, ".ys")) {
		assert(0);
	}

	ofile = fopen(filename, "w");

	for(int i = 0; i < quad_index; i++){
		switch(array[i]->op){
			case Q_ASSIGN:

				break;

			case Q_ADD:
				fprintf(ofile, "mrmovl");
				break;

			case Q_SUB:

				break;

			case Q_MULT:

				break;

			case Q_DIV:

				break;

			case Q_INC:

				break;

			case Q_DEC:

				break;

			case Q_IFF:

				break;

			case Q_IFT:

				break;

			case Q_GOTO:

				break;

			case Q_LABEL:

				break;

			case Q_READ:

				break;

			case Q_PRINT:

				break;

			case Q_HALT:

				break;

			case Q_EQ:

				break;

			case Q_GT:

				break;

			case Q_LT:

				break;

			case Q_GTEQ:

				break;

			case Q_LTEQ:

				break;

			case Q_NEG:

				break;

			case Q_NEQ:

				break;

			case Q_MOD:

				break;

			case Q_CALL:

				break;

			case Q_PUSH:

				break;

			case Q_RETURN:

				break;

			case Q_JEQ:

				break;

			case Q_JGT:

				break;

			case Q_JGEQ:

				break;

			case Q_JLT:

				break;

			case Q_JLE:

				break;

			case Q_ADDR:

				break;

			case Q_DEREF:

				break;

			default:
				break;
		}
	}


	// switch() {

	// 	case
	// 	break




	// }


	return 0;
}


/*~~~~~~~~~~~~~~~~~~~~ Helper functions ~~~~~~~~~~~~~~~~~~~~~~~~*/

/* Allocates space for all the variables in the symbol table */
// int calculate_var_addrs(symhashtable* symtable){

// 	for(int j = 0; j < HASHSIZE; j++ ) {
// 		for(symnode_t *node = hashtable->table[j]; node != NULL; node = node->next) {
// 			if(node->type == VAR_INT_T){
// 				fprintf(ofile, "%s\n", node->name);
// 				// Create a label scope_sibling_name for each variable.
// 				fprintf(ofile, "\t.long %d_%d_%s\n", node->abnode->current_level,
// 				 node->abnode->current_sibling, node->name);
// 			}
// 		}
// 	}

// 	/* Recurse on each child of the subtree hashtable */
// 	symhashtable_t *child;
// 	for (child = hashtable->child; child != NULL; child = child->rightsib)
// 	pretty_print(child);

// }

int offset = -8;

int calculate_var_offsets(symhashtable_t* hashtable) {
	symhashtable_t *hash = NULL;
	for(int j = 0; j < HASHSIZE; j++ ) { //every index in hash
		for(symnode_t *node = hashtable->table[j]; node != NULL; node = node->next) { //every linked list at an index
			offset = -8;
			if(node->type == FUNC_INT_T || node->type == FUNC_VOID_T) {

				assert(node != NULL);
				assert(node->abnode != NULL); //ast_node
				assert(node->abnode->left_child != NULL); //formal_params
				assert(node->abnode->left_child->right_sibling != NULL); //SEQ
				assert(node->abnode->left_child->right_sibling->left_child != NULL); //LOCAL_DECLARATIONS
				// assert(node->abnode->left_child->right_sibling->left_child->left_child);
				
				
				if(node->abnode->left_child->left_child != NULL) {
					hash = node->abnode->left_child->left_child->snode->parent; //param
					// printf("\nLOLZ HERE!\n");
					calculate_var_offsets_helper(hash);
				}	

				else if(node->abnode->left_child->right_sibling->left_child->left_child != NULL) { //this means tht this function contains var declarations
							
					hash = node->abnode->left_child->right_sibling->left_child->left_child->snode->parent; //hashtabel containing var declaration
					calculate_var_offsets_helper(hash); //offset starts at eight
				}		

			}
		}
	}	
	return 0;

}



void calculate_var_offsets_helper(symhashtable_t* hashtable){

	for(int j = 0; j < HASHSIZE; j++ ) {
		for(symnode_t *node = hashtable->table[j]; node != NULL; node = node->next) {
			if(node->type == VAR_INT_T){
				node->offset = offset;
				offset -= 4;
				printf("%s %d\n", node->name,offset);
			} 
			else if(node->type == VAR_ARRAY_INT_T) {
				node->offset = offset;
				offset = offset - 4 * node->abnode->array_length;
			}
		}
	}

	/* Recurse on each child of the subtree hashtable */
	symhashtable_t *child;
	for (child = hashtable->child; child != NULL; child = child->rightsib)
		calculate_var_offsets_helper(child);

}


int get_temp_addr(symnode_t* temp){
	return temp->num_val * 4 + ENDOFPROG;
}


/* Calculates the location of strings in memory and stores that location in the
 symnode for the particular string */
void calculate_string_addrs(symhashtable_t* hashtable){

	endoftemp = temp_counter * 4 + ENDOFPROG + 4; // Where in memory the strings should start
	                                              // +4 because that's the space for the last quad.
	int offset = 0;	// offset

	// Traverse the hashtable looking for strings (we have to put them in
	// memory).
	for(int j = 0; j < HASHSIZE; j++ ) {
    for(symnode_t *node = hashtable->table[j]; node != NULL; node = node->next) {

			if(node->type == STRING_T){
				// Allocate memory for it
				node->addr = offset + endoftemp;
				offset += round_str_addr(node->name);
			}
    }
	}

}


/*
*/
void put_strings_in_mem(symhashtable_t* hashtable){

	fprintf(ofile, ".pos 0x%x\n", endoftemp);

	// Traverse the hashtable looking for strings (we have to put them in
	// memory).
	for(int j = 0; j < HASHSIZE; j++ ) {
    for(symnode_t *node = hashtable->table[j]; node != NULL; node = node->next) {

			if(node->type == STRING_T){
				// Allocate memory for it
				int counter = 0;
				int len = strlen(node->name);
				for(int counter = 0; counter < len; counter++){
					if(counter % 4 == 0){
						fprintf(ofile, "\n.long \t0x");
					}
					fprintf(ofile, "%x", node->name[counter]);
				}
			}
    }
	}
}


/* Takes a str, and returns the amount of bytes it will need in memory (a multiple
   of 4), since addresses must be aligned in 4-byte boundaries. */
int round_str_addr(char* str){
	int len = strlen(str);
	return len + 4 - (len % 4);
}
