
#include "symtab.h"
#include "string.h"
#include "quad.h"
#include <stdio.h>
#include <stdlib.h>


int temp_counter = 0;
int quad_index = 0;
extern quad_type *quad_array[1024*5];

/* a label is a symnode with the label name, it is inserted into specified hashtable */
 symnode_t* NewLabel(ast_node anode, char *text, symhashtable_t *hashtable) {
     char *label_name = calloc(sizeof(char), 100);
     sprintf(label_name, "__L_%d_", anode->node_no);
     strcat(label_name, text);
     
     assert(hashtable != NULL);
     symnode_t *snode = lookup_symhashtable(hashtable, label_name, NOHASHSLOT);
     
     if(snode == NULL) {
        ast_node new_anode = create_ast_node(LABEL_N);
        assert(new_anode != NULL);
        new_anode->value_string = label_name;
        snode = insert_into_symhashtable(hashtable, new_anode);
        assert(snode != NULL);
     }
     else {
         fprintf(stderr, "\n\nLABEL OVERLAP FOR SOME REASON!\n\n");
     }
     
     return snode;
 }
 /* returns a temp with name determined by global counter. it is also inserted into the specified hashtable */
 symnode_t* NewTemp(symhashtable_t *hashtable) {
     char *temp_name = calloc(sizeof(char), 100);
     sprintf(temp_name, "__T%d", temp_counter);
     
     ast_node anode = create_ast_node(TEMP_N);
     assert(anode != NULL);
     anode->value_string = temp_name;
     symnode_t *snode = insert_into_symhashtable(hashtable, anode);
     assert(snode != NULL);
     snode->num_val = temp_counter;
     temp_counter++;
     return snode;
 }
 
 
 
 void make_insert_quad(quad_op_type op, symnode_t *dest, symnode_t *src1, symnode_t *src2) {
     quad_type *quad = calloc(sizeof(quad_type), 1);
     assert(quad != NULL);
     quad->op = op;
     quad->dest = dest;
     quad->src1 = src1;
     quad->src2 = src2;
     
     quad_array[quad_index] = quad;
     
     quad_index++;
 }
 
 
 void print_quad_array(quad_type **array) {
     
     printf("There are %d entries\n",quad_index);
     for(int i=0; i < quad_index; i++) {
         printf("%d: ", i);
         printf("(%s, %s, %s, %s)\n",OP_NAME(array[i]->op), array[i]->dest->name, array[i]->src1->name, array[i]->src2->name);
     }
     
 }
 
 
 
 
