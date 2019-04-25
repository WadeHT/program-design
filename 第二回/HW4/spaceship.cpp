#include<iostream>
#include<stdlib.h>
using namespace std;
int main(void)
{
    int n,k1,k2;
    int K1,K2,dp1,dp2,t;
    cin>>n;
    while(n)
    {
        dp1=dp2=0;
        K1=K2=1000;
        while(n--)
        {
            cin>>k1>>k2;
            t=dp1+abs(k1-K1)<dp2+abs(k1-K2)?dp1+abs(k1-K1):dp2+abs(k1-K2);
            dp2=dp1+abs(k2-K1)<dp2+abs(k2-K2)?dp1+abs(k2-K1):dp2+abs(k2-K2);
            dp1=t;
            K1=k1;
            K2=k2;
        }
        cout<<(dp1<dp2?dp1:dp2)<<"\n";
        cin>>n;
    }
}
