# Final submission

For this submission, we have focused on bug hunting and more testing.

## Authors
- SeokJun Bing
- Juan C. Torres

Some code provided by Professor Sean W. Smith with some originally written by Professor Thomas Cormen. See each file for specific details.

## How to build and run

- Execute `make` to build the program, `make clean` to delete object files and other executable files.

- Execute make test to build the program and run relevant tests. The folder `./testinputs` contains several example programs written in our C grammar, a subset of the full C grammar. Our test script should produce several files `[testfile].output.{date}` with the results of each test. The assembly files will be located in the `ys` folder, with the title `[testfile].ys`, e.g., `test1.c.ys`.

    - `recursive_factorial.c` contains a recursive function that calculates `n!` for a given `n`.
    - `fibb` contains a function that calculates the `n^th` term of the _Fibonacci_ sequence. It containts `if` and `for` statements designed to test our handling of jumps and condition testing.
    - `scoping.c` contains a program that uses global and local variables, as well as nested scopes inside a function.
    - `helloworld` contains a sample of a program that simply prints `"helloworld"` to the terminal window from where the Y86-simulator is called.


- Generating assembly code for a particular file should be done by running `./parser [output file] < [input file]`, where `[input file]` represents the high-level C program and `[output file]` represents the file name of the output file. The output file will be located in `ys/[output file].ys`

- *WARNING*: Using the scrollable memory display will freeze the simulator when running some of our programs given the spread-out nature of memory accesses. Use a nonscrollable .tcl file if possible.

## Program execution

*For descriptions of previous parts of this compiler, please see previous folders.*

- `targetcode.c` and `targetcode.h` contain the code to generate the target code for Y86-assembly.

- `unescape.c`, provided by Professor Sean Smith, helps with printing strings to memory.

- `quad.c` and `quad.h` define the data structures and functions required to build the array of quads that we will eventually use to generate assembly code.

- `symtab.c` and `symtab.h` define the data structures and functions required to build the symbol tables, as well as the functions to check for errors related to such symbol table,
e.g., checking that a variable has been defined before it is used.

- `parser.l` is a flex specification so that flex returns the next token from the input stream and returns other relevant information to the creation of a parse tree, such as string and int values.

- `parser.y` is a bison file, including a grammar and executable code. Each production in the grammar is accompanied by some code used to build a parse tree.

- `ast.c` and `ast.h` define the relevant data structures and functions needed to build a parse tree.

The program traverses the syntax tree created in previous steps, assuming that there have been no errors until this point (if there were, the program halts).


## Changes
#### Parameters
##### Parameter offsets in local functions
Parameters to a function are no longer addressed as negative offsets from the frame pointer. Previously, after parameters were pushed onto the stack and the frame pointer was moved beneath them, we
copied the parameters below the frame pointer so that we could access all symbols in a scope in a uniform
manner. This creates some complications and inefficiencies, so we have reverted this change. Now
parameters are accessed as positive offsets from the frame pointer.

##### Entire arrays as parameters
When entire arrays are passed as parameters, they are pushed to the stack. They function to which they are passed will treat
them as local variables, and can access the values stored in the array as they were stored at the time they were passed to
the function, but **will not modify the values of the array globally**.

Since passing arrays as parameters does not work as in C where pointers are used, but instead
we push onto the stack every element of the array, we have decided to limit the number of elements
in the arrays that are passed as parameters.
This is done because there is no way to know the length of the arrays that a function is expecting to be passed as arrays. When a function is declared and its signature specifies that it expects an
entire array as a parameter, it looks like this:

    my_func(my_arr[]){
        ...
    }

`my_arr` has never been seen in the symbol table before, so there is no way to know how many elements
it contains. By default, we consider all arrays passed as parameters to contain 20 elements, all of
which are pushed onto the stack when an array is passed as a parameter. If the array passed as a
parameter contains less than 20 elements, this approach results in more data being pushed onto the
stack, but these data will not affect other local variables or parameters. The behavior when the user
accesses these data is unspecified.

If, on the other hand, the array contains more than 20 elements, only the first 20 elements will be
pushed onto the stack.

It is entirely possible to still pass as many parameters individually to a function as desired. Passing
an array longer than 20 elements can be done by passing its elements individually, even if this is not
an ideal situation.

A way to solve this in the future could include passing pointers when arrays are used as parameters
or passing some sort of information in a temporary variable that can be read so that the function knows
how many elements a particular array has.


## Project status

### The following still have bugs:

- Saving the value of multiple function calls, if they are on the same expression,
e.g., `f(x) + g(y);`
