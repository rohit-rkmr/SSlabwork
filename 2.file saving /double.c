#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct{
char dname[15];
char fname[10][15];
int fno;
}dir[10];

int dno=0;

void Created( ){
    printf("enter directory name\n");
    scanf("%s",dir[dno].dname);
    dir[dno].fno=0;
    dno++;
}

void Createf( )
{   
	char f[15];
    int j;
    printf("enter directory name\n");
    scanf("%s",f);
    for(j=0;j<dno;j++)
        if(!strcmp(f,dir[j].dname))
            break;
    if(j==dno)
        {   printf("no directory with this name");
            return;
        }   
	int i;
	printf("enter file name\n");
	scanf("%s",f);
	for(i=0;i<=dir[j].fno;i++)
	{	if(!strcmp(f,dir[j].fname[i]))
		break;
	}
	if(i<dir[j].fno)
	{
		printf("file already there\n");
		return ;
	}
	else
	{
		strcpy(dir[j].fname[dir[j].fno],f);
		dir[j].fno++;
	}

}


void Delete()
{
	char f[15];
    int j;
    printf("enter directory name\n");
    scanf("%s",f);
    for(j=0;j<dno;j++)
        if(!strcmp(f,dir[j].dname))
            break;
    if(j==dno)
        {   printf("no directory with this name");
            return;
        } 
	int i;
	printf("enter file name\n");
    scanf("%s",f);
	for(i=0;i<dir[j].fno;i++)
	{	
		if(!strcmp(f,dir[j].fname[i]))
		{
			do
			{	strcpy(dir[j].fname[i],dir[j].fname[i+1]);
				dir[j].fno--;
				i++;
			}while(i<dir[j].fno-1);
			return;
		}
		
	}
	printf("not there!\n");
	return;
}

void Search()
{
	char  f[15];
    int j;
    printf("enter directory name\n");
    scanf("%s",f);
    for(j=0;j<dno;j++)
        if(!strcmp(f,dir[j].dname))
            break;
    if(j==dno)
        {   printf("no directory with this name");
            return;
        } 
	int i;
	printf("enter file name\n");
	scanf("%s",f);
	for(i=0;i<dir[j].fno;i++)
	{	if(!strcmp(f,dir[j].fname[i]))
		{
			printf("present\n");
			return;
		}
	}
	if(i==dir[j].fno)
	{	printf("not there!\n");
		return;
	}
}

void Display( )
{   int j;
    char f[15];
    printf("enter directory name\n");
    scanf("%s",f);
    for(j=0;j<dno;j++)
        if(!strcmp(f,dir[j].dname))
            break;
    if(j==dno)
        {   printf("no directory with this name");
            return;
        } 
for(int i=0;i<dir[j].fno;i++)
printf("%s \n",dir[j].fname[i]);
}

void main()
{
int c;
while(1)
 {
printf("Enter option 1.Add directory 2.Create file 3.Delete File 4.Search file 5.Display files \nenter any other to exit\n");
scanf("%d",&c);
switch(c)
  {case 1:Created();
break;
case 2:Createf();
break;
case 3:Delete();
break;
case 4:Search();
break;
case 5:Display();
break;
default:exit(0);
  }  
 }
}
