#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int disk_size=200;
void fcfs(int x[],int s, int head) 
{ 
    int seek_cnt = 0; 
    int d, cur_trk; 
    
  
    for (int i = 0; i < s; i++)
     { 
        cur_trk = x[i];  
        d = abs(cur_trk - head);  
        seek_cnt += d; 
        head = cur_trk; 
     } 
    cout<<"FCFS\n";
    cout << "Total number of seek operations = "
         << seek_cnt << endl; 
    cout << "Seek Sequence :" << endl; 
  
    for (int i = 0; i <s; i++) { 
        cout << x[i] << endl; 
    } 
} 


void scan(int x[],int s, int head) 
{   int dir;
    cout<<"enter direction 1.left 2.right\n";
    cin>>dir;
    int seek_cnt = 0; 
    int d, cur_trk; 
    vector<int> left,right,seek_seq;
    if(dir==1)
        left.push_back(0);
    else
        right.push_back(disk_size-1);
    for (int i = 0; i < s; i++)
    {
        if(x[i]<head)
            left.push_back(x[i]);
        else
            right.push_back(x[i]);
    }
    std::sort(left.begin(), left.end()); 
    std::sort(right.begin(), right.end()); 
    int r=2;
    while(r)
    {
        if(dir==1)
        { 
            for (int i = left.size()-1; i >=0 ; i--)
                { 
                    cur_trk = left[i];  
                    seek_seq.push_back(cur_trk);
                    d = abs(cur_trk - head);  
                    seek_cnt += d; 
                    head = cur_trk; 
                }
            dir=2;
        } 
     else 
        {
            { 
                for (int i = 0; i < right.size(); i++)
                    { 
                        cur_trk = right[i];  
                        seek_seq.push_back(cur_trk);
                        d = abs(cur_trk - head);  
                        seek_cnt += d; 
                        head = cur_trk; 
                    }
                dir=1;
            }
        }
    r--;
    }
    cout<<"SCAN\n";
    cout << "Total number of seek operations = "
         << seek_cnt << endl; 
    cout << "Seek Sequence :" << endl; 
  
    for (int i = 0; i <seek_seq.size(); i++) { 
        cout << seek_seq[i] << endl; 
    } 
} 

void cscan(int x[],int s, int head) 
{   int dir;
    cout<<"enter direction 1.left 2.right\n";
    cin>>dir;
    int seek_cnt = 0; 
    int d, cur_trk; 
    vector<int> left,right,seek_seq;
    left.push_back(0);
    right.push_back(disk_size-1);
    for (int i = 0; i < s; i++)
    {
        if(x[i]<head)
            left.push_back(x[i]);
        else
            right.push_back(x[i]);
    }
    std::sort(left.begin(), left.end()); 
    std::sort(right.begin(), right.end()); 
    int r=2;
    for (int i =0; i<right.size(); i++)
        { 
            cur_trk = right[i];  
            seek_seq.push_back(cur_trk);
            d = abs(cur_trk - head);  
            seek_cnt += d; 
            head = cur_trk; 
        }
    head=0;
    for (int i = 0; i < left.size(); i++)
                    { 
                        cur_trk = left[i];  
                        seek_seq.push_back(cur_trk);
                        d = abs(cur_trk - head);  
                        seek_cnt += d; 
                        head = cur_trk; 
                    }
    cout<<"C SCAN\n";
    cout << "Total number of seek operations = "
         << seek_cnt << endl; 
    cout << "Seek Sequence :" << endl; 
  
    for (int i = 0; i <seek_seq.size(); i++) { 
        cout << seek_seq[i] << endl; 
    } 
} 

int main(){
int h,n;
cout<<"enter size\n";
cin>>n;
int a[n];
cout<<"enter indexes\n";
for(int i=0;i<n;i++)
	cin>>a[i];
cout<<"enter head\n";
cin>>h;	
fcfs(a,n,h);
scan(a,n,h);
cscan(a,n,h);

return 0;
}
