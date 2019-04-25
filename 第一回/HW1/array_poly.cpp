#include<iostream>
#include<string.h>
#include<math.h>
#define HB 100
using namespace std;
int Fac(int n)
{
    int i=1;
    while(n--)i*=(n+1);
    return i;
}
int main(void)
{
    int M,a,b,c,d;
    int A,B,C,Cof[100];
    cin>>M;
    while(M--)
    {
        cin>>a>>b>>c>>d;
        memset(Cof,0,sizeof(Cof));
        for(A=d; A>=0; A--)for(B=(d-A); B>=0; B--)Cof[A*2+B]=Cof[A*2+B]+Fac(d)*pow(a,A)*pow(b,B)*pow(c,d-A-B)/(Fac(A)*Fac(B)*Fac(d-A-B));
        for(A=d<<1; A>0; A--)cout<<Cof[A]<<" ";
        cout<<Cof[0];
        if(M)cout<<"\n";
    }
}
