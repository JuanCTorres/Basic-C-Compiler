
#include "symtab.h"
#include "string.h"
#include "quad.h"
#include <stdio.h>
#include <stdlib.h>


int temp_counter = 0;
int quad_index = 0;
extern quad_type *quad_array[1024*5];

// Since quads only take symnodes, need to create one
// for every int that we will use.
symnode_t* true_n = NULL;
symnode_t* false_n = NULL;
symnode_t* elem_size_n = NULL;


//NOTE TO THE READER: "Abandon all hope, ye who enter here."

/* a label is a symnode with the label name, it is inserted into specified hashtable
    label name takes a form of "__L_%d + text" where %d is from the node_no var in the ast node
    and text is any input string.
*/
 symnode_t* NewLabel(ast_node anode, char *text, symhashtable_t *hashtable) {
     char *label_name = calloc(sizeof(char), 100);
     char *label_name_clean = calloc(sizeof(char), 100);

     sprintf(label_name, "__L_%d_", anode->node_no);
     strcat(label_name, text);

     sprintf(label_name_clean, "L_%d_", anode->node_no);
     strcat(label_name_clean, text);

     assert(hashtable != NULL);
     symnode_t *snode = lookup_symhashtable(hashtable, label_name, NOHASHSLOT);

     if(snode == NULL) {
        ast_node new_anode = create_ast_node(LABEL_N);
        assert(new_anode != NULL);
        new_anode->value_string = label_name;
        snode = insert_into_symhashtable(hashtable, new_anode);
        snode->name_clean = label_name_clean;
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
        assert(array[i] != NULL);
        //printf("Currently considering %s\n", OP_NAME(array[i]->op));
        assert(array[i]->dest != NULL);
        printf("%d: ", i);
        printf("(%s, %s, ",OP_NAME(array[i]->op), array[i]->dest->name);
        if (array[i]->src1 != NULL)
          printf("%s, ",array[i]->src1->name);
        else
          printf("-, ");
        if (array[i]->src2 != NULL)
          printf("%s)\n", array[i]->src2->name);
        else
          printf("-)\n");
     }
 }


