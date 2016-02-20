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


int gen_target_code (quad_type **array, char argv[], symboltable_t* symboltable) {

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

	assert(ofile != NULL);

	calculate_var_offsets(symboltable->root);
	calculate_string_addrs(symboltable->literal_collection);

	fprintf(ofile, "END OF PROG: %d", ENDOFPROG);

	for(int i = 0; i < quad_index; i++){

		int type1;
		int type2;

		print_quad(array[i]);

		switch(array[i]->op){
			case Q_ASSIGN:
				/*
				   Move the value of the right hand side into %eax,
				   then call assign(), which will take care of moving it
				   into the location of the symnode (somewhere in memory,
				   depending on whether the left hand side is a temp, a global,
				   etc.)
				*/
				move_to_reg(array[i]->src1, LEFT_OPERAND_REG);
				assign(array[i]->dest);
				break;

			/*~~~~~~~~~ Binary operations ~~~~~~~~~*/
			case Q_ADD:
				move_to_reg_bin(array[i]);
				fprintf(ofile, "\taddl %%ecx, %%eax\n");
				fprintf(ofile, "\n");
				break;

			case Q_SUB:
				move_to_reg_bin(array[i]);
				fprintf(ofile, "\tsubl %%ecx, %%eax\n");
				fprintf(ofile, "\n");
				break;

			case Q_MULT:
				move_to_reg_bin(array[i]);
				fprintf(ofile, "\tmull %%ecx, %%eax\n");
				fprintf(ofile, "\n");
				break;

			case Q_DIV:
				move_to_reg_bin(array[i]);
				fprintf(ofile, "NOW PRINTING DIVISION\n");
				fprintf(ofile, "\tdivl %%ecx, %%eax\n");
				fprintf(ofile, "\n");
				break;


			case Q_MOD:
				move_to_reg_bin(array[i]);
				fprintf(ofile, "\tmodl %%ecx, %%eax\n");
				fprintf(ofile, "\n");
				break;

			/*~~~~~~~~~ Unary operations ~~~~~~~~~*/

			case Q_INC:
				//move_to_reg_un(array[i]);
				// move to %eax
				move_to_reg(array[i]->src1, LEFT_OPERAND_REG);
//				fprintf(ofile, "I AM NOW IN INC\n");
				fprintf(ofile, "\tirmovl 1, %%ecx\n");
				fprintf(ofile, "\taddl %s, %s\n", RIGHT_OPERAND_REG, LEFT_OPERAND_REG);
				if(assign(array[i]->src1) == 0){
					fprintf(ofile, "ERROR. TRYING TO ASSIGN VALUE TO INT\n");
				}
				break;

			case Q_DEC:
				move_to_reg(array[i]->src1, LEFT_OPERAND_REG);
				fprintf(ofile, "\tirmovl 1, %%ecx\n");
				fprintf(ofile, "\tsubl %s, %s\n", RIGHT_OPERAND_REG, LEFT_OPERAND_REG);

				if(!assign(array[i]->src1)){
					fprintf(ofile, "\n\n\nERROR. TRYING TO ASSIGN VALUE TO INT\n\n\n");
				}

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

	put_strings_in_mem(symboltable->literal_collection);
	print_global_vars(symboltable);

	return 0;
}


/*~~~~~~~~~~~~~~~~~~~~ Helper functions ~~~~~~~~~~~~~~~~~~~~~~~~*/


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


/* Allocates space for all the variables in the symbol table */
void calculate_global_var_addrs(symboltable_t *symboltable){
	int global_var_offset = 0;
	symhashtable_t *hashtable = symboltable->root;

  for(int j = 0; j < HASHSIZE; j++) {
    for(symnode_t *node = hashtable->table[j]; node != NULL; node = node->next) {

      if(node->type == VAR_INT_T){
				node->addr = endofstr + global_var_offset;
				global_var_offset += 4;
      }

			if(node->type == VAR_ARRAY_INT_T) {
				node->addr = global_var_offset;
				global_var_offset += (node->abnode->array_length * 4);
			}
    }
  }
}


/* Print the global variables into the file */
void print_global_vars(symboltable_t *symboltable){
	symhashtable_t *hashtable = symboltable->root;

	fprintf(ofile, "\n.pos 0x%x   # Start of global var space \n", endofstr);

	for(int j = 0; j < HASHSIZE; j++) {
    for(symnode_t *node = hashtable->table[j]; node != NULL; node = node->next) {

      if(node->type == VAR_INT_T){
				fprintf(ofile, "\t.long 0x%08x\n", node->num_val);
      }

			if(node->type == VAR_ARRAY_INT_T) {
				for(int i = 0; i < node->abnode->array_length; i++){
					fprintf(ofile, "\t.long 0x%08x\n", 0);
				}
			}
    }
  }
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
	endoftemp = (temp_counter * 4 + ENDOFPROG + 4); // Where in memory the strings should start
	// +4 because that's the space for the last quad.
	int str_offset = 0;	// str_offset

	// Traverse the hashtable looking for strings (we have to put them in
	// memory).
	for(int j = 0; j < HASHSIZE; j++ ) {
		for(symnode_t *node = hashtable->table[j]; node != NULL; node = node->next) {


			if(node->type == STRING_T){
				// fprintf(ofile, "Found a string: %s\n", node->name);
				// Allocate memory for it
				node->addr = str_offset + endoftemp;
				str_offset += round_str_addr(node->name);
			}
		}
	}
	endofstr = endoftemp + str_offset + 4;
}


/*
*/
void put_strings_in_mem(symhashtable_t* hashtable){

	assert(ofile != NULL);


	fprintf(ofile, ".pos 0x%x    #Start of string space\n", endoftemp);

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
						fprintf(ofile, "\n\t.long \t0x");
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


/*
  Returns the type of the symnode (variable, temp, int) so that it is treated
  properly by other functions.
*/
int get_symnode_type(symnode_t *snode){
  char *substr1 = substring(snode->name, 3); // first 3 chars of name
  char *substr2 = substring(snode->name, 2); // first 2 chars of name

  // if name starts with anything other than __, it is a var
  if(strcmp(substr2, "__") != 0){
		free(substr2);
		return VAR_SYMNODE;
  }
  free(substr2);

  if(strcmp(substr1, "__T") == 0){
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


void print_quad(quad_type *quad){
	fprintf(ofile, "(%s, %s, ",OP_NAME(quad->op), quad->dest->name);
	if (quad->src1 != NULL)
		fprintf(ofile, "%s, ",quad->src1->name);
	else
		fprintf(ofile, "-, ");
	if (quad->src2 != NULL)
		fprintf(ofile, "%s)\n", quad->src2->name);
	else
		fprintf(ofile, "-)\n");
}


/*
  Moves the operands of a quad containing a binary operation into %eax and %ecx.
	The left operand is moved into %eax, while the right one is moved into %ecx.
*/
// void move_to_reg_bin(quad_type *quad){
// 	int type1 = get_symnode_type(quad->src1);
// 	int type2 = get_symnode_type(quad->src2);
//
// 	fprintf(ofile, "\n\t");
// 	if(type1 == INT_SYMNODE){
// 		fprintf(ofile, "irmovl %x, %%eax\n", quad->src1->num_val);
// 	} else if(type1 == TEMP_SYMNODE){
// 		fprintf(ofile, "mrmovl %d, %%eax\n", get_temp_addr(quad->src1));
// 	} else{ // var
// 		if(is_var_global(quad->src1)){
// 			fprintf(ofile, "mrmovl %d, %%eax\n", quad->src1->addr);
// 		} else{
// 			fprintf(ofile, "mrmovl %d(%%ebp), %%eax\n", quad->src1->offset);
// 		}
// 	}
//
// 	fprintf(ofile, "\t");
// 	// Move first operand into %ecx
// 	if(type2 == INT_SYMNODE){
// 		fprintf(ofile, "irmovl %x, %%ecx\n", quad->src2->num_val);
// 	} else if(type2 == TEMP_SYMNODE){
// 		fprintf(ofile, "mrmovl %d, %%ecx\n", get_temp_addr(quad->src2));
// 	} else{ // var
// 		if(is_var_global(quad->src2)){
// 			fprintf(ofile, "mrmovl %d, %%ecx\n", quad->src2->addr);
// 		} else{
// 			fprintf(ofile, "mrmovl %d(%%ebp), %%ecx\n", quad->src2->offset);
// 		}
// 	}
//}

void move_to_reg_bin(quad_type *quad){
	move_to_reg(quad->src1, LEFT_OPERAND_REG);
	move_to_reg(quad->src2, RIGHT_OPERAND_REG);
}

/*
  Moves a unary operand into %eax.
*/
// void move_to_reg_un(quad_type *quad){
// 	int type = get_symnode_type(quad->src1);
//
// 	fprintf(ofile, "\n\t");
// 	if(type == INT_SYMNODE){
// 		fprintf(ofile, "irmovl %x, %%eax\n", quad->src1->num_val);
// 	} else if(type == TEMP_SYMNODE){
// 		fprintf(ofile, "mrmovl %d, %%eax\n", get_temp_addr(quad->src1));
// 	} else{ // var
// 		if(is_var_global(quad->src1)){
// 			fprintf(ofile, "mrmovl %d, %%eax\n", quad->src1->addr);
// 		} else{
// 			fprintf(ofile, "mrmovl %d(%%ebp), %%eax\n", quad->src1->offset);
// 		}
// 	}
// }

/*
  Moves a unary operand into %eax.
*/
void move_to_reg_un(quad_type *quad){
	move_to_reg(quad->src1, LEFT_OPERAND_REG);
}


/*
   Handles register and memory moves to assign a value to a particular variable
	 or temp.
	 Uses %edx to store the right value, then moves it as appropriate.
	 Returns 1 if successful, 0 if unsuccessful (when trying to assign to an int)
*/
int assign(symnode_t *left_val){
	assert(left_val != NULL);
	//assert(right_val != NULL);

	int left_type = get_symnode_type(left_val);
	//int right_type = get_symnode_type(right_val);

	if(left_type == INT_SYMNODE){ // Can't assign to right value.
		return 0;
	} else{
		if(left_type == TEMP_SYMNODE){
			fprintf(ofile, "\trmmovl %s, %d\n", LEFT_OPERAND_REG, get_temp_addr(left_val));
		}
		else{ // var
			if(is_var_global(left_val)){
				fprintf(ofile, "\trmmvol %s, %d\n", LEFT_OPERAND_REG, left_val->addr);
			} else{
				fprintf(ofile, "\trmmovl %s, %d(%s)\n", LEFT_OPERAND_REG, left_val->offset, BASE_PTR);
			}
		}
		return 1;
	}
}

/*
   Moves the right hand side of an assignment operation into %eax (since assign moves
   whatever is located in %eax into memory)
*/
void move_to_reg_rhs(quad_type *quad){
	int type = get_symnode_type(quad->src2);
	fprintf(ofile, "\t");

	if(type == INT_SYMNODE){
		fprintf(ofile, "irmovl %x, %s\n", quad->src2->num_val, LEFT_OPERAND_REG);
	} else if(type == TEMP_SYMNODE){
		fprintf(ofile, "mrmovl %d, %s\n", get_temp_addr(quad->src2), LEFT_OPERAND_REG);
	} else{ // var
		if(is_var_global(quad->src2)){
			fprintf(ofile, "mrmovl %d, %s\n", quad->src2->addr, LEFT_OPERAND_REG);
		} else{
			fprintf(ofile, "mrmovl %d(%s), %s\n", quad->src2->offset, BASE_PTR, LEFT_OPERAND_REG);
		}
	}
}


// /*
//    Moves the right hand side of an assignment operation into %eax (since assign moves
//    whatever is located in %eax into memory)
// */
// void move_to_assign_reg(symnode_t *operand){
// 	int type = get_symnode_type(operand);
//
// 	fprintf(ofile, "\t");
// 	if(type == INT_SYMNODE){
// 		fprintf(ofile, "irmovl %x, %s\n", operand->num_val, LEFT_OPERAND_REG);
// 	} else if(type == TEMP_SYMNODE){
// 		fprintf(ofile, "mrmovl %d, %s\n", get_temp_addr(operand), LEFT_OPERAND_REG);
// 	} else{ // var
// 		if(is_var_global(operand)){
// 			fprintf(ofile, "mrmovl %d, %s\n", operand->addr, LEFT_OPERAND_REG);
// 		} else{
// 			fprintf(ofile, "mrmovl %d(%s), %s\n", operand->offset, BASE_PTR, LEFT_OPERAND_REG);
// 		}
// 	}
// }

void move_to_reg(symnode_t *operand, char *reg){
	int type = get_symnode_type(operand);

	fprintf(ofile, "\t");
	if(type == INT_SYMNODE){
		fprintf(ofile, "irmovl %x, %s\n", operand->num_val, reg);
	} else if(type == TEMP_SYMNODE){
		fprintf(ofile, "mrmovl %d, %s\n", get_temp_addr(operand),reg);
	} else{ // var
		if(is_var_global(operand)){
			fprintf(ofile, "mrmovl %d, %s\n", operand->addr, reg);
		} else{
			fprintf(ofile, "mrmovl %d(%s), %s\n", operand->offset, BASE_PTR, reg);
		}
	}
}
