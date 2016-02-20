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
    int type1;
    int type2;

		switch(array[i]->op){
			case Q_ASSIGN:

				break;

			case Q_ADD:
        type1 = get_symnode_type(array[i]->src1);
        type2 = get_symnode_type(array[i]->src1);

        // Move first operand into %eax
        if(type1 == INT_SYMNODE){
          fprintf(ofile, "irmovl %08x, %%eax\n", array[i]->src1->num_val);
        } else if(type1 == TEMP_SYMNODE){
          fprintf(ofile, "mrmovl %d, %%eax\n", get_temp_addr(array[i]->src1));
        } else{ // var
          if(is_var_global(array[i]->src1)){
            //fprintf(ofile, "mrmovl %d", );
          }
          //fprintf(ofile, "mrmovl %d(%%ebp), %%eax\n", array[i]->src1->offset);
        }

        // Move first operand into %ecx
        if(type2 == INT_SYMNODE){
          fprintf(ofile, "irmovl %d, %%ecx\n", array[i]->src2->num_val);
        } else if(type2 == INT_SYMNODE){
          fprintf(ofile, "mrmovl %d, %%ecx\n", get_temp_addr(array[i]->src2));
        } else{ // var
          //fprintf(ofile, "mrmovl %d(%%ebp), %%ecx");
        }

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
    return 0;
	}
//
//
// 	// switch() {
//
// 	// 	case
// 	// 	break
//
//
//
//
// 	// }
//
//
	return 0;
}
//
//
/*~~~~~~~~~~~~~~~~~~~~ Helper functions ~~~~~~~~~~~~~~~~~~~~~~~~*/

/* Allocates space for all the variables in the symbol table */
void calculate_var_addrs(symhashtable_t *symtable){

	// for(int j = 0; j < HASHSIZE; j++ ) {
	// 	for(symnode_t *node = hashtable->table[j]; node != NULL; node = node->next) {
	// 		if(node->type == VAR_INT_T){
  //
	// 		}
	// 	}
	// }
}


/* Returns 1 if var is global, i.e., was declared in scope (0-0)*/
int is_var_global(symnode_t *var){
  if(var->abnode->curr_level == 0 && var->abnode->curr_sib == 0){
    return 1;
  } else{
    return 0;
  }
}


/* */
int get_global_addr(symnode_t *var){
  return 0;
}


int get_temp_addr(symnode_t* temp){
	return temp->num_val * 4 + ENDOFPROG;
}


/* Calculates the location of strings in memory and stores that location in the
 symnode for the particular string */
void calculate_string_addrs(symhashtable_t* hashtable){

	endoftemp = temp_counter * 4 + ENDOFPROG + 4; // Where in memory the strings should start
	                                              // +4 because that's the space for the last quad.
	int str_offset = 0;	// str_offset

	// Traverse the hashtable looking for strings (we have to put them in
	// memory).
	for(int j = 0; j < HASHSIZE; j++ ) {
    for(symnode_t *node = hashtable->table[j]; node != NULL; node = node->next) {

			if(node->type == STRING_T){
				// Allocate memory for it
				node->addr = str_offset + endoftemp;
				str_offset += round_str_addr(node->name);
			}
    }
	}
  endofstr = str_offset + 4;
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


/*
  Takes a str, and returns the amount of bytes it will need in memory (a multiple
  of 4), since addresses must be aligned in 4-byte boundaries.
*/
int round_str_addr(char* str){
	int len = strlen(str);
	return len + 4 - (len % 4);
}


/*
  Returns the type of the symnode (variable, temp, int) so that it is treated
  properly by other functions.
*/
int get_symnode_type(symnode_t *snode){
  char *substr1 = substring(snode->name, 3);
  char *substr2 = substring(snode->name, 2);
  // if name starts with anything other than __, it is a var
  if(strcmp(substr2, "__") != 0){
    return VAR_SYMNODE;
  }
  free(substr2);

  if(strcmp(substr1, "__T")){
    free(substr1);
    return TEMP_SYMNODE;
  } else{
    free(substr1);
    return INT_SYMNODE;
  }
}


/*
  Returns a substring of str, from str[0] to str[len]
*/

char *substring(char *str, int len) {
  char *sub = calloc(len + 1, sizeof(char));
  assert(sub != NULL);
  strncpy(sub, str, len);
  sub[len] = '\0';
  return sub;
}
