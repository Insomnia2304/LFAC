%{
#include <stdio.h>
#include <stdlib.h>
#include "compiler.tab.h"
%}
%option noyywrap
%%
"begin_program" { return BEGIN_PROGRAM; }
"end_program" { return END_PROGRAM; }
"begin_main" { return BEGIN_MAIN; }
"end_main" { return END_MAIN; }
"==" { return EQ; }
"!=" { return NEQ; }
"<=" { return LEQ; }
">=" { return GEQ; }
"<" { return LESS; }
">" { return GR; }
"&&" { return AND; }
"||" { return OR; }
"if" { return IF; }
"else" { return ELSE; }
"while" { return WHILE; }
"do" { return DO; }
"for" { return FOR; }
"class" { return CLASS; }
"int"|"float"|"char"|"string"|"bool" { yylval.string = strdup(yytext); return TYPE; }
[1-9][0-9]* { yylval.int_val = atoi(yytext); return ARRAY_SIZE; }
"void" { yylval.string = strdup(yytext); return VOID; }
0|1 { yylval.int_val = atoi(yytext); return VAR_BOOL; }
\"[_a-zA-Z0-9]+\" { yylval.string = strdup(yytext); yylval.string++; yylval.string[strlen(yylval.string) - 1] = 0; return VAR_STRING; }
\'[_a-zA-Z0-9]\' { yylval.string = strdup(yytext); yylval.string++; yylval.string[strlen(yylval.string) - 1] = 0; return VAR_CHAR; }
-?[1-9][0-9]*|0 { yylval.int_val = atoi(yytext); return VAR_INT; }
-?([1-9][0-9]*\.[0-9]+|0\.[0-9]+) { yylval.float_val = atof(yytext); return VAR_FLOAT;}
"const" { return CONST; }
[_a-zA-Z][_a-zA-Z0-9]* { yylval.string = strdup(yytext); return ID; }
"=" { yylval.string = strdup(yytext); return ASSIGN; }
[ \t] ;
\n { yylineno++; }
. { return yytext[0]; }
