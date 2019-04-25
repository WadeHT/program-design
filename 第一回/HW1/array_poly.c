#include<stdio.h>
#define HB 100


int Fac(int a)
{
    int T,t=1;
    for(T=2; T<=a; T++)
    {
        t=t*T;
    }
    return t;
}

int Pow(int a, int b)
{
    int A=1,T=a;
    while(b)
    {
        if(b&1)
            A*=T;
        T=T*T;
        b>>=1;
    }
    return A;
}

int main()
{
    int n,a,b,c,d,A,B,C,T,Cof[HB];
    scanf("%d%",&n);

    for(T=0; T<n; T++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);

        for(A=0; A<HB; A++)
        {
            Cof[A]=0;
        }

        for(A=d; A>=0; A--)
        {
            for(B=(d-A); B>=0; B--)
            {
                C=d-A-B;
                //printf("A=%d B=%d C=%d\n%d\n",A,B,C,Fac(d)*Pow(a,A)*Pow(b,B)*Pow(c,C)/(Fac(A)*Fac(B)*Fac(C)));
                Cof[A*2+B]=Cof[A*2+B]+Fac(d)*Pow(a,A)*Pow(b,B)*Pow(c,C)/(Fac(A)*Fac(B)*Fac(C));
            }
        }

        for(A=2*d; A>=0; A--)
        {
            //if(Cof[A]!=0)
            //{
            printf("%d",Cof[A]);
            if(A>0)
            {
                printf(" ");//非最後則空格
            }
            //}
        }
        if(T<n-1)//非最後一次則換行
            printf("\n");
    }
}
