## Parser

This parser

## Authors
- SeokJun Bing
- Juan C. Torres

Some code provided by Sean W. Smith, some originally written by Thomas Cormen.

## How to build and run

- Execute `make` to build the program, `make clean` to delete object files and other executable files.

- Execute `make test` to build the program and run relevant tests. This produces a file `test.output.{date}` with the results of the test.

## Program execution
- parser.l is a flex specification so that flex returns the next token from the input stream and returns other relevant information to the creation of a parse tree, such as string and int values.

- parser.y is a bison file, including a grammar and executable code. Each production in the grammar is accompanied by some code used to build a parse tree.

- ast.c and ast.h define the relevant data structures and functions needed to build a parse tree.

## Notes about the program

1. We have assumed that the tree will be traversed using a preoder walk, and have tailored our tree so that code generation is easier on future steps. For instance, a `for` loop is created so that with a preorder walk we would see the initialization, test condition, and iteration stataments in that order, before moving to the body of the loop.

2. We have decided to maintain some extra information in order to preserve condition 1 and make future code generation easier. For instance, a compound statement in our grammar requires that local variables be defined before other executable code (`compound-statement -> local-declarations stament-list`). In the case that no local variables are defined, we could have not created a node for `local-declarations`, but this would have made complying with condition 1 harder, as we would have had to handle a special case of pointer manipulation. We have, then, kept an empty node in here to facilitate future code generation easier, as well as facilitate our compliance with condition 1.
