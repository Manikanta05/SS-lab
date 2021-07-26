#include<stdio.h> #include<stdlib.h> int n,nf;
int ref[30]; int p[50]; int hit=0; int i,j=0,k;
int pgfaultcnt=0; void getData()
{
printf("Enter length of page reference sequence:\n"); scanf("%d", &n);
printf("Enter the number of frames:\n"); scanf("%d",&nf);
printf("Enter the page reference sequence:\n"); for(i=0;i<n;i++)
scanf("%d",&ref[i]);
}
void initilize()
{
pgfaultcnt=0; for(i=0;i<nf;i++) p[i]=9999;
}
int ishit(int data)
{
hit=0; for(j=0;j<nf;j++)
{
if(p[j]==data)
{
hit=1; break;
}
}
return hit;
}
void dispages()
{
for(k=0;k<nf;k++)
{ if(p[k]!=9999)
printf("%d",p[k]);
}
}
void fifo()
{
int j=0; initilize();
printf("\tPAGE\tFRAMES\tFAULTS\n");
for(i=0;i<n;i++)
{
printf("\n\t%d\t",ref[i]); if(ishit(ref[i])==0)
{
p[j]=ref[i]; j++;
dispages();
printf("\tpage fault %d",pgfaultcnt); pgfaultcnt++;
}
else
{
dispages();
printf("\tNo pages fault");
}
if(j==nf) j=0;
}
printf("\nTotal no of page faults in FIFO is %d",pgfaultcnt);
}
void lru()
{
initilize(); int least[50];
printf("\t PAGE\tFRAMES\tFAULTS\n"); for(i=0;i<n;i++)
{
printf("\n\t%d\t",ref[i]); if(ishit(ref[i])==0)
{
for(j=0;j<nf;j++)
{
int pg=p[j]; int found=0;
for(k=i-1;k>=0;k--)
{
if(pg==ref[k])
{
least[j]=k; found=1; break;
}
else found=0;
}
if(!found) least[j]=-9999;
}
int min=9999; int repindex; for(j=0;j<nf;j++)
{
if(least[j]<min)
{
min=least[j]; repindex=j;
}
}
p[repindex]=ref[i]; dispages();
printf("\tPage fault %d",pgfaultcnt); pgfaultcnt++;
}
else
{
dispages();
printf("\tNo page fault!");
}
}
printf("\n Total no of page faults in lru is:%d", pgfaultcnt);
}
int main()
{
int choice, yn; do
{
printf("Page Replacement Algorithms\n"); printf("1. Enter data 2. FIFO 3.LRU 4.Exit\n"); printf("Enter your choice\n"); scanf("%d",&choice);
switch(choice)
{
case 1: getData();
break; case 2: fifo();
break; case 3: lru();
break; case 4: exit(0);
}
printf("\n Do you want to continue?\n If yes press 1\n If no press 0\n"); scanf("%d",&yn);
}
while(yn==1); return(0);
}
