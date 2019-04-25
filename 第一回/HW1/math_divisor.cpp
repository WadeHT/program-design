#include<iostream>
using namespace std;
int gcd(int A,int B)
{
    A%=B;
    if(A)return gcd(B,A);
    return B;
}
int main(void)
{
    int n,Q1,Q2,R1,R2;
    int i,t;
    cin>>n;
    while(n--)
    {
        cin>>Q1>>R1>>Q2>>R2;
        t=gcd(Q1-R1,Q2-R2);
        for(i=1; i<=t; i++)if(!(t%i))cout<<i<<" ";
        cout<<"\n";
    }
}
