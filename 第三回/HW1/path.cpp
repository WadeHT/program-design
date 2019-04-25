#include<string.h>
#include<iostream>
using namespace std;
int main(void)
{
    int n,dp0,dp1;
    int i,t;
    cin>>n;
    while(n)
    {
        dp0=dp1=0;
        for(i=0;i<n;i++)
        {
            cin>>t;
            t+=dp0;
            dp0=dp1>dp0?dp1:dp0;
            dp1=t;
        }
        cout<<(dp0>dp1?dp0:dp1)<<"\n";
        cin>>n;
    }
}
