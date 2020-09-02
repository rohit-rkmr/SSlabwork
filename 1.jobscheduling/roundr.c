#include<stdio.h>
#include<stdbool.h>
void findwt(int bt[],int n,int wt[],int qt)
{int r_bt[n],t=0;
    for(int i=0;i<n;i++)
     	 r_bt[i]=bt[i]; 
      
         
while(true)
 { bool f=true; 
for(int i=0;i<n;i++)
  {
 if(r_bt[i]>0)
   {f=false;
	 if(r_bt[i]>qt)
	 {
	 t=t+qt;
	 r_bt[i]=r_bt[i]-qt;

 	}
	 else
 	{
 	t=t+r_bt[i];
 	wt[i]=t-bt[i];
 	r_bt[i]=0;
 	}
 	
   }

  }
 if(f==true)
 break;
 }      
}
void findtt(int bt[],int n,int tt[],int wt[])
{for(int i=0;i<n;i++)
        tt[i]=wt[i]+bt[i];
}

void findavgt(int p[],int n,int bt[],int qt){
    
    float avgtt=0.0,avgwt=0.0;
    int wt[n],tt[n];
    findwt(bt,n,wt,qt);
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
void enterp(int n){int p[n],bt[n],qt; 
    printf("\nenter burst times");
    for(int i=0;i<n;i++)
    	{p[i]=i+1;
        scanf("%d",&bt[i]);
        }
     printf("\nenter quantum time");
        scanf("%d",&qt);
        findavgt(p,n,bt,qt);
}

void main(){
	int n;
    	printf("\nEnter number of processes");
    	scanf("%d",&n);
	enterp(n);



}
