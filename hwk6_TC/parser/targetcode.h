
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


int gen_target_code (quad_type **array, char argv[]);


void put_strings_in_mem(symhashtable_t* hashtable);

void calculate_string_addrs(symhashtable_t* hashtable);

int round_str_addr(char* str);

#endif
