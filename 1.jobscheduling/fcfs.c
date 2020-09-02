#include<stdio.h>

void findwt(int bt[],int n,int wt[])
{
    wt[0]=0;
    for(int i=1;i<n;i++)
       wt[i]=bt[i-1]+wt[i-1];
       
}
void findtt(int bt[],int n,int tt[],int wt[])
{for(int i=0;i<n;i++)
        tt[i]=wt[i]+bt[i];
}

void findavgt(int p[],int n,int bt[]){
    
    float avgtt=0.0,avgwt=0.0;
    int wt[n],tt[n];
    findwt(bt,n,wt);
    findtt(bt,n,tt,wt);
    printf("process\tBurst time\tWaiting time\tTurnaround Time");
for(int i=0;i<n;i++)
{
    printf("\n%d\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tt[i]);
    avgtt=avgtt+tt[i];
    avgwt=avgwt+wt[i];
}
	avgwt=avgwt/n;
	avgtt=avgtt/n;
    printf("\nAvg waiting time:%f",avgwt);
    printf("\nAvg turnaround time:%f",avgtt);

}
void enterp(int n){int p[n],bt[n]; 
    printf("\nenter burst times");
    for(int i=0;i<n;i++)
    	{p[i]=i+1;
        scanf("%d",&bt[i]);
        }
        findavgt(p,n,bt);
}

void main(){
	int n;
    	printf("\nEnter number of processes");
    	scanf("%d",&n);
	enterp(n);



}
