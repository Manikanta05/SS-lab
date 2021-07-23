%{
#include<stdio.h>
#include<stdlib.h>
int id=0,dig=0,key=0,op=0;
%}
%token ID DIGIT KEY OP
%%
input:
DIGIT input {dig++;}
| ID input {id++;}
| KEY input {key++;}
| OP input {op++;}
| DIGIT {dig++;}
| ID {id++;}
| KEY {key++;}
| OP {op++;}
%%
extern FILE *yyin;
main(int argc, char *argv[])
{
yyin=fopen(argv[1],"r");
yyparse();
printf("digit=%d\n,id=%d\n,key=%d\n,op=%d\n",dig,id,key,op);
}
yyerror()
{
printf("error\n");
exit(0);
}
