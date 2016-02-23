
#ifndef TARGETCODE_H_
#define TARGETCODE_H_

#include "string.h"
#include "assert.h"
#include "quad.h"
#include "ast.h"
#include "symtab.h"

extern int quad_index;

#define ENDOFPROG ((quad_index * 6 * 5) + (4 - (quad_index * 6 * 5) % 4))
#define HASHSIZE 211

/* Need to differentiate between these as getting values into registers will
   be handled differently for each of these. */
#define VAR_SYMNODE 0
#define TEMP_SYMNODE 1
#define INT_SYMNODE 2
#define RET_SYMNODE 3


/*
   Macros for the registers, which we plan to use for specific operations.
   Defining a macro allows us to change this later without having to change
   them one by one.
   Not escaping them because when printing them, the escaping character also
   gets printed.
*/
#define LEFT_OPERAND_REG "%eax"    // Also used to store the result of operations
                                    // (e.g., irmovl %ecx, %eax)
#define RIGHT_OPERAND_REG "%ecx"
#define IO_REG "%edx"
#define STACK_PTR "%esp"
#define BASE_PTR "%ebp"
#define RETURN_REG "%edi"
#define DSTR "0x00FFFE10"
#define DHXR "0x00FFFE14"
#define KHXR "0x00FFFE1C"
#define KSTR "0x00FFFE18"
#define KBDR "0x00FFFE04"


/* Translates array of quads into series of assembly instructions */
int gen_target_code (quad_type **array, char argv[], symboltable_t *symboltable);

/*
   Lays out the strings in their location in memory as .byte directives
*/
void put_strings_in_mem(symhashtable_t* hashtable);

/* Calculates the location of strings in memory and stores that location in the
   symnode for the particular string
 */
void calculate_string_addrs(symhashtable_t* hashtable);

/*
  Returns the type of the symnode (variable, temp, int) so that it is treated
  properly by other functions.
*/
int get_symnode_type(symnode_t *snode);

/*
 * Gets the address of a temporary variable
 */
int get_temp_addr(symnode_t* temp);


/* Print the global variables into the file */
void print_global_vars(symboltable_t *symboltable);

/* Takes a str, and returns the amount of bytes it will need in memory (a multiple
   of 4), since addresses must be aligned in 4-byte boundaries. */
int round_str_addr(char* str);

void calculate_var_offsets_helper(symhashtable_t* hashtable);

/* Allocates space for all the variables in the symbol table */
void calculate_global_var_addrs(symboltable_t *symboltable);

int calculate_var_offsets(symhashtable_t* hashtable);

/*
  Returns a substring of str, from str[0] to str[len]
*/
char *substring(char *str, int len);

void print_quad(quad_type *quad);

/*
  Moves the operands of a quad containing a binary operation into %eax and %ecx.
	The left operand is moved into %eax, while the right one is moved into %ecx.
*/
void move_to_reg_bin(quad_type *quad);

/*
  Moves a unary operand into %eax.
*/
void move_to_reg_un(quad_type *quad);

/*
   Moves the value in operand (depending on whether it is a temp,
   a global, or a local variable), and issues an instruction to move
	 into the register specified by reg.
	 For possible registers, see targetcode.h's macros for registers.
*/
void move_to_reg(symnode_t *operand, char *reg);

/*
  Moves a value to stored in a register to the variable specified by target.
*/
void move_from_reg(char* reg, symnode_t* target);

/*
   Handles register and memory moves to assign a value seen in a quad
	 to a particular variable or temp.
	 Returns 1 if successful, 0 if unsuccessful (when trying to assign to an int
   or a register used for returning values)
*/
int assign(symnode_t *left_val);

/*
   Returns 1 if a label is a function, 0 otherwise
*/
int is_function(symnode_t *label);

void print_initialization();

void print_stack_setup();

/* Returns 1 if the function symnode has parameters, 0 otherwise*/
int has_params(symnode_t *node);

/* Returns 1 if the function symnode has local var declarations, 0 otherwise*/
int has_locals(symnode_t *node);


#endif