/*
Main code generation function. Treat carefully
*/
void CG(ast_node x, symhashtable_t *hashtable) {
  //symnode_t temp;
  // Declared here because for some reason
  // you can't declare anything within a switch statement

  symnode_t* label1, *label2, *label3, *label4;

  symnode_t *left_node, *right_node;

  if (x != NULL) {

    ast_node y;
    ast_node z;
    symnode_t *temp, *temp2, *temp3, *temp4;


    /* Recursion pattern depends on the node type
    because sometimes (such as when you see an ifStmt),
    you need to do some things in a weird order (test, come back to if to insert jxx,
    then keep recursing on your other children
    w/o re-evaluating the test you just did)
    */

    switch(x->node_type){

      /* Don't recurse on left child because already
      evaluated (because needed to know results of
      test before putting the jxx statement)*/
      case IF_STMT_N:
        y = x->left_child->right_sibling;
        break;

      /* First two children (test) and what happens if test == true,
        handled before, because labels and jumps must be inserted in the
        middle of these before evaluating the else part of the statement */
      case IF_ELSE_STMT_N:
        y = x->left_child->right_sibling->right_sibling;
        break;

      /* Test before coming back to parent, inserting labels, then
      recursing on the body of the loop */
      case WHILE_N:
        y = x->left_child->right_sibling;
        break;

      /* Similar to while; see above */
      case DO_WHILE_N:
        y = x->left_child->right_sibling;
        break;

      /* Semantically, very similar to while with a tree that looks very
      different. Need to handle that */
      case FOR_N:
        y = x->left_child->right_sibling->right_sibling->right_sibling;
        break;

      /*~~~~~~~ Stopping recursion manually for these because
      short circuiting; handling manually switching on y->node_type
      ~~~~~~~~~*/
      case OP_AND_N:
        y = NULL;
        break;

      case OP_OR_N:
        y = NULL;
        break;

      case OP_NOT_N:
        y = NULL;
        break;

      /* Normal recursion, post-order (visiting children before
      parent nodes), but in-order in code because of left_child,
      right_sibling representation*/
      default:
        y = x->left_child;
        break;
    }

    while (y != NULL) {

      //~~~~~~~ generate code to prepare for y ~~~~~~~~~~~/
      // Two switch statements because handling different
      // node types is better done depending on whether you
      // are in x or in y. Loops, for instance, are better
      // handled when x is the loop node.

      switch(y->node_type){

        case FUNC_DECLARATION_N:
          make_insert_quad(Q_LABEL, y->snode, NULL, NULL);
          break;

        case CALL_N:
          // Function Prologue is caller's responsibility!
          // See after recursion as well.
          //label1 = NewLabel(y, "FUNC_PROLOGUE_BEGIN", hashtable);

          //make_insert_quad(Q_PRECALL, y->left_child->snode, NULL, NULL);

          //make_insert_quad(Q_LABEL, label1, NULL, NULL);
          break;

        // case IF_STMT_N:
        //   label1 = NewLabel(y, "FI", hashtable);
        //   CG(y->left_child, hashtable);
        //   make_insert_quad(Q_IFF, label1, y->left_child->snode, NULL);
        //   break;

        case OP_AND_N:
          // A && B

          temp = NewTemp(hashtable);
          label1 = NewLabel(y, "FALSE", hashtable);
          label2 = NewLabel(y, "DONE", hashtable);

          // Evaluate A, assign to temp
          CG(y->left_child, hashtable);
          temp = NewTemp(hashtable);
          left_node = get_symnode(y->left_child);
          make_insert_quad(Q_ASSIGN, temp, left_node, NULL);

          // Short circuiting: Jump if !A
          make_insert_quad(Q_IFF, label1, temp, NULL);

          // Evaluate B, assign to temp
          CG(y->left_child->right_sibling, hashtable);
          temp2 = NewTemp(hashtable);
          right_node = get_symnode(y->left_child->right_sibling);
          make_insert_quad(Q_ASSIGN, temp2, right_node, NULL);

          // Jump if !B
          make_insert_quad(Q_IFF, label1, temp2, NULL);

          // A && B == True. Assign value, jump to done
          temp3 = NewTemp(hashtable);
          make_insert_quad(Q_ASSIGN, temp3, true_n, NULL);
          make_insert_quad(Q_GOTO, label2, NULL, NULL);

          // A && B == FALSE
          make_insert_quad(Q_LABEL, label1, NULL, NULL);
          make_insert_quad(Q_ASSIGN, temp3, false_n, NULL);

          // Done
          make_insert_quad(Q_LABEL, label2, NULL, NULL);
          y->temp_node = temp3;

          break;

        case OP_OR_N:
          // A || B
          temp = NewTemp(hashtable);
          temp2 = NewTemp(hashtable);
          temp3 = NewTemp(hashtable);
          label1 = NewLabel(y, "TRUE", hashtable);
          label2 = NewLabel(y, "DONE", hashtable);

          // Evaluate A, assign to temp
          CG(y->left_child, hashtable);
          temp2 = NewTemp(hashtable);
          left_node = get_symnode(y->left_child);
          make_insert_quad(Q_ASSIGN, temp, left_node, NULL);
          make_insert_quad(Q_IFT, label1, temp, NULL);

          // Evaluate B, assign to temp
          CG(y->left_child->right_sibling, hashtable);
          right_node = get_symnode(y->left_child->right_sibling);
          make_insert_quad(Q_ASSIGN, temp2, right_node, NULL);
          make_insert_quad(Q_IFT, label1, temp, NULL);

          // A || B == False
          make_insert_quad(Q_ASSIGN, temp3, false_n, NULL);
          make_insert_quad(Q_GOTO, label2, NULL, NULL);

          // A || B == True
          make_insert_quad(Q_LABEL, label1, NULL, NULL);
          make_insert_quad(Q_ASSIGN, temp3, true_n, NULL);

          // Done
          make_insert_quad(Q_LABEL, label2, NULL, NULL);
          y->temp_node = temp3;
          break;

        case OP_NOT_N:
          // !A
          label1 = NewLabel(y, "FALSE", hashtable);
          label2 = NewLabel(y, "DONE", hashtable);
          temp = NewTemp(hashtable);
          temp2 = NewTemp(hashtable);

          // Eval A, assign temp to it.
          CG(y->left_child, hashtable);
          left_node = get_symnode(y->left_child);
          make_insert_quad(Q_ASSIGN, temp, left_node,  NULL);

          // Jump?
          make_insert_quad(Q_IFF, label1, temp, NULL);

          // A = true
          make_insert_quad(Q_ASSIGN, temp2, false_n, NULL);
          make_insert_quad(Q_GOTO, label2, NULL, NULL);

          // A = false
          make_insert_quad(Q_LABEL, label1, NULL, NULL);
          make_insert_quad(Q_ASSIGN, temp2, true_n, NULL);

          // Done
          make_insert_quad(Q_LABEL, label2, NULL, NULL);

          // Set boolean value
          y->temp_node = temp2;
          break;

        /*~~~~~~~ Comparations better handled after recursing on children and we
        are back on X ~~~~~~~*/

        default:
          break;
      }

      /* Control statements are better handled by switching on the node type
      of x, because we'll need some labels created before evaluating some of the
      children nodes. Switching on y->node_type would mean we would not have access
      to such labels when evaluating the relevant node after recursing on its children
      (since the current node, by then, would be x, and the labels created here
      would be inaccesssible by then) */
      switch (x->node_type) {

        case IF_STMT_N:
          label1 = NewLabel(x, "FI", hashtable);
          temp = NewTemp(hashtable);
          // Execute test code first
          CG(x->left_child, hashtable);
          // Assign to temp to avoid destruction
          left_node = get_symnode(x->left_child);
          make_insert_quad(Q_ASSIGN, temp, left_node, NULL);
          // Conditional jump
          make_insert_quad(Q_IFF, label1, temp, NULL);
          break;

        case IF_ELSE_STMT_N:
          // else

          label1 = NewLabel(x, "ELSE", hashtable);
          // fi
          label2 = NewLabel(x, "FI", hashtable);
          temp = NewTemp(hashtable);

          // test
          CG(x->left_child, hashtable);
          left_node = get_symnode(x->left_child);
          make_insert_quad(Q_ASSIGN, temp, left_node, NULL);

          make_insert_quad(Q_IFF, label1, temp, NULL);
          // if
          CG(x->left_child->right_sibling, hashtable);
          make_insert_quad(Q_GOTO, label2, NULL, NULL);
          make_insert_quad(Q_LABEL, label1, NULL, NULL); // else label
          // else
          break;

        case WHILE_N:

          label1 = NewLabel(x, "WHILE_BEGIN", hashtable);
          label2 = NewLabel(x, "WHILE_END", hashtable);
          // Beginning of loop
          make_insert_quad(Q_LABEL, label1, NULL, NULL);
          // Test
          CG(x->left_child, hashtable);
          left_node = get_symnode(x->left_child);
          make_insert_quad(Q_IFF, label2, left_node, NULL);
          break;

        case DO_WHILE_N:

          label1 = NewLabel(x, "DO_WHILE_BEGIN", hashtable);
          // Beginning of loop
          make_insert_quad(Q_LABEL, label1, NULL, NULL);
          break;

        case FOR_N:
          // For is pretty much while with an Initialization, and a
          // change after the inside statement.
          // The C Programming Language 2nd Ed., p. 60
          label1 = NewLabel(x, "FOR_BEGIN", hashtable);
          label2 = NewLabel(x, "FOR_END", hashtable);
          // Initialization
          CG(x->left_child, hashtable);
          // Beginning of while loop
          make_insert_quad(Q_LABEL, label1, NULL, NULL);
          // Loop invariant
          CG(x->left_child->right_sibling, hashtable);
          right_node = get_symnode(x->left_child->right_sibling);
          make_insert_quad(Q_IFF, label2, right_node, NULL);
          break;

        default:
          break;
      }

      // if(x->node_type == FUNCTION_N){
      //   printf("Yep. x is func, y is null\n");
      // }
      /*~~~~~~~~~~~~~ Generate node for child ~~~~~~~~~~~~~~~~~*/
      CG(y, hashtable);
      /*~~~~~~~~~~~~~~~~~~~~ Go to sibling ~~~~~~~~~~~~~~~~~~~~*/
      y = y->right_sibling;

    }


    /*~~~~~~~~ generate code to implement x’s action ~~~~~~~~*/
    switch (x->node_type){

      /*~~~~~~~ Binary ops ~~~~~~~~~*/

      case OP_ASSIGN_N:
        // No need for temps, variable should have been declared before
        if(x->left_child->node_type == ARRAY_TYPE_N){
          left_node = get_array_slot_addr(x->left_child, hashtable);
        } else{
          left_node = get_symnode(x->left_child);
        }

        if(x->left_child->right_sibling->node_type == ARRAY_TYPE_N){
          right_node = get_array_slot_val(x->left_child->right_sibling, hashtable);
        } else{
          right_node = get_symnode(x->left_child->right_sibling);
        }

        // left_node = get_symnode(x->left_child);
        //right_node = get_symnode(x->left_child->right_sibling);

        //make_insert_quad(Q_ASSIGN, x->left_child->temp_node, x->left_child->right_sibling->temp_node, NULL);
        make_insert_quad(Q_ASSIGN, left_node, right_node, NULL);

        //left_node = get_symnode(x->left_child);
        x->temp_node = left_node;
        break;

      case OP_PLUS_N:
        insert_binary_op_quad(x, Q_ADD, hashtable);
        break;

      case OP_MINUS_N:
        insert_binary_op_quad(x, Q_SUB, hashtable);
        break;

      case OP_TIMES_N:
        insert_binary_op_quad(x, Q_MULT, hashtable);
        break;

      case OP_DIVIDE_N:
        insert_binary_op_quad(x, Q_DIV, hashtable);
        break;

      case OP_MODULUS_N:
        insert_binary_op_quad(x, Q_MOD, hashtable);
        break;

      /*~~~~~~~~~ Comparators ~~~~~~~~~*/

      case OP_EQUALS_N:
        temp = NewTemp(hashtable);
        temp2 = NewTemp(hashtable);
        temp3 = NewTemp(hashtable);
        label1 = NewLabel(x, "TRUE", hashtable);
        label2 = NewLabel(x, "DONE", hashtable);

        // Is either greater?
        left_node = get_symnode(x->left_child);
        right_node = get_symnode(x->left_child->right_sibling);
        temp = left_node;
        temp2 = right_node;

        //make_insert_quad(Q_JEQ, label1, NULL, NULL);
        make_insert_quad(Q_EQ, temp3, temp, temp2);
        make_insert_quad(Q_IFT, label1, temp3, NULL);

        // False
        make_insert_quad(Q_ASSIGN, temp3, false_n, NULL);
        make_insert_quad(Q_GOTO, label2, NULL, NULL);

        // True
        make_insert_quad(Q_LABEL, label1, NULL, NULL);
        make_insert_quad(Q_ASSIGN, temp3, true_n, NULL);

        // Done
        make_insert_quad(Q_LABEL, label2, NULL, NULL);

        x->temp_node = temp3;
        break;

      case OP_LESS_THAN_N:
        temp = NewTemp(hashtable);
        temp2 = NewTemp(hashtable);
        temp3 = NewTemp(hashtable);
        label1 = NewLabel(x, "TRUE", hashtable);
        label2 = NewLabel(x, "DONE", hashtable);

        // Is either smaller?
        left_node = get_symnode(x->left_child);
        right_node = get_symnode(x->left_child->right_sibling);
        temp = left_node;
        temp2 = right_node;

        make_insert_quad(Q_LT, temp3, temp, temp2);
        make_insert_quad(Q_IFT, label1, temp3, NULL);

        // False
        make_insert_quad(Q_ASSIGN, temp3, false_n, NULL);
        make_insert_quad(Q_GOTO, label2, NULL, NULL);

        // True
        make_insert_quad(Q_LABEL, label1, NULL, NULL);
        make_insert_quad(Q_ASSIGN, temp3, true_n, NULL);

        // Done
        make_insert_quad(Q_LABEL, label2, NULL, NULL);

        x->temp_node = temp3;
        break;

      case OP_LESS_EQUAL_N:
        temp = NewTemp(hashtable);
        temp2 = NewTemp(hashtable);
        temp3 = NewTemp(hashtable);
        label1 = NewLabel(x, "TRUE", hashtable);
        label2 = NewLabel(x, "DONE", hashtable);

        // LEQ?
        left_node = get_symnode(x->left_child);
        right_node = get_symnode(x->left_child->right_sibling);
        temp = left_node;
        temp2 = right_node;

        make_insert_quad(Q_LTEQ, temp3, temp, temp2);
        make_insert_quad(Q_IFT, label1, temp3, NULL);

        // False
        make_insert_quad(Q_ASSIGN, temp3, false_n, NULL);
        make_insert_quad(Q_GOTO, label2, NULL, NULL);

        // True
        make_insert_quad(Q_LABEL, label1, NULL, NULL);
        make_insert_quad(Q_ASSIGN, temp3, true_n, NULL);

        // Done
        make_insert_quad(Q_LABEL, label2, NULL, NULL);

        x->temp_node = temp3;
        break;

      case OP_GREATER_THAN_N:
        temp = NewTemp(hashtable);
        temp2 = NewTemp(hashtable);
        temp3 = NewTemp(hashtable);
        label1 = NewLabel(x, "TRUE", hashtable);
        label2 = NewLabel(x, "DONE", hashtable);

        // GT?
        left_node = get_symnode(x->left_child);
        right_node = get_symnode(x->left_child->right_sibling);
        temp = left_node;
        temp2 = right_node;

        make_insert_quad(Q_GT, temp3, temp, temp2);
        make_insert_quad(Q_IFT, label1, temp3, NULL);

        // False
        make_insert_quad(Q_ASSIGN, temp3, false_n, NULL);
        make_insert_quad(Q_GOTO, label2, NULL, NULL);

        // True
        make_insert_quad(Q_LABEL, label1, NULL, NULL);
        make_insert_quad(Q_ASSIGN, temp3, true_n, NULL);

        // Done
        make_insert_quad(Q_LABEL, label2, NULL, NULL);

        x->temp_node = temp3;
        break;

      case OP_GREATER_EQUAL_N:
        temp = NewTemp(hashtable);
        temp2 = NewTemp(hashtable);
        temp3 = NewTemp(hashtable);
        label1 = NewLabel(x, "TRUE", hashtable);
        label2 = NewLabel(x, "DONE", hashtable);

        // GEQ?
        left_node = get_symnode(x->left_child);
        right_node = get_symnode(x->left_child->right_sibling);
        temp = left_node;
        temp2 = right_node;

        make_insert_quad(Q_GTEQ, temp3, temp, temp2);
        make_insert_quad(Q_IFT, label1, temp3, NULL);

        // False
        make_insert_quad(Q_ASSIGN, temp3, false_n, NULL);
        make_insert_quad(Q_GOTO, label2, NULL, NULL);

        // True
        make_insert_quad(Q_LABEL, label1, NULL, NULL);
        make_insert_quad(Q_ASSIGN, temp3, true_n, NULL);

        // Done
        make_insert_quad(Q_LABEL, label2, NULL, NULL);

        x->temp_node = temp3;
        break;

      case OP_NOT_EQUAL_N:
        temp = NewTemp(hashtable);
        temp2 = NewTemp(hashtable);
        temp3 = NewTemp(hashtable);
        label1 = NewLabel(x, "TRUE", hashtable);
        label2 = NewLabel(x, "DONE", hashtable);

        // NEQ?
        left_node = get_symnode(x->left_child);
        right_node = get_symnode(x->left_child->right_sibling);
        temp = left_node;
        temp2 = right_node;;

        make_insert_quad(Q_NEQ, temp3, temp, temp2);
        make_insert_quad(Q_IFT, label1, temp3, NULL);

        // False
        make_insert_quad(Q_ASSIGN, temp3, false_n, NULL);
        make_insert_quad(Q_GOTO, label2, NULL, NULL);

        // True
        make_insert_quad(Q_LABEL, label1, NULL, NULL);
        make_insert_quad(Q_ASSIGN, temp3, true_n, NULL);

        // Done
        make_insert_quad(Q_LABEL, label2, NULL, NULL);

        x->temp_node = temp3;
        break;

      /*~~~~~ Unary operations ~~~~~~~*/
      //<TODO> GOTTA FIX THESE!!!!

      case OP_NEG_N:
        temp = NewTemp(hashtable);
        assert(temp != NULL);
        symnode_t *node = get_symnode(x->left_child);
        assert(node != NULL);

        left_node = get_symnode(x->left_child);
        make_insert_quad(Q_NEG, temp, left_node, NULL);
        x->temp_node = temp;
        break;

      case OP_INCREMENT_N:
        temp = NewTemp(hashtable);
        left_node = get_symnode(x->left_child);
        make_insert_quad(Q_INC, temp, left_node, NULL);
        x->temp_node = temp;
        break;

      case OP_DECREMENT_N:
        temp = NewTemp(hashtable);
        left_node = get_symnode(x->left_child);
        make_insert_quad(Q_DEC, temp, left_node, NULL);
        x->temp_node = temp;
        break;

      /*~~~~~~~ Control Statements ~~~~~~*/

      case IF_STMT_N:
        make_insert_quad(Q_LABEL, label1, NULL, NULL);
        break;

      case IF_ELSE_STMT_N:
        make_insert_quad(Q_LABEL, label2, NULL, NULL); // fi label
        break;

      case WHILE_N:
        make_insert_quad(Q_GOTO, label1, NULL, NULL);
        make_insert_quad(Q_LABEL, label2, NULL, NULL);
        break;

      case DO_WHILE_N:
        CG(x->left_child, hashtable);
        left_node = get_symnode(x->left_child);
        make_insert_quad(Q_IFT, label1, left_node, NULL);
        break;

      case FOR_N:
        CG(x->left_child->right_sibling->right_sibling, hashtable);
        make_insert_quad(Q_GOTO, label1, NULL, NULL);
        make_insert_quad(Q_LABEL, label2, NULL, NULL);
        break;

      case FOR_HEADER_EMPTY_N:
        // <TODO> Anything here? Probably not?
        temp = NewTemp(hashtable);
        make_insert_quad(Q_ASSIGN, temp, true_n, NULL);
        x->temp_node = temp;
        break;

      case PRINT_N:
        left_node = get_symnode(x->left_child);
        //make_insert_quad(Q_PRINT, x->left_child->temp_node, NULL, NULL);
        make_insert_quad(Q_PRINT, left_node, NULL, NULL);
        break;

      case READ_N:
        left_node = get_symnode(x->left_child);
        //make_insert_quad(Q_READ, x->left_child->temp_node, NULL, NULL);
        make_insert_quad(Q_READ, left_node, NULL, NULL);
        break;

      case ARRAY_TYPE_N:
      //   temp = NewTemp(hashtable);
      //   temp2 = NewTemp(hashtable);
      //   temp3 = NewTemp(hashtable);
      //   temp4 = NewTemp(hashtable);
      //
      //   left_node = get_symnode(x->left_child);
      //
      //   // Calculate offset into array chunk in memory
      //   make_insert_quad(Q_MULT, temp, left_node, elem_size_n);
      //   // Grab the address of array
      //   left_node = get_symnode(x);
      //   make_insert_quad(Q_ADDR, temp2, left_node, NULL);
      //   // And add the offset to it
      //   make_insert_quad(Q_ADD, temp3, temp, temp2);
      //   // Grab the element
      //   make_insert_quad(Q_DEREF, temp4, temp3, NULL);
      //
      //   x->temp_node = temp4;
        break;

      case RETURN_N:
        left_node = get_symnode(x->left_child);
        assert(left_node != NULL);
        if(x->left_child != NULL){
          make_insert_quad(Q_RETURN, left_node, NULL, NULL);
          //make_insert_quad(Q_RETURN, x->left_child->temp_node, NULL, NULL);
        } else{
          //symnode_t * empty_return = create_symnode("empty_return", hashtable);
          //empty_return->type = VOID_RET_T;
          //make_insert_quad(Q_RETURN, NULL, NULL, NULL);
        }
        break;

      case FUNC_DECLARATION_N:
        // Might need to change in the future
        break;

      case CALL_N:
        // Function epilogue
        //label2 = NewLabel(x, "FUNC_EPILOGUE", hashtable);
        //make_insert_quad(Q_LABEL, label2, NULL, NULL);
        left_node = get_symnode(x->left_child);
        make_insert_quad(Q_POSTCALL, left_node, NULL, NULL);
        x->temp_node = create_symnode("__RET_INT", NULL);
        break;

      case FUNCTION_N:
        // Push arguments
        for(z = x->left_child; z != NULL; z = z->right_sibling){
          temp = NewTemp(hashtable);
          left_node = get_symnode(z);
          make_insert_quad(Q_ASSIGN, temp, left_node, NULL);
          make_insert_quad(Q_PUSH, temp, NULL, NULL);
        }
        // Precall
        left_node = get_symnode(x);
        make_insert_quad(Q_PRECALL, left_node, NULL, NULL);
        // Function call
        make_insert_quad(Q_CALL, left_node, NULL, NULL);
        break;

      case FORMAL_PARAMS_N:
        // Don't think anything is necessary in here,
        // Maybe in the future
        break;

      default:
        break;
    }
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
      break;
  }

  printf("\n");


  }
}


