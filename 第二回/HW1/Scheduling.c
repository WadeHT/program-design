#include<stdio.h>
int Fmin(unsigned long long int m[],int M)
{
    int i,min,minum=0;
    min=m[0];
    for(i=0; i<M; i++)
    {
        if(min>m[i])
        {
            min=m[i];
            minum=i;
        }
    }
    return minum;
}
void Re(unsigned long long int m[],int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        m[i]=0;
    }
}

int main(void)
{
    int T,N,M;
    unsigned long long int t[3005],m[15],cost;
    int i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for(i=0; i<N; i++)
        {
            scanf("%llu",&t[i]);
        }
        Re(m,M);
        for(i=0; i<N; i++)
        {
            m[Fmin(m,M)]+=t[i];
        }
        cost=0;
        for(i=0; i<M; i++)
            if(cost<m[i])
                cost=m[i];
        printf("%llu\n",cost);
    }
}
