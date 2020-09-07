#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct{
char dname[15];
char fname[10][15];
int fno;
}dir ={.fno=0};

void Create()
{
	char f[15];
	int i;
	printf("enter file name\n");
	scanf("%s",f);
	for(i=0;i<=dir.fno;i++)
	{	if(!strcmp(f,dir.fname[i]))
		break;
	}
	if(i<dir.fno)
	{
		printf("file already there\n");
		return ;
	}
	else
	{
		strcpy(dir.fname[dir.fno],f);
		dir.fno++;
	}

}


void Delete()
{
	char f[15];
	int i;
	printf("enter file name\n");
    scanf("%s",f);
	for(i=0;i<dir.fno;i++)
	{	
		if(!strcmp(f,dir.fname[i]))
		{
			do
			{	strcpy(dir.fname[i],dir.fname[i+1]);
				dir.fno--;
				i++;
			}while(i<dir.fno-1);
			return;
		}
		
	}
	printf("not there!\n");
	return;
}

void Search()
{
	char  f[15];
	int i;
	printf("enter file name\n");
	scanf("%s",f);
	for(i=0;i<dir.fno;i++)
	{	if(!strcmp(f,dir.fname[i]))
		{
			printf("present\n");
			return;
		}
	}
	if(i==dir.fno)
	{	printf("not there!\n");
		return;
	}
}

void Display( )
{
for(int i=0;i<dir.fno;i++)
printf("%s \n",dir.fname[i]);
}

void main()
{
int c;
while(1)
 {
printf("Enter option 1.Add file 2.Delete File 3.Search file 4.Display files \nenter any other to exit\n");
scanf("%d",&c);
switch(c)
  {case 1:Create();
break;
case 2:Delete();
break;
case 3:Search();
break;
case 4:Display();
break;
default:exit(0);
  }  
 }
}
