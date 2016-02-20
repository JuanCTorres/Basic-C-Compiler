
#ifndef TARGETCODE_H_
#define TARGETCODE_H_

#include "string.h"
#include "assert.h"
#include "quad.h"
#include "ast.h"
#include "symtab.h"

extern int quad_index;

#define ENDOFPROG ((quad_index * 6) + (4 - (quad_index * 6) % 4))
#define HASHSIZE 211

/* Need to differentiate between these as getting values into registers will
   be handled differently for each of these. */
#define VAR_SYMNODE 0
#define TEMP_SYMNODE 1
#define INT_SYMNODE 2

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
#define ASSIGN_REG "%edx"
#define STACK_PTR "%esp"
#define BASE_PTR "%ebp"
#define RETURN_REG "%edi"


int gen_target_code (quad_type **array, char argv[], symboltable_t *symboltable);

void put_strings_in_mem(symhashtable_t* hashtable);

void calculate_string_addrs(symhashtable_t* hashtable);

int get_symnode_type(symnode_t *snode);

int get_temp_addr(symnode_t* temp);

int is_var_global(symnode_t *var);

void print_global_vars(symboltable_t *symboltable);

int round_str_addr(char* str);

void calculate_var_offsets_helper(symhashtable_t* hashtable);

int calculate_var_offsets(symhashtable_t* hashtable);

char *substring(char *str, int len);

void print_quad(quad_type *quad);

void move_to_reg_bin(quad_type *quad);

void move_to_reg_un(quad_type *quad);

void move_to_reg(symnode_t *operand, char *reg);

int assign(symnode_t *left_val);

#endif
