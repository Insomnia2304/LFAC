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

%token <string> BEGIN_PROGRAM END_PROGRAM BEGIN_MAIN END_MAIN CLASS CONST MAIN
%token <string> TYPE VOID ID ASSIGN VAR_CHAR VAR_STRING
%token <int_val> ARRAY_SIZE VAR_INT VAR_BOOL
%token <float_val> VAR_FLOAT
%token <string> LESS GR LEQ GEQ 
%token <string> EQ NEQ
%token <string> AND OR
%token <string> IF ELSE FOR DO WHILE
%start progr
%left OR
%left AND
%left EQ NEQ
%left LESS GR LEQ GEQ
%left '+' '-'
%left '*' '/' '%'

%%
progr : BEGIN_PROGRAM SECTIONS END_PROGRAM { printf("The program is correct!\n"); }
    | BEGIN_PROGRAM SECTIONS END_PROGRAM error { printf("Unexpected text after end of program!\n"); } //"error" is a keyword
    ;


SECTIONS : SECT1_USER_DEFINED_DATA SECTIONS 
        | SECT2_GLOBAL_VARIABLES SECTIONS 
        | SECT3_GLOBAL_FUNCTIONS SECTIONS 
        | SECT4_MAIN 
        ;

/*
SECTIONS : SECT1_USER_DEFINED_DATA  SECTIONS
    |  REST1 ;

REST1: SECT2_GLOBAL_VARIABLES REST1 
    | REST2 ;

REST2: SECT3_GLOBAL_FUNCTIONS REST2 
    | SECT4_MAIN ;
*/

SECT1_USER_DEFINED_DATA : USER_DEFINED_TYPE
    ;

USER_DEFINED_TYPE : CLASS ID '{' INSIDE_CLASS '}' ';'
    | CLASS ID '{' INSIDE_CLASS '}' ID_LIST ';'
    ;

INSIDE_CLASS : VAR_DECL INSIDE_CLASS
    | FUNC_DECL INSIDE_CLASS
    | /* epsilon */
    ;

SECT2_GLOBAL_VARIABLES : VAR_DECL
    ;

SECT3_GLOBAL_FUNCTIONS : FUNC_DECL
    ;

SECT4_MAIN : TYPE MAIN '(' ')' '{' INSTR_LIST  '}' 
    | VOID MAIN '(' ')' '{' INSTR_LIST  '}' 
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

FUNC_DECL : TYPE ID '(' PARAM_LIST ')' ';'
    | VOID ID '(' PARAM_LIST ')' ';'
    ;

ARG : TYPE ELEMENT
    | /* epsilon */
    ;

PARAM_LIST : ARG ',' PARAM_LIST
    | ARG
    ;

INSTR_LIST : /* epsilon */
    | INSTR_LIST VAR_DECL
    | INSTR_LIST INSTR ';'
    | INSTR_LIST if
    | INSTR_LIST while
    | INSTR_LIST do
    | INSTR_LIST for
    ;

INSTR : ID ASSIGN ID
    ;

COND : COND AND COND
    | COND OR COND
    | '(' COND ')'
    | ID OP ID
    ;

OP : LESS
    | GR
    | LEQ
    | GEQ
    | EQ
    | NEQ
    ; 

if : IF '(' COND ')' '{' INSTR_LIST '}'
    | IF '(' COND ')' '{' INSTR_LIST '}' ELSE '{' INSTR_LIST'}'
    ;

while : WHILE '(' COND ')' '{' INSTR_LIST '}'
        ;

do : DO '{' INSTR_LIST '}' WHILE '(' COND ')' ';'
    ;

for : FOR '(' INSTR ';' COND ';' INSTR ')' '{' INSTR_LIST '}'
    ;
%%

void yyerror(const char * s) {
    printf("{error} %s at line: %d :(\n", s, yylineno);
}

int main(int argc, char **argv) {
    yyin = fopen(argv[1], "r");
    yyparse();
} 