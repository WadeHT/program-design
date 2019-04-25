#include<stdio.h>
int main(void)
{
    int M,N;
    int T;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        T=0;
        while(M>0)
        {
            if((M%100)==N)T++;
            M/=10;
        }
        printf("%d\n",T);
    }
}
