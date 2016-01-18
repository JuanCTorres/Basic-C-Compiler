/*The file name: 
*   toktype.h
* The purpose of the file:
*   contains array of names of Token Types as defined by enum
* The names of all the authors:
*   SeokJun Bing
*   Charles Li
*   Juan Torres
* Attributions, as appropriate.
*   need cscan.l, cscan.c
*
*/

#ifndef TOKTYPE_H_
#define TOKTYPE_H_

enum TokenType { ID_T=258, INTCONST_T, FLOATCONST_T, STRINGCONST_T,
                 PLUS_T, MINUS_T, ASTERISK_T, SLASH_T, MODULUS_T,
		             SEMICOLON_T, COMMA_T, ASSIGN_T,
                 SHARP_T, LESS_T, GREATER_T, ISEQUAL_T, NOTEQUAL_T,
		             SHL_T, DOT_T, ARROW_T,
		             INCLUDE_T, EXTERN_T, INT_T, CHAR_T, WHILE_T, FOR_T,
		             EOF_T, OTHER_T, LINE_COMMENT_T, MULTI_COMMENT_T,
                 AND_T, OR_T, NOT_T,
                 INCREMENT_T, DECREMENT_T,
                 LESS_EQUAL_T, GREATER_EQUAL_T, IF_T, ELSE_T, RETURN_T, VOID_T,
                 READ_T, PRINT_T, DO_T };

 // string names for the token types
 
static char *tokens[] =
              { "ID", "INTCONST", "FLOATCONST", "STRINGCONST",
                "PLUS", "MINUS", "ASTERISK", "SLASH", "MODULUS",
                "SEMICOLON", "COMMA", "ASSIGN",
                "SHARP", "LESS", "GREATER", "ISEQUAL", "NOTEQUAL",
                "SHL", "DOT", "ARROW",
                "INCLUDE", "EXTERN", "INT", "CHAR", "WHILE", "FOR",
                "EOF", "OTHER", "LINE_COMMENT", "MULTI_COMMENT",
                "AND", "OR", "NOT",
                "INCREMENT", "DECREMENT",
                "LESS_EQUAL", "GREATER_EQUAL", "IF", "ELSE", "RETURN", "VOID", "READ",
                "PRINT", "DO"};

#define FIRST_BIG_TOKEN ID_T
// so that it works even if ID_T ends up nonzero

char *token_name(int token);


#endif
