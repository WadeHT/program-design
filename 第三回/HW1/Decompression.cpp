#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
int main(void)
{
    int N,a,b,c,A,B,C,D;
    int i,j;
    cin>>N;
    while(N--)
    {
        cin>>D>>a>>b>>c>>A>>B>>C;
        for(i=0; i<=a; i++)for(j=0; j<=b; j++)if(!((D-i*A-j*B)%C)&&(D-i*A-j*B)/C<=c)goto BL;
        cout<<"no\n";
        continue;
BL:
        cout<<"yes\n";
    }
}
