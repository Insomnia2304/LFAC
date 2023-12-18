#!/bin/bash

echo "compiling compiler"
rm -f lex.yy.c
rm -f compiler.tab.c
rm -f compiler

bison -d -Wcounterexamples compiler.y
lex compiler.l
g++ lex.yy.c  compiler.tab.c -o compiler
./compiler input.txt