#include <stdio.h>
#include <stdlib.h>
int Max[10][10], need[10][10], alloc[10][10], avail[10],
completed[10], request[10], sseq[10], ch1;
int p,r,i,j,k, new;
int safeseq();
int main()
{
int violationcheck, waitcheck;
printf("Enter the number of process :");
scanf("%d", &p);
printf("Enter the no of resources :");
scanf("%d", &r);
printf("Enter the Max matrix for each process:\n");
for(i=0; i<p;i++)
{
printf("For process %d :", i+1);
for(j=0;j<r;j++)
scanf("%d", &Max[i][j]);
}
printf("Enter the allocation for each process :\n");
for(i=0;i<p;i++)
{
printf("For process %d :", i+1);
for(j=0; j<r;j++)
scanf("%d", &alloc[i][j]);
}
printf("Enter the available Resources :\n");
for(i=0;i<r; i++)
scanf("%d",&avail[i]);
for (i=0;i<p;i++)
for (j=0;j<r;j++)
need[i][j] = Max[i][j] - alloc[i][j];
printf("\nMax Matrix:\tAllocation matrix:\t Need matrix\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
printf("%d", Max[i][j]);
printf("\t\t");
for(j=0;j<r; j++)
printf("%d", alloc[i][j]);
printf("\t\t");
for(j=0;j<r; j++)
printf("%d", need[i][j]);
printf("\n");
}
ch1=safeseq();
if(ch1==0)
{
printf("The system is not in safe state\n");
exit(0);
}
else
{
violationcheck=0;
waitcheck=0;
printf("\nRequesting Process ID:\n");
scanf("%d",&new);
printf("Enter the request for process \n");
for(j=0;j<r;j++)
scanf("%d", &request[j]);
for(i=0;i<p;i++)
{
if (i==new)
{
for(j=0;j<r;j++)
{
if(request[j]>need[i][j])
violationcheck=1;
if(request[j]>avail[j])
waitcheck=1;
}
if(violationcheck==1)
{
printf("\nThe process exceeds its MAx Needs: Terminated\n");
exit(0);
}
else if(waitcheck==1)
{
printf("\nlack of resources:process state-wait\n");
exit(0);
}
else
{
for(j=0;j<r;j++)
{
avail[j]=avail[j]-request[j];
alloc[i][j]=alloc[i][j]+request[j];
need[i][j]= need[i][j]-request[j];
}
}
}
}
ch1=safeseq();
if(ch1==0)
{
for(j=0;j<r;j++)
{
avail[j]=avail[j]+request[j];
alloc[new][j]=alloc[new][j]-request[j];
need[new][j]=need[new][j]+request[j];
}
}
else if(ch1==1)
printf("\nRequest Committed\n");
}
}
int safeseq()
{ int tj, tk,i,j,k,work[10];
int check1, check2,ss=0;
for(j=0;j<r;j++)
work[j]=avail[j];
for(j=0;j<p;j++)
completed[j]=0;
for(tk=0;tk<r;tk++)
{
for(j=0;j<p;j++)
{
if(completed[j]==0)
{
check1=0;
for(k=0;k<r;k++)
if(need[j][k]<=work[k])
check1++;
if(check1==r)
{
for(k=0;k<r;k++)
{
work[k]=work[k]+alloc[j][k];
completed[j]=1;
}
sseq[ss]=j;
ss++;
}
}
}
}
check2=0;
for(i=0;i<p;i++)
if(completed[i]==1)
check2++;
printf("\n");
if(check2>=p)
{
printf("\nThe System is in Safe State\n");
for(tj=0;tj<p;tj++)
printf("p%d",sseq[tj]);
return 1;
}
else
{
printf("\nThe system is not in Safe State\n");
return 0;
}
}
