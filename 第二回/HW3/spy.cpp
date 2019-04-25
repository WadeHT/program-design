#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    int T,N,node[10005],n[10005];
    int i,t;
    cin>>T;
    while(T--)
    {
        t=0;
        memset(n,0,sizeof(n));
        cin>>N;
        for(i=1;i<N;i++)cin>>node[i];
        for(i=N-1;i>0;i--)if(!n[i]&&!n[node[i]])
        {
            t++;
            n[node[i]]=1;
        }
        cout<<t<<"\n";
    }
}
