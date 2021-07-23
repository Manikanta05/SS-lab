%{
#include<stdio.h>
#include "y.tab.h"
extern  yylval;
%}
%%
[\t] ;
[+|-|*|/|=|<|>] {printf("operator is %s\n",yytext);return OP;}
[0-9]+ {yylval=atoi(yytext);printf("number is %d\n",yylval);return DIGIT;}
int|char|bool|float|void|for|while|if {printf("keyword is %s\n",yytext);return KEY;}
[_]?[a-zA-Z]+[0-9]* {printf("Identifier is %s\n",yytext);return ID;}
. ;
%%