/*~~~~~~~~~~~~~~~~~ Helper functions ~~~~~~~~~~~~~~~~*/


void set_constants(symhashtable_t *hashtable){

  ast_node node0 = create_ast_node(INT_LITERAL_N);
  char *name = calloc(100, sizeof(char));
  sprintf(name, "__%d", 1);
  node0->value_string = name;
  node0->value_int = 1;
  true_n = lookup_symhashtable(hashtable, name, NOHASHSLOT);
  if(true_n == NULL){
    true_n = insert_into_symhashtable(hashtable, node0);
  }

  ast_node node1 = create_ast_node(INT_LITERAL_N);
  name = calloc(100,  sizeof(char));
  sprintf(name, "__%d", 0);
  node1->value_string = name;
  node1->value_int = 0;
  false_n = lookup_symhashtable(hashtable, name, NOHASHSLOT);
  if(true_n == NULL){
    true_n = insert_into_symhashtable(hashtable, node1);
  }

  ast_node node2 = create_ast_node(INT_LITERAL_N);
  name = calloc(100, sizeof(char));
  sprintf(name, "__%d", ELEMSIZE);
  node2->value_string = name;
  node2->value_int = ELEMSIZE * 2;
  elem_size_n = lookup_symhashtable(hashtable, name, NOHASHSLOT);
  if(elem_size_n == NULL){
    elem_size_n = insert_into_symhashtable(hashtable, node2);
  }
}

