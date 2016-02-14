#include "ast.h"
#include "string.h"
#include "quad.h"
#include <stdio.h>
#include <stdlib.h>


int temp_counter = 0;
quad_type = quad_array[1024*5];

 char* NewLabel(int node_num, char *text) {
     char *label_name = calloc(sizeof(char), 100);
     sprintf(label_name, "L_%d_", node_num);
     strcat(label_name, text);   
     return label_name;
 }
 
 temp_type* NewTemp() {
     temp_type *temp = calloc(sizeof(temp_type),1);
     temp->id = temp_counter;
     temp_counter++;
     return temp;
 }
 
void CG(ast_node root) {
  if (root != NULL) {
    ast_node y = root->left_child;
    while (y != NULL) {
      generate code to prepare for y;
      CG(y);
      y = y->right_sibling;
    }
    generate code to implement root’s action;
  }
}
 
 
 int main() {
     char  *lab_name = NewLabel(543, "ELSE");
     
     printf("%s\n", lab_name);
     
     
     return 0;
 }