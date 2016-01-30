# Symbols and types: Top-down

In this part of our compiler, we traverse the syntax tree created in previous steps of our project, and start creating symbol tables to store declared variable and function names, so that we know in the future whether a particular name has been defined.

## Authors
- SeokJun Bing
- Juan C. Torres

Some code provided by Sean W. Smith, some originally written by Thomas Cormen.

## How to build and run

- Execute make to build the program, make clean to delete object files and other executable files.

- Execute make test to build the program and run relevant tests. The folder testinputs contains several example programs written in our C grammar, a subset of the full C grammar. Our test script should produce one file {testfile}.output.{date} with the results of each test.

## Program execution

- symtab.c and symtab.h define the data structures and functions required to build the symbol tables.

- parser.l is a flex specification so that flex returns the next token from the input stream and returns other relevant information to the creation of a parse tree, such as string and int values.

- parser.y is a bison file, including a grammar and executable code. Each production in the grammar is accompanied by some code used to build a parse tree.

- ast.c and ast.h define the relevant data structures and functions needed to build a parse tree.


The program traverses the syntax tree created in previous steps in a top-down manner. Starting at the root, it uses a pre-order walk to discover function and variable declarations, and adds them to the appropriate scope. The scope that a particular symbol belongs is defined as follows:

- Any particular scope is identified by a tuple of two numbers: (*n*, *m*), defined as follows:
	- *n* is defined as the level of any particular scope, 0 being the global level. Subsequent levels increase by one. Any scope that is contained by another scope will have a higher level number. For instance, if a function *my_func* is defined in the global scope (level 0), the variables inside such function would be in level 1. If, then, there is another scope inside *my_func*, the variables inside that scope would be in level 2.

	- *m* is defined as the sibling identifier, and is used to differentiate between different scopes on the same level. For instance, if two different *if* statements are found inside a function at level (1, 0), two new scopes would be defined with levels (2, *s*), (2, *s + 1*).


- The particular tuple of new scopes is determined as follows:

	- When a compound statement is found in our program (as defined in our grammar, though it could be understood as basically any statement inside braces), the level *n* is increased by 1. This because any identifiers found inside the compound statement will be local to that compound statement. They can't be accessed outside the compound statement, but they can access the identifiers defined in any parent scopes.
	- After a compound statement is found, the sibling identifier *m* is also increased. This to make sure that if any more compound statements are found on the same level, they will create different scopes. For instance:

	```
		int func_one(){
			...    // scope (m, n)
		}
		int func_two(){
			...    // scope (m, n + 1)
		}
	```

- It is important to keep in mind that the particular identifier of a scope does not determine its children or its parent. For instance, the two following diagrams illustrate two different possible scope hierarchies that use the same scope identifiers:
  ```
  Diagram 1

         ...
    /          \
 (1, 0)        (1, 1)
  /   \           |
(2, 0) (2, 1)    (2, 2)

  ```
  ```
  Diagram 2

        ...
    /         \     
(1, 0)      (1, 1)
   |         /     \
(2, 0)   (2, 1)  (2, 2)
```

- In order to determine the hierarchical relations between different scopes, we build a tree that specifies these relations, as follows:

  - As a scope (*m*, *n*) is created, it is linked to its parent, identified as the scope whose level is *m - 1* (any scope with level 2 will have to be linked to a scope with level 1), and whose sibling identifier is the maximum of the sibling identifiers for its parent level. For instance, if we have the scopes
  `{..., (2, 0), (2, 1), (2, 2), (3, 0)}`
  and we create a new scope `(3, 1)`, its parent would be the scope `(2, 2)`, as scopes `(2, 0)` and `(2, 1)` are already closed and it is clear that our scope is a sub-scope of the latest scope with level 2 to be opened. See the following annotated code for clarification:
  ```
  for(...){
       ...       // scope (2, 0)
  }
  while(...){
       ...       // scope (2, 1)
       for(...){
          ...    // scope (3, 0)
        }
  }
  if(...){
       ...      // scope (2, 2)
       if(...){ // scope (3, 1)
       }
  }
    ```

  - Scope `(3, 1)` is a child of scope `(2, 2)`, since scope `(2, 2)` is the latest scope of level 2 to be opened. Clearly, scopes `(2, 0)` and `(2, 1)` are already closed (since there is a scope with the same level and a higher sibling identifier), and could not have created scope `(3, 1)`.

## Notes about the program

1. We have assumed that the tree will be traversed using a preoder walk, and have tailored our tree so that code generation is easier on future steps. For instance, a for loop is created so that with a preorder walk we would see the initialization, test condition, and iteration stataments in that order, before moving to the body of the loop.

2. We have decided to maintain some extra information in order to preserve condition 1 and make future code generation easier. For instance, a compound statement in our grammar requires that local variables be defined before other executable code (compound-statement -> local-declarations statement-list). In the case that no local variables are defined, we could have not created a node for local-declarations, but this would have made complying with condition 1 harder, as we would have had to handle a special case of pointer manipulation. We have, then, kept an empty node in here to facilitate future code generation easier, as well as facilitate our compliance with condition 1.

## Changes from previous programs

- Fixed bug where parser would not see all the variables if the declarations contained an assignment. 
