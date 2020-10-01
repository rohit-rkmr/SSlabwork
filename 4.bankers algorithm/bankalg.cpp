#include<iostream>
using namespace std;
const int m=3,n=5;// m is no of resources and n is no of processes
void disp(int alloc[][m],int max[][m])
{int i,j;
cout<<"\tA\tB\tC\n";
for(i=0;i<n;i++)
    {   
        cout<<"p"<<i+1<<"\n";
        for(j=0;j<m;j++)
            {   cout<<"\t"<<alloc[i][j];
            }
            cout<<"\n";
        for(j=0;j<m;j++)
        {   cout<<"\t"<<max[i][j];
        }
        cout<<"\n";
    }   
}
void bkl(int alloc[][m],int max[][m],int av[])
{
	int f[n],ss[n],pos=0,i,j,k,l,need[n][m],flag;
	for(i=0;i<n;i++)// flag for process 
		f[i]=0;	
	for(i=0;i<n;i++)
    {   for(j=0;j<m;j++)
            {
                need[i][j]=max[i][j]-alloc[i][j];
            }
    }
    for(l=0;l<5;l++)
    {
        for(i=0;i<n;i++)
        {
            if(f[i]==0)
            {   flag=0;//flag for need availability
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>av[j])// if resources are inadequate
                    { 
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {   ss[pos++]=i;
                    for(k=0;k<m;k++)
                            av[k]+=alloc[i][k];
                    f[i]=1;
                }
            }   
        }
    }
    cout<<"safe sequence\n";
	for(i=0;i<n;i++)
        cout<<"-> P "<<ss[i];
}

int main()
{
    int max[n][m],alloc[n][m],av[m],i,j;
    for(i=0;i<n;i++)
    {   cout<<"enter allocated and max resources of A,B and C respectively for p"<<i+1<<"\n";
        for(j=0;j<m;j++)
            {
                cin>>alloc[i][j];
                cin>>max[i][j];
            }
    }
    cout<<"enter availability of A, B and C\n";
    for(i=0;i<m;i++)
        cin>>av[i];
//     disp(alloc,max);
    bkl(alloc,max,av);
}
