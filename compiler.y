%{
#include <iostream>
#include "compiler.h"
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
    struct AST* tree;
}



%token <string> RETURN CLASS CONST MAIN EVAL TYPEOF
%token <string> TYPE VOID ID ASSIGN VAR_CHAR VAR_STRING
%token <int_val> VAR_INT
%token <float_val> VAR_FLOAT
%token <string> VAR_BOOL
%token <string> LESS GR LEQ GEQ 
%token <string> EQ NEQ
%token <string> NOT AND OR
%token <string> IF ELSE FOR DO WHILE

%type <tree> EXPR
%type <tree> COND
%type <string> LVALUE



%start progr

%left OR
%left AND
%left EQ NEQ
%left LESS GR LEQ GEQ
%left '+' '-'
%left '*' '/' '%'

%%
progr : SECTIONS { printf("The program is correct!\n"); }
    | SECTIONS error { printf("Unexpected text after end of program!\n"); } //"error" is a keyword
    ;



/*
SECTIONS : SECT1_USER_DEFINED_DATA  SECTIONS
    |  REST1 ;

REST1: SECT2_GLOBAL_VARIABLES REST1 
    | REST2 ;

REST2: SECT3_GLOBAL_FUNCTIONS REST2 
    | SECT4_MAIN  


*/
SECTIONS : SECT1_USER_DEFINED_DATA SECTIONS 
        | SECT2_GLOBAL_VARIABLES SECTIONS 
        | SECT3_GLOBAL_FUNCTIONS SECTIONS 
        | SECT4_MAIN 
        ;

SECT1_USER_DEFINED_DATA : USER_DEFINED_TYPE
    ;

USER_DEFINED_TYPE : CLASS ID  { strcpy(domain,$2); addClass($2,yylineno); strcpy(functionDomain,$2);} '{' INSIDE_CLASS '}' ';'  { strcpy(domain,"global"); strcpy(functionDomain,"global");}
    ;

INSIDE_CLASS : VAR_DECL ';' INSIDE_CLASS
    | FUNC_DECL INSIDE_CLASS
    | /* epsilon */
    ;

SECT2_GLOBAL_VARIABLES :  VAR_DECL ';'
    ;

SECT3_GLOBAL_FUNCTIONS :  FUNC_DECL  
    ;

SECT4_MAIN : TYPE MAIN { strcpy(domain,"main"); } '(' ')' '{' INSTR_LIST  '}' 
    ;

VAR_DECL : TYPE ID {  AST* aux=buildTree(strcmp($1,"bool")==0? "false": "0",convertStringToEnum($1),NULL,NULL,yylineno); addVar($1, $2, evaluateTree(aux,yylineno),domain, 0, yylineno); }
    | CONST TYPE ID { AST* aux=buildTree(strcmp($2,"bool")==0? "false": "0",convertStringToEnum($2),NULL,NULL,yylineno); addVar($2, $3, evaluateTree(aux,yylineno),domain, 1, yylineno); }
    | TYPE ID ASSIGN EXPR { addVar($1,$2,evaluateTree($4,yylineno),domain,0,yylineno); }
    | CONST TYPE ID ASSIGN EXPR { addVar($2,$3,evaluateTree($5,yylineno),domain,1,yylineno); }
    | TYPE ID '[' EXPR ']'  { int size=checkSize(evaluateTree($4,yylineno),yylineno); addArray($1,$2,size,domain,0,yylineno);}
    | ID ID   { checkClass($1,yylineno); AST* aux=buildTree("0",OTHER,NULL,NULL,yylineno); addVar($1, $2, evaluateTree(aux,yylineno),domain, 0, yylineno);}
    | TYPE ID '[' EXPR ']' '[' EXPR']'
    | TYPE ID '[' EXPR ']' '[' EXPR']' '[' EXPR']'
    | TYPE ID '[' EXPR ']' '[' EXPR']' '[' EXPR']' '[' EXPR']'
    ;



FUNC_DECL : TYPE ID {strcpy(domain,$2);} '(' PARAM_LIST ')' '{' INSTR_LIST '}'  { addFunction($1,$2,functionDomain,yylineno); strcpy(domain,"global"); }
    ;

PARAM_LIST : VAR_DECL { addParameter(); }',' PARAM_LIST
    | VAR_DECL { addParameter(); }
    | /* epsilon */
    ;

INSTR_LIST : /* epsilon */
    | INSTR_LIST VAR_DECL ';'
    | INSTR_LIST INSTR ';'
    | INSTR_LIST if
    | INSTR_LIST while
    | INSTR_LIST do
    | INSTR_LIST for
    | INSTR_LIST RETURN EXPR ';'
    | INSTR_LIST EVAL '(' EXPR ')' ';' { Eval(evaluateTree($4,yylineno),yylineno); }
    | INSTR_LIST TYPEOF '(' EXPR ')' ';' { TypeOf(evaluateTree($4,yylineno),yylineno); }
    ;

INSTR : LVALUE ASSIGN EXPR { updateVarValue(lvalue,evaluateTree($3,yylineno),yylineno); }
    | MULTIDIM ASSIGN MULTIDIM
    | MULTIDIM ASSIGN EXPR
    | EXPR
    ;

