#include<iostream>
#include<queue>
using namespace std;
int main(void)
{
    int T,N,M;
    int i,t;
    priority_queue<int>Q;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        for(i=0;i<M;i++)
        {
            cin>>t;
            Q.push(-t);
        }
        for(;i<N;i++)
        {
            cin>>t;
            t-=Q.top();
            Q.pop();
            Q.push(-t);
        }
        while(--M)Q.pop();
        cout<<-Q.top()<<"\n";
        Q.pop();
    }
}
