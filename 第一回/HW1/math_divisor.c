#include<stdio.h>
#define HB 100
void change(int *A, int *B)
{
    int T;
    T=*A;
    *A=*B;
    *B=T;
}
int gcd(int A, int B)
{
    int T;
    if(A<B)
        change(&A,&B);
    while(B!=0)
    {
        A=A%B;
        change(&A,&B);
        //printf("%d %d\n",A,B);
    }
    return A;
}

int Re(int A[],int a)
{
    int T;
    for(T=0; T<a; T++)
    {
        A[T]=0;
    }
    return 0;
}

int main()
{
    int a,T,t,Q2,Q1,R1,R2,A[HB],n,N;

    scanf("%d",&n);
    for(N=0; N<n; N++)
    {
        scanf("%d%d%d%d",&Q1,&R1,&Q2,&R2);
        t=gcd(Q1-R1,Q2-R2);
        for(T=1; T<=t; T++)
        {
            if(t%T==0)
            {
                printf("%d",T);
                if(T<t)
                    printf(" ");
            }
        }
        printf("\n");
    }
}


