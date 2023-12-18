%{
#include <stdio.h>
#include <stdlib.h>
#include "compiler.tab.h"
%}
%option noyywrap
%%

"begin_program" { return BEGIN_PROGRAM; }
"end_program" { return END_PROGRAM; }
"class" { return CLASS; }
"int"|"float"|"char"|"string"|"bool" { yylval.string = strdup(yytext); return TYPE; }
[_a-zA-Z][_a-zA-Z0-9]* { yylval.string = strdup(yytext); return ID; }
[1-9][0-9]* { yylval.int_value = atoi(yytext); return ARRAY_SIZE; }




[ \t] ;
\n { yylineno++; }
. { return yytext[0]; }