void preorder_print(ast_node root) {
  

  if (root != NULL) {
    ast_node y = root->left_child;
    while (y != NULL) {
    //   generate code to prepare for y;
      preorder_print(y);
      y = y->right_sibling;
    }
    // generate code to implement root’s action;

    printf("%s (uid: N%d) ", NODE_NAME(root->node_type), root->node_no);

    switch (root->node_type) {
    case SEQ_N:     // change main level when see a new sequence
      // lvl++;
      break;

    case FORMAL_PARAMS_N:
      // lvl++;
      // printf("[in scope: (%d,%d) | child of (%d,%d)]", lvl, sublvl, MAX(lvl - 1, 0), siblings[lvl - 1]);
      // printf("[in scope: (%d,%d) | child of (%d,%d)]", root->curr_level, root->curr_sib, root->parent_level, root->parent_sib);

      break;

    case ARRAY_TYPE_N:
      printf("%s ", root->value_string);
      if(root->return_type != 0) {
        // printf(" (type: %s)", NODE_NAME(root->return_type));
      }
      // printf("[in scope: (%d,%d) | child of (%d,%d)]", lvl, sublvl, MAX(lvl - 1, 0), siblings[lvl - 1]);
      printf("[scope (%d,%d) <- (%d,%d)]", root->curr_level, root->curr_sib, root->parent_level, root->parent_sib);
      printf(" declared at line %d ", root->line_declared);
      break;

    case FUNCTION_N:
      printf("%s ", root->value_string);
      if(root->return_type != 0) {
        // printf(" (type: %s)", NODE_NAME(root->return_type));
      }
      int i = 0;
      ast_node anode;
      for(anode = root->left_child; anode != NULL; anode = anode->right_sibling) {
        i++;
      }
      printf(" (%d params:", i);
      for(anode = root->left_child; anode != NULL; anode = anode->right_sibling) {
        printf(" %s", NODE_NAME(root->return_type));
      }
      printf(")");
      // printf("[in scope: (%d,%d) | child of (%d,%d)]", lvl, sublvl, MAX(lvl - 1, 0), siblings[lvl - 1]);
      printf("[scope (%d,%d) <- (%d,%d)]", root->curr_level, root->curr_sib, root->parent_level, root->parent_sib);
      printf(" declared at line %d ", root->line_declared);
      break;

    case STRING_LITERAL_N:
      printf("%s ", root->value_string);
      break;

    case ID_N:      /* print the id */
      printf("%s ", root->value_string);
      if(root->return_type != 0) {
        // printf(" (type: %s)", NODE_NAME(root->return_type));
      }
      // printf("[in scope: (%d,%d) | child of (%d,%d)]", lvl, sublvl, MAX(lvl - 1, 0), siblings[lvl - 1]);
      printf("[scope (%d,%d) <- (%d,%d)]", root->curr_level, root->curr_sib, root->parent_level, root->parent_sib);
      printf(" declared at line %d ", root->line_declared);
      break;

    case INT_LITERAL_N:   /* print the int literal */
      printf("%d", root->value_int);
      // printf(" (type: %s)", NODE_NAME(root->return_type));
      break;

    case FUNC_DECLARATION_N:
      printf("%s ", root->value_string);
      assert(root->return_type != 0);
      // if(root->return_type != 0) {
        // printf(" (type: %s)", NODE_NAME(root->return_type));
      // }
      printf(" (%d params:", root->snode->num_parameters);
      for(int k = 0; k < root->snode->num_parameters; k++) {
        printf(" %s ", TYPE_NAME(root->snode->parameters[k]));
      }
      printf(")");
      // printf("[in scope: (%d,%d) | child of (%d,%d)]", lvl, sublvl, MAX(lvl - 1, 0), siblings[lvl - 1]);
      printf("[scope (%d,%d) <- (%d,%d)]", root->curr_level, root->curr_sib, root->parent_level, root->parent_sib);
      printf(" declared at line %d ", root->line_declared);
      break;

    case RETURN_N:
      // printf("[in scope: (%d,%d) | child of (%d,%d)]", lvl, sublvl, MAX(lvl - 1, 0), siblings[lvl - 1]);
      printf("[scope (%d,%d) <- (%d,%d)]", root->curr_level, root->curr_sib, root->parent_level, root->parent_sib);
      printf("return to %s at line %d ", root->return_to->value_string, root->return_to->line_declared);
      break;

    default:
      //printf("at default of switch\n");
      break;
  }

  printf("\n");


  }
}
 
 
//  int main() {

    //  symboltable_t *symtable = create_symboltable(); //0,0 lvl created as well
    //  symtable->root;
     
    //  ast_node anode = create_ast_node(TEMP_N);
     
    //  symnode_t *snode1 = NewLabel(anode, "test_label_lolz", symtable->root);
     
    //  printf("\nname of label: %s\n",snode1->name);
     
    //  symnode_t *snode2 = NewTemp(symtable->root);
     
    //  printf("\nname of temp: %s, the int count is %d\n",snode2->name, snode2->num_val);
     
    //  symnode_t *snode3, *snode4, *snode5;
     
    //  snode3 = create_symnode("yolo", symtable->root);
    //  snode4 = create_symnode("hobo", symtable->root);
    //  snode5 = create_symnode("imho", symtable->root);
     
    //  make_insert_quad(Q_ASSIGN, snode3 ,snode4, snode5);
    //  print_quad_array(quad_array);
     
     
    //  return 0;
//  }

