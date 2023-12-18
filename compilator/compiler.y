%{
#include <iostream>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);

%}
%union {
    char* string;
    int int_val;
    float float_val;
}

%token  BEGIN_PROGRAM END_PROGRAM CLASS CONST
%token<string> TYPE ID ASSIGN VAR_CHAR VAR_STRING
%token<int_val> ARRAY_SIZE VAR_INT VAR_BOOL
%gtoken<float_val> VAR_FLOAT
%start progr

%%
progr : BEGIN_PROGRAM SECT1_USER_DEFINED_DATA SECT2_GLOBAL_VARIABLES SECT3_GLOBAL_FUNCTIONS SECT4_MAIN END_PROGRAM { printf("The program is correct!\n"); }
    | BEGIN_PROGRAM SECT1_USER_DEFINED_DATA SECT2_GLOBAL_VARIABLES SECT3_GLOBAL_FUNCTIONS SECT4_MAIN END_PROGRAM error { printf("Unexpected text after end of program!\n"); } //"error" is a keyword
    ;


SECT1_USER_DEFINED_DATA : USER_DEFINED_TYPE SECT1_USER_DEFINED_DATA
    | /* epsilon */
    ;

USER_DEFINED_TYPE : CLASS ID '{' INSIDE_CLASS '}' ';'
    | CLASS ID '{' INSIDE_CLASS '}' ID_LIST ';'
    ;

INSIDE_CLASS : VAR_DECL INSIDE_CLASS
    | /* epsilon */
    ;

SECT2_GLOBAL_VARIABLES : VAR_DECL SECT2_GLOBAL_VARIABLES
    | /* epsilon */
    ;

SECT3_GLOBAL_FUNCTIONS : 
    ;

SECT4_MAIN :
    ;

VAR_DECL : TYPE ID_LIST ';'
    | CONST TYPE ID_LIST ';'
    ;

ID_LIST : ELEMENT
    | ELEMENT ',' ID_LIST
    ;

ELEMENT : ID
    | ID '[' ARRAY_SIZE ']'
    ;

%%

void yyerror(const char * s) {
    printf("{error} %s at line: %d :(\n", s, yylineno);
}

int main(int argc, char** argv) {
    yyin = fopen(argv[1], "r");
    yyparse();
} 