symnode_t *get_symnode(ast_node anode){
  if(anode->snode == NULL){
    return anode->temp_node;
  }
  else{
    return anode->snode;
  }
}

void insert_binary_op_quad(ast_node anode, quad_op_type quad_op, symhashtable_t *hashtable){
    symnode_t *temp, *temp2, *temp3, *temp4, *temp5, *temp6, *temp7, *temp8, *temp9;
    symnode_t *left_node, *right_node;
    symnode_t *left_index, *right_index;
    symnode_t *left_arr, *right_arr;

    left_node = get_symnode(anode->left_child);
    right_node = get_symnode(anode->left_child->right_sibling);

    //left_arr = get_array_slot_val(anode->left_child, hashtable);
    // right_arr = get_array_slot_val(anode->left_child->right_sibling, hashtable);


     //<TODO> anode->left_child->snode->is_array

    if(anode->left_child->node_type == ARRAY_TYPE_N){
      left_arr = get_array_slot_val(anode->left_child, hashtable);
    //   temp = NewTemp(hashtable);
    //   temp2 = NewTemp(hashtable);
    //   temp3 = NewTemp(hashtable);
    //   temp4 = NewTemp(hashtable);
    //
    //   // What index of the array are we looking for?
    //   left_index = get_symnode(anode->left_child->left_child);
    //
    //   make_insert_quad(Q_MULT, temp, left_index, elem_size_n);
    //   make_insert_quad(Q_ADDR, temp2, left_node, NULL);
    //
    //   // Global array addresses grow up as their slots grow up,
    //   // local ones do the opposite.
    //   if(is_var_global(anode->left_child->snode)){
    //     make_insert_quad(Q_ADD, temp3, temp2, temp);
    //   }
    //   else{
    //     make_insert_quad(Q_SUB, temp3, temp2, temp);
    //   }
    //
    //   // Actual value of array[something]
    //   make_insert_quad(Q_DEREF, temp4, temp3, NULL);
    }

    if(anode->left_child->right_sibling->node_type == ARRAY_TYPE_N){
      right_arr = get_array_slot_val(anode->left_child->right_sibling, hashtable);
    //   temp5 = NewTemp(hashtable);
    //   temp6 = NewTemp(hashtable);
    //   temp7 = NewTemp(hashtable);
    //   temp8 = NewTemp(hashtable);
    //
    //   // What index of the array are we looking for?
    //   right_index = get_symnode(anode->left_child->right_sibling->left_child);
    //   make_insert_quad(Q_MULT, temp5, right_index, elem_size_n);
    //   // temp6 will hold the address of right array.
    //   make_insert_quad(Q_ADDR, temp6, right_node, NULL);
    //
    //   // Global array addresses grow up as their slots grow up,
    //   // local ones do the opposite.
    //   if(is_var_global(anode->left_child->snode)){
    //     make_insert_quad(Q_ADD, temp7, temp6, temp5);
    //   }
    //   else{
    //     make_insert_quad(Q_SUB, temp7, temp6, temp5);
    //   }
    //
    //   // Actual value of array[something]
    //   make_insert_quad(Q_DEREF, temp8, temp7, NULL);
    }

    temp9 = NewTemp(hashtable);

    if(anode->left_child->node_type == ARRAY_TYPE_N){
      if(anode->left_child->right_sibling->node_type == ARRAY_TYPE_N){ // array + array
        // make_insert_quad(quad_op, temp9, temp4, temp8);
        make_insert_quad(quad_op, temp9, left_arr, right_arr);
      }
      else{               // array + num
        //make_insert_quad(quad_op, temp9, temp4, right_node);
        make_insert_quad(quad_op, temp9, left_arr, right_node);
      }
    }
    else{
      if(anode->left_child->right_sibling->node_type == ARRAY_TYPE_N){ // num + array
        //make_insert_quad(quad_op, temp9, left_node, temp8);
        make_insert_quad(quad_op, temp9, left_node, right_arr);
      }
      else{               // num + num
        make_insert_quad(quad_op, temp9, left_node, right_node);
      }
    }

    anode->temp_node = temp9;
}


