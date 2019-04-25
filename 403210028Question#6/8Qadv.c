#include<stdio.h>
#include<math.h>
#include<string.h>
#define NN  100
int max,P[NN][NN];
int N,n[NN][NN];
void Be1(int J)
{
    int i,j,k;
    for(i=1; i<N; i++)n[i][J]=1<<(N-J-1);
    for(i=1,j=J+1; i<N&&j<N; i++,j++)n[i][J]|=(1<<(N-j-1));
    for(i=1,j=J-1; i<N&&j>=0; i++,j--)n[i][J]|=(1<<(N-j-1));
    for(i=1; i<N; i++)n[i][J]=(1<<N)-1-n[i][J];
}
void Qu(int I,int J,int now[],int temp,int IN)
{
    int i,j,k,K,h,H,NOW[NN];
    temp+=P[I][J];
    if(IN==0)
    {
        if(max<temp)max=temp;
        return 0;
    }
    memcpy(NOW,now,sizeof(int)*N);
    for(i=I+1; i<=N-IN; i++)
        for(j=0; j<N; j++)
        {
            if(((n[i-I][J]&now[i])>>(N-j-1))&1)
            {
                for(k=i; k<N; k++)NOW[k]&=n[k-I][J];
                Qu(i,j,NOW,temp,IN-1);
                memcpy(NOW,now,sizeof(int)*N);
            }
        }
    return 0;
}
int main()
{
    int i,j,k,H,now[NN],T,IN;
    freopen("123.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&IN);
        memset(n,0,sizeof(n));
        for(j=0; j<N; j++)Be1(j);
        H=(1<<N)-1;
        for(k=0; k<N; k++)now[k]=H;
        for(i=0; i<N; i++)for(j=0; j<N; j++)
            {
                scanf("%d",&P[i][j]);
                if(P[i][j]<0)now[i]^=(1<<N-j-1);
            }
        max=0;
        if(N>=IN)for(i=0; i<=N-IN; i++)for(j=0; j<N; j++)Qu(i,j,now,0,IN-1);
        printf("%d\n",max);
    }
}
