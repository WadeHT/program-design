#include<stdio.h>
#include<queue>
using namespace std;

long long int costLes(int N,int M,long long int job[])
{
    int i;
    long long int mmin;
    priority_queue<long long int> Fmm;
    for(i=0; i<N; i++)
    {
        if(i<M)
            Fmm.push(-job[i]);
        else
        {
            mmin=Fmm.top();
            Fmm.pop();
            Fmm.push(mmin-job[i]);
        }
    }
    while(!Fmm.empty())
    {
        mmin=Fmm.top();
        Fmm.pop();
    }
    return -mmin;
}
long long int Max(long long int job[],int N)
{
    priority_queue<long long int> Fmm;
    int i;
    for(i=0; i<N; i++)
    {
        Fmm.push(job[i]);
    }
    return Fmm.top();
}
long long int Tsum(long long int job[],int N)
{
    int i,j;
    long long int k=0;
    for(i=0; i<N; i++)
        k+=job[i];
    return k;
}

long long int FinLes(int N,long long int D,long long int job[])
{
    long long int mostM=N,lessM=Tsum(job,N)/D,midM=(mostM+lessM)/2,mostT,lessT,midT;
    lessT=Max(job,N);
    if(lessT>D)
        return -1;
    mostT=costLes(N,lessM,job);
    midT=costLes(N,midM,job);
    if(mostT==D)
        return lessM;
    else if(lessT==D)
        return mostM;
    else if(midT==D)
        return midM;
    while(1)
    {
        if(lessM+1==mostM)
        {
            if(mostT==D)
                return lessM;
            else
                return mostM;
        }
        else
        {
            if(mostT>D&&D>midT)
            {
                mostM=midM;
                lessT=midT;
            }
            else if(midT>D&&D>lessT)
            {
                lessM=midM;
                mostT=midT;
            }
            midM=(mostM+lessM)/2;
            midT=costLes(N,midM,job);
        }
        if(midT==D)
            return midM;
    }
}
int main(void)
{
    int T,N;
    long long int job[100005],D;
    int i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lld",&N,&D);
        for(i=0; i<N; i++)
        {
            scanf("%lld",&job[i]);
        }
        // printf("%lld %lld\n",costLes(N,3,job),costLes(N,5,job));
        printf("%lld\n",FinLes(N,D,job));

    }
}
