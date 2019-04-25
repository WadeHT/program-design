#include<stdio.h>
#include<stdlib.h>
int Cmp(const void *e1,const void *e2)
{
    return (*(int*)e1)-(*(int*)e2);
}
int main(void)
{
    int i,j;
    int T,N;
    unsigned long long int costt[1005],sum,temp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(i=0; i<N; i++)
            scanf("%llu",&costt[i]);
        qsort(costt,N,sizeof(unsigned long long int),Cmp);
        sum=0;
        for(i=0; i<N; i++)
        {
            sum+=(2*i+1)*costt[N-i-1];
        }
        printf("%llu\n",sum);
    }
}
