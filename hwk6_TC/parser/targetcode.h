
#ifndef TARGETCODE_H_
#define TARGETCODE_H_

#include "string.h"
#include "assert.h"
#include "quad.h"
#include "ast.h"
#include "symtab.h"

extern int quad_index;

#define ENDOFPROG (quad_index * 6) + (4 - (quad_index * 6) % 4);
#define HASHSIZE 211

/* Need to differentiate between these as getting values into registers will
   be handled differently for each of these. */
#define VAR_SYMNODE 0
#define TEMP_SYMNODE 1
#define INT_SYMNODE 2


int gen_target_code (quad_type **array, char argv[]);


void put_strings_in_mem(symhashtable_t* hashtable);

void calculate_string_addrs(symhashtable_t* hashtable);

int get_symnode_type(symnode_t *snode);

int get_temp_addr(symnode_t* temp);

int is_var_global(symnode_t *var);

int round_str_addr(char* str);
void calculate_var_offsets_helper(symhashtable_t* hashtable);
int calculate_var_offsets(symhashtable_t* hashtable);

char *substring(char *str, int len);

#endif
