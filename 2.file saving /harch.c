#include<stdio.h>
#include<string.h>

void main()
{
        char d[10][10][50];
        int md[10];
        int i,m,f[20],j;
        printf("Enter the number of directories of ROOT");
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
                printf("Enter the number of all subdirectories in directory %d :",i);
                scanf("%d",&md[i]);
                printf("Enter the number of files in the last subdirectory of %d : ",i);
                scanf("%d",&f[i]);
        }
        printf("Enter the name of the ROOT : ");
        scanf("%s",d[0][0]);
        for(i=1;i<=m;i++)
        {
                printf("Enter the name of Main Directory %d : ",i);
                scanf("%s",d[i][0]);
        }
        for(i=1;i<=m;i++)
        {	
            printf("Enter the name of the subdirectories of %d :",i);
            for(j=1;j<=md[i];j++)
            {    
                scanf("%s",d[i][j]);
            }
        }
        for(i=1;i<=m;i++)
        {
            printf("Enter the name of the files in last folder of %d :",i);
            for(j=md[i]+1;j<=f[i]+md[i];j++)
            {  
            scanf("%s\n",d[i][j]);
            }	
        }
        printf("The directory structure\n");
        printf("The ROOT : \t %s \n",d[0][0]);
        for(i=1;i<=m;i++)
        {
                printf("The Directory %d :%s\n",i,d[i][0]);
                for(j=1;j<=f[i]+md[i];j++)
                {
                    if(j<=md[i])
                    {    
                        printf ("   subdirectory: %s\n",d[i][j]);
                    }
                    else
                    {
                        printf ("       file: %s\n",d[i][j]);	
                    }    	                        
                }
        }
}
