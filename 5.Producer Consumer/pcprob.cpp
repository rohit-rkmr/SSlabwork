#include<iostream>
using namespace std;

const int bfrs=5;// buffersize
int mutex=1;// binary semaphore
int empty=bfrs,full=0; // counting semaphore
int buffer[bfrs];// buffer array
int in=0,out=0;

void wait(int &s)
{
	while(s<=0);// busy wait 
	--s;
}

void signal(int &s)
{
	++s;
}

void Producer(int item)
{
	wait(empty);
	wait(mutex);
	//add item
	buffer[in]=item;
	in=(in+1)%bfrs;
	signal(mutex);
	signal(full);
}


void Consumer()
{
	wait(full);
	wait(mutex);
	//remove item
	int del= buffer[out];
	out=(out+1)%bfrs;
	signal(mutex);
	signal(empty);
	cout<<"item "<<del<<" was consumed\n";
}

void Displayb( )
{   cout<<"BUFFER\t";
	for(int i=out;i<in;i++)
		cout<<buffer[i]<<"\t";
    cout<<"\n";

}

int main()
{int ch=1,it;
while(true)
{
	cout<<"ENTER YOUR CHOICE\n";
	cout<<"1.PRODUCE\t2.CONSUME\t3.SHOW BUFFER\t4.EXIT\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
        if((mutex==1)&&(empty!=0))
        {
            cout<<"Enter item\n";
            cin>>it;
            Producer(it);
        }
       else
           cout<<"Buffer is full\n";
		break;
		case 2:
        if((mutex==1)&&(full!=0))
        {
		Consumer();
        }
        else
            cout<<"Buffer is empty\n";
        break;
		case 3:
		Displayb();
		break;
		default: exit(0);
	}
	
}
return 0;
}
