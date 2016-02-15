
#include "symtab.h"
#include "string.h"
#include "quad.h"
#include <stdio.h>
#include <stdlib.h>


int temp_counter = 0;
int quad_index = 0;
extern quad_type *quad_array[1024*5];

/* a label is a symnode with the label name, it is inserted into specified hashtable 
    label name takes a form of "__L_%d + text" where %d is from the node_no var in the ast node
    and text is any input string. 
*/
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
 /* returns a temp with name determined by global counter. it is also inserted into the specified hashtable 
    name takes a form of "__T%d" where %d is the global temp counter
 */
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
 
 
 /* makes a quad and then inserts into the quad array. uses global quad arrya and index*/
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
 
 /*pretty print the quad array*/
 void print_quad_array(quad_type **array) {
     printf("There are %d entries\n",quad_index);
     for(int i=0; i < quad_index; i++) {
         printf("%d: ", i);
         printf("(%s, %s, %s, %s)\n",OP_NAME(array[i]->op), array[i]->dest->name, array[i]->src1->name, array[i]->src2->name);
     }
 }
 
 
 
symnode_t CG(ast_node root) {
 
 switch (root->node_type) { 
  case ROOT_N:
    break;
  case SEQ_N:
    break;
  case OP_ASSIGN_N: 
    break;
  case OP_PLUS_N:
    break;
  case OP_MINUS_N:   
    break;
  case OP_NEG_N: 
    break;
  case OP_TIMES_N: 
    break;
  case OP_DIVIDE_N:
    break;
  case OP_EQUALS_N:
    break;
  case IF_STMT_N:
    break;
  case IF_ELSE_STMT_N:
    break;
  case ID_N:
    break;
  case INT_LITERAL_N:
    break;
  case OP_MODULUS_N:
    break;
  case OP_LESS_THAN_N:
    break;
  case OP_LESS_EQUAL_N:
    break;
  case OP_GREATER_THAN_N:
    break;
  case OP_GREATER_EQUAL_N:
    break;
  case OP_NOT_EQUAL_N:
    break;
  case OP_AND_N:
    break;
  case OP_OR_N:
    break;
  case OP_NOT_N:
    break;
  case OP_INCREMENT_N:
    break;
  case OP_DECREMENT_N:
    break;
  case WHILE_N:
    break;
  case DO_WHILE_N:
    break;
  case PRINT_N:
    break;
  case STRING_LITERAL_N:
    break;
  case INT_TYPE_N:
    break;
  case VOID_TYPE_N:
    break;
  case ARRAY_TYPE_N:
    break;
  case FUNCTION_N:
    break;
  case FORMAL_PARAMS_N:
    break;
  case RETURN_N:
    break;
  case READ_N:
    break;
  case FOR_N:
    break;
  case FOR_HEADER_EMPTY_N:
    break;
  case STATEMENT_LIST_N:
    break;
  case LOCAL_DECLARATIONS_N:
    break;
  case CALL_N:
    break;
  case FUNC_DECLARATION_N:
   break;
  default:
   break;
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

