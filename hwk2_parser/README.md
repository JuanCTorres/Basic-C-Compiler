# SIMPLE COMPILER


## What is it?

Simple compiler is a basic compiler for a subset of C.

## Modules

* *lexer* Takes as input a file and returns tokens based on the lexemes found.
* *parser* Calls the lexer and builds a syntax tree based on the productions defined in the grammar (specified here).

## How to run

Compile using `make`. By default, this produces an executable named `parse` Run by redirecting output to it:
`$ ./parse test1.c`

## authors

* [Juan C. Torres](https://github.com/juanctorres)
* [Seok Jun Bing](https://github.com/seokjunbing)
* Charles Li contributed to lexer.

Some files provided by Sean W. Smith, some originally writen by Thomas Cormen.
See each file for more details.