/*
   Returns a temporary node holding the _address_ of the array at the index specified
   as the left child of anode in the abstract syntax tree.
*/
symnode_t *get_array_slot_addr(ast_node anode, symhashtable_t *hashtable){
  symnode_t *temp, *temp2, *temp3, *temp4;
  symnode_t *index;
  symnode_t *symnode = get_symnode(anode);

  temp = NewTemp(hashtable);
  temp2 = NewTemp(hashtable);
  temp3 = NewTemp(hashtable);
  temp4 = NewTemp(hashtable);

  // What index of the array are we looking for?
  index = get_symnode(anode->left_child);

  make_insert_quad(Q_MULT, temp, index, elem_size_n);
  make_insert_quad(Q_ADDR, temp2, symnode, NULL);


  if(is_var_global(anode->snode)){
    make_insert_quad(Q_ADD, temp3, temp2, temp);
  }
  else{
    make_insert_quad(Q_SUB, temp3, temp2, temp);
  }

  temp3->is_array = 1; // We need to treat this differently later.
  return temp3;
}

/*
   Returns a temporary node holding the _value_ of the array at the index specified
   as the left child of anode in the abstract syntax tree.
*/
symnode_t *get_array_slot_val(ast_node anode, symhashtable_t *hashtable){
  symnode_t *temp, *temp2;

  temp2 = NewTemp(hashtable);

  temp = get_array_slot_addr(anode, hashtable);
  make_insert_quad(Q_DEREF, temp2, temp, NULL);

  return temp2;
}


/* Returns 1 if var is global, i.e., was declared in scope (0-0)*/
int is_var_global(symnode_t *var){
  if(var->abnode->curr_level == 0 && var->abnode->curr_sib == 0){
    return 1;
  } else{
    return 0;
  }
}
