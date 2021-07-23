%{
int cc=0;
%}
%x CML CSL
%%
"/*"       {BEGIN CML; cc++;}
<CML>.     ;
<CML>"*/" {BEGIN 0;}
"//" {BEGIN CSL; cc++;}
<CSL>.      ;
<CSL>\n {BEGIN 0;}
%%
int main(int argc, char *argv[])
{
if(argc!=3)
{
printf("usage is %s <src file> <dest file>\n",argv[0]);
return;
}
yyin=fopen(argv[1],"r");
yyout=fopen(argv[2],"w");
yylex();
printf("no. of comment lines=%d\n",cc);
}
