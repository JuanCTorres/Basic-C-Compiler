# Target code generation

In this part of our compiler, we look at the array of quads generated in previous steps of our project, and with the help of the symbol, we generate code targeted at Y86-assembly.

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


### Generating target code

We look at the sequence of three-address instructions one by one, and generate assembly code to implement the instructions specified by them.

#### Conventions
##### Register use

We have decided to use particular registers for specific purposes:


- Left operand register, `LEFT_OPERAND_REG` is `%eax`.
- Right operand register, `RIGHT_OPERAND_REG` is `%ecx`.
- I/O register, `IO_REG`, is `%edx`. This register is used when moving values to I/O addresses.
- Stack pointer, `STACK_PTR`, is `%esp`.
- Base pointer, `BASE_PTR`, is `%ebp`.
- Return register, `RETURN_REG`, is `%edi`. This register is used to return values from functions.

##### I/O

I/O in our compiler is achieved by moving or reading data from the following addresses in memory:


- `DSTR`, used to display a string value, is `0x00FFFE10`.
- `DHXR`, used to display a hex value, is `0x00FFFE14`.
- `KHXR`, used to read a hex value from the keyboard, is `0x00FFFE1C`.

#### Memory use

- Program code starts at the bottom of the memory space, at `0`.
- Temporary storage variables are stored in the heap, above the program code. Each temporary variable has a unique temporary identifier, which is then used to calculate the offset from the beginning of the temporary memory space when accessing them.
- String literals are stored in the heap, above the temporary space as `.byte` directives.
- Global variables are stored in the heap, above the string literals, as `.long` directives.
- Local variables are stored in the stack, with an offset from the frame pointer.
- Parameters to a function are stored above the function's frame pointer, though we are copying them into the same space as locals (below the frame pointer), to make their handling easier

## Changes from previous programs

- Function prologues and epilogues are no longer just a label. Instead, each has its own three-address operation or quad.
