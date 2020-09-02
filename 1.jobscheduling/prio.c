#include<stdio.h>
void swap(int *x,int *y)
{int temp;
temp=*x;
*x=*y;
*y=temp;

}
void orderedp(int p[],int n,int bt[],int pr[])
{// uses selection sort algorithm
int min;
for(int i=0;i<n-1;i++)
{min=i;
for(int j=i+1;j<n;j++)
{if(pr[j]<pr[min])
min=j;
}
swap(&p[i],&p[min]);
swap(&bt[i],&bt[min]);
swap(&pr[i],&pr[min]);

}

}

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

void findavgt(int p[],int n,int bt[],int pr[]){
    
    float avgtt=0.0,avgwt=0.0;
    int wt[n],tt[n];
    findwt(bt,n,wt);
    findtt(bt,n,tt,wt);
    printf("process\tBurst time\tPriority\tWaiting time\tTurnaround Time");
for(int i=0;i<n;i++)
{
    printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],pr[i],wt[i],tt[i]);
    avgtt=avgtt+tt[i];
    avgwt=avgwt+wt[i];
}
	avgwt=avgwt/n;
	avgtt=avgtt/n;
    printf("\nAvg waiting time:%f",avgwt);
    printf("\nAvg turnaround time:%f",avgtt);

}
void enterp(int n){int p[n],bt[n],pr[n]; 
    printf("\nenter burst times and priority for each process");
    for(int i=0;i<n;i++)
    	{p[i]=i+1;
        scanf("%d",&bt[i]);
        scanf("%d",&pr[i]);
        }
        orderedp(p,n,bt,pr);
        findavgt(p,n,bt,pr);
}

void main(){
	int n;
    	printf("\nEnter number of processes");
    	scanf("%d",&n);
	enterp(n);



}
