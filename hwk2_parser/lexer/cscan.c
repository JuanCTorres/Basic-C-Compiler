/*The file name: 
*   cscan.c
* The purpose of the file:
*   contains main func as well as token_name() 
*   that returns string corresponding to TOKEN_T
* The names of all the authors:
*   SeokJun Bing
*   Charles Li
*   Juan Torres
* Attributions, as appropriate.
*   need cscan.l, toktype.h
*   use make to compile and link
*/


#include <stdio.h>
#include <string.h>
#include "toktype.h"

extern char *yytext;
extern int yyleng;
extern int yylex (void);
extern int num_lines;

char *token_name(int token) {
  char tiny_buf[2];

  if (token > 256) // non-single-char
    return (tokens[token - FIRST_BIG_TOKEN]);

  tiny_buf[1] = 0x00;
  tiny_buf[0] = token;
  return strdup(tiny_buf);
}

int main() {
  int token;

  while ((token = yylex()) != EOF_T)
    printf("line num: %2d\ttoken: %s\t\t length: %2d\t\"%s\"\n", num_lines, token_name(token), yyleng, yytext);

  return 0;
}

  /* Some tokens just to check: == 3.14 "quote\"x" -6.02e23 */
