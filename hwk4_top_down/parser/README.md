# Symbols and types: Bottom-up traversal

In this part of our compiler, we traverse the syntax tree created in previous steps of our project, and with the help of the symbol table created in previous steps, start catching errors when, for instance, users try to use an undefined variable or call a function with the wrong number of arguments.

## Authors
- SeokJun Bing
- Juan C. Torres

Some code provided by Sean W. Smith, some originally written by Thomas Cormen.

## How to build and run

- Execute `make` to build the program, `make clean` to delete object files and other executable files.

- Execute make test to build the program and run relevant tests. The folder `./testinputs` contains several example programs written in our C grammar, a subset of the full C grammar. Our test script should produce several files `{testfile}.output.{date}` with the results of each test.

## Program execution

*For descriptions of previous parts of this compiler, please see previous folders.*

- `symtab.c` and `symtab.h` define the data structures and functions required to build the symbol tables, as well as the functions to check for errors related to such symbol table,
e.g., checking that a variable has been defined before it is used.

- `parser.l` is a flex specification so that flex returns the next token from the input stream and returns other relevant information to the creation of a parse tree, such as string and int values.

- `parser.y` is a bison file, including a grammar and executable code. Each production in the grammar is accompanied by some code used to build a parse tree.

- `ast.c` and `ast.h` define the relevant data structures and functions needed to build a parse tree.

The program traverses the syntax tree created in previous steps, assuming that there have been no errors until this point (if there were, the program halts).

### Type Inference

First, the program begins by recording a `return_type` for the nodes that can be returned
and whose return_type is known, such as `int`s and function definitions.

*Note: `return_type` is different from `node_type` in that `return_type` is only assigned
to values that can be returned. Even though the abstract syntax tree created for the input
file contains all sorts of node, such as nodes for keeping track of the creation of scopes,
these nodes cannot be returned, and therefore don't have a `return_type`.*

After this, the program tries to infer the return type of unary and binary operators by traversing the tree in post-order. By doing so, children nodes are visited before
parent nodes, an important feature since `return_type` is a synthesized attribute for
operators, i.e., the `return_type` of a `+` node will depend on the `return_type` of its children.

#### Unary operators

For binary operators, such as `!` or unary minus, the `return_type` of the operation
is the `return_type` of its only child.

#### Binary operators

For binary operators, such as `+`, `=`, or `==`, the `return_type` of the operation
is the `return_type` of both of its children, if the `return_type`s of its children
are equal.

It is especially important to check the assignment operator `=`, as the type of
the variable on the left value is explicitly specified by the user program
and stored in the symbol table.

### Function Checking

After inferring the type of operations, calls to functions are checked to make
sure the types of parameters and values returned agree with those specified in the
function declaration.
#### Function parameter type checking

This is done by checking that the number and type of parameters match those stored
previously in the symbol table.

#### Function return type checking

This is done by checking that non-`void` functions return a value, and that `void`
functions do not.

The types of the values returned by each function are compared to the types
returned by the function, as stored in the symbol table.

*Note: It is important that checking come after type inference, as sometimes it
is unclear what the type of a parameter or a return value is.
For instance, without type inference, the type of the parameter passed
to `my_func(5 + 6)` is unclear, as is the type of the return value for
`return 3 + 2 + 4`.*


## Changes from previous programs

- The `ast_node` structure used in our syntax tree has been changed to include a line number to be printed in error messages, for easier debugging.

- Added a new `ast_node` type to identify function declarations, for easier error checking in our symbol tables.

- Added a pointer from each `ast_node` to its corresponding `symnode`.

- Added to flex and bison files to track current line number.