LVALUE : ID { strcpy(lvalue,$1); }
    | ID '[' EXPR ']' { strcpy(lvalue,$1); strcat(strcat(strcat(lvalue,"["),evaluateTree($3,yylineno).resultStr),"]");} 
    | ID '.' ID 
    | ID '[' EXPR ']' '.' LVALUE
    ;
/*
RVALUE : ID 
    | ID '(' ARGS_LIST ')'   
    | ID '.' RVALUE
    | ID '[' EXPR ']'
    | ID '[' EXPR ']' '.' RVALUE
    ;
*/

MULTIDIM:   | ID '[' EXPR ']' '[' EXPR']'
    | ID '[' EXPR ']' '[' EXPR']' '[' EXPR']'
    | ID '[' EXPR ']' '[' EXPR']' '[' EXPR']' '[' EXPR']' 
    ;

EXPR : EXPR '+' EXPR { $$=buildTree("+", OPERATOR, $1, $3,yylineno); }
    | EXPR '-' EXPR { $$=buildTree("-", OPERATOR, $1, $3,yylineno); }
    | EXPR '*' EXPR { $$=buildTree("*", OPERATOR, $1, $3,yylineno); }
    | EXPR '/' EXPR { $$=buildTree("/", OPERATOR, $1, $3,yylineno); }
    | EXPR '%' EXPR { $$=buildTree("%", OPERATOR, $1, $3,yylineno); }
    | '(' EXPR ')' { $$=$2; }
    | VAR_INT { $$=buildTree(itoaCustom($1), NUMBER_INT, NULL, NULL,yylineno); }
    | VAR_FLOAT { $$=buildTree(ftoaCustom($1), NUMBER_FLOAT, NULL, NULL,yylineno); }
    | VAR_BOOL { $$=buildTree($1, NUMBER_BOOL, NULL, NULL,yylineno); }
    | VAR_CHAR {  $$=buildTree($1, CHAR, NULL, NULL,yylineno); }
    | VAR_STRING { $$=buildTree($1, STRING, NULL, NULL,yylineno); }
    | EXPR AND EXPR { $$=buildTree("&&",NUMBER_BOOL,$1,$3,yylineno); }
    | EXPR OR EXPR { $$=buildTree("||",NUMBER_BOOL,$1,$3,yylineno); }
    | EXPR LESS EXPR { $$=buildTree("<",NUMBER_BOOL,$1,$3,yylineno); }
    | EXPR GR EXPR { $$=buildTree(">",NUMBER_BOOL,$1,$3,yylineno); }
    | EXPR LEQ EXPR { $$=buildTree("<=",NUMBER_BOOL,$1,$3,yylineno); }
    | EXPR GEQ EXPR { $$=buildTree(">=",NUMBER_BOOL,$1,$3,yylineno); }
    | EXPR EQ EXPR { $$=buildTree("==",NUMBER_BOOL,$1,$3,yylineno); }
    | EXPR NEQ EXPR { $$=buildTree("!=",NUMBER_BOOL,$1,$3,yylineno); }
    | NOT '(' EXPR ')' { $$=buildTree("!",NUMBER_BOOL,$3,NULL,yylineno);}
    | ID '(' ARGS_LIST ')'  { compareParamWithArgs($1,args,"global",yylineno); $$=buildTree($1,convertStringToEnum(getFuncType($1)),NULL,NULL,yylineno);}
    | ID { $$=buildTree($1,IDENTIFIER, NULL,NULL,yylineno); }
    | ID '[' EXPR ']' { char rvalue[1024]; strcpy(rvalue,$1); strcat(strcat(strcat(rvalue,"["),evaluateTree($3,yylineno).resultStr),"]"); $$=buildTree(rvalue,IDENTIFIER,NULL,NULL,yylineno);}
    | ID '.' ID '(' ARGS_LIST ')' { compareParamWithArgs($3,args,getTypeOfObject($1,yylineno),yylineno); isMemberInClass($1,$3,yylineno); $$=buildTree($1,OTHER,NULL,NULL,yylineno);}
    | ID '.' ID {  isIdInClass($1,$3,yylineno); $$=buildTree("0",OTHER,NULL,NULL,yylineno);}
    | ID '.' ID '[' EXPR ']' { }
    ;

COND : EXPR
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

ARGS_LIST : EXPR ',' { strcat(strcat(args, convertEnumToString(evaluateTree($1,yylineno).treeType)),", "); } ARGS_LIST
    | EXPR { strcat(args, convertEnumToString(evaluateTree($1,yylineno).treeType)); }
    | /* epsilon */ { strcat(args,"-"); }
    ;




%%

void yyerror(const char * s) {
    printf("{error} %s at line: %d :(\n", s, yylineno);
}

int main(int argc, char **argv) {
    FILE *fvar, *ffunc;
    fvar = fopen("variables.txt", "w");
    ffunc= fopen("functions.txt", "w");
    yyin = fopen(argv[1], "r");
    yyparse();
    //print();
    printVar(fvar);
    printFunc(ffunc);
    fclose(fvar);
    fclose(ffunc);
}