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
    int int_value;
}

%token  BEGIN_PROGRAM END_PROGRAM CLASS ID ARRAY_SIZE
%token<string> TYPE
%start progr

%%
progr : BEGIN_PROGRAM SECT1_USER_DEFINED_DATA SECT2_GLOBAL_VARIABLES END_PROGRAM { printf("The program is correct!\n"); }
    | BEGIN_PROGRAM SECT1_USER_DEFINED_DATA SECT2_GLOBAL_VARIABLES SECT3_GLOBAL_FUNCTIONS SEC4_MAIN END_PROGRAM error { printf("Unexpected text after end of program!\n"); } //"error" is a keyword
    ;


SECT1_USER_DEFINED_DATA : USER_DEFINED_TYPE SECT1_USER_DEFINED_DATA
    | USER_DEFINED_TYPE
    ;

USER_DEFINED_TYPE : CLASS ID '{' INSIDE_CLASS '}' ';'
    ;

INSIDE_CLASS : CLASS_VARS
    ;

CLASS_VARS : CLASS_VAR_DECL
    ;

SECT2_GLOBAL_VARIABLES : VAR_DECL SECT2_GLOBAL_VARIABLES
    | VAR_DECL
    ;

SECT3_GLOBAL_FUNCTIONS : 
    ;

SEC4_MAIN :
    ;

CLASS_VAR_DECL : TYPE ID_LIST CLASS_VAR_DECL
    | TYPE ID_LIST
    ;

VAR_DECL : TYPE ID_LIST VAR_DECL
    | TYPE ID_LIST
    ;

ID_LIST : ELEMENT ';'
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