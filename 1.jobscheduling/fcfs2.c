#include<stdio.h>

void findwt(int bt[],int n,int wt[],int at[])
{int servicet[n];
servicet[0]=0;
    wt[0]=0;
    for(int i=1;i<n;i++)
    {	servicet[i]=servicet[i-1]+ bt[i-1];
       wt[i]=servicet[i]-at[i];
       
       if(wt[i]<0)
       wt[i]=0;
     }  
}
void findtt(int bt[],int n,int tt[],int wt[])
{for(int i=0;i<n;i++)
        tt[i]=wt[i]+bt[i];
}

void findavgt(int p[],int n,int bt[],int at[]){
    
    float avgtt=0.0,avgwt=0.0;
    int wt[n],tt[n],ct;
    findwt(bt,n,wt,at);
    findtt(bt,n,tt,wt);
    printf("Process\tBurst time\tArrival time\tWaiting time\tTurnaround Time\tCompletion Time");
for(int i=0;i<n;i++)
{	ct=at[i]+tt[i];
    printf("\n%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],at[i],wt[i],tt[i],ct);
    avgtt=avgtt+tt[i];
    avgwt=avgwt+wt[i];
}
	avgwt=avgwt/n;
	avgtt=avgtt/n;
    printf("\nAvg waiting time:%f",avgwt);
    printf("\nAvg turnaround time:%f",avgtt);

}
void enterp(int n){
int p[n],bt[n],at[n];
printf("\nenter burst times and arrival times");
	for(int i=0;i<n;i++)
    	{p[i]=i+1;
        scanf("%d",&bt[i]);
        scanf("%d",&at[i]);
        }
        findavgt(p,n,bt,at);
}

void main(){
	int n;
    	printf("\nEnter number of processes");
    	scanf("%d",&n);
	enterp(n);



}
