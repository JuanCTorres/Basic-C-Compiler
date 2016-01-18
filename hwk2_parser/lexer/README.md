# README
Documentation for building and running our lexer, including any assumptions made.

## Group Name
HelloWorld

## Team Members
- SeokJun Bing
- Charles Li
- Juan Torres

Attributions, as appropriate.

## Documentation
- Invoke make to build the lexer.

## Program execution
- cscan.l is a flex specification so that flex returns the next token from the input stream and places the
lexeme so matched in the global variable yytext.

- toktype.h contains an array of string token tables and enum of token types

- cscan.c contains the main function that calls yylex() and outputs the final result to the terminal

## Attributions
Please also note that we have used the given example code from the class to do this assignment.

## Assumptions
- Because the assignment description was some what vague about what lexemes to include and what not to include, we have
decided to include the lexemes from the original code in addition to the explicitly stated lexemes in the
assignment decription.

- Inputs such as ^123 is divided into ^ and 123 as ^ is an unrecognized character in our lexer. 123 is
recognized as integer constant. (We checked with the TA and he says this is fine)

- When yylex reaches the end of input, it returns EOF_T (Checked with the TA that this is fine as well)

- OTHER_T token is given to words that are not recognized by the lexer.


## Testing
`./testscript.sh`

- Use this command to run test. This bash script runs make and then inputs test parameters from test_1.input

- The output file is named "testoutput.`date +"%a_%b_%d_%T_%Y".
