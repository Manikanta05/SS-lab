%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
S:e {printf("result=%d\n",$$); return 0;}
;
e:e'+'e {$$=$1+$3;}
|e'-'e {$$=$1-$3;}
|e'*'e {$$=$1*$3;}
|e'/'e {$$=$1/$3;}
|'('e')' {$$=$2;}
|NUM {$$=$1;}
;
%%
main()
{
printf("enter the expr\n");
yyparse();
}
yyerror()
{
printf("error\n");
exit(0);
}
