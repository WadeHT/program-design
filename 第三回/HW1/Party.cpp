#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int visited[1005],dp0[1005],dp1[1005],r[1005],n;
int gra[1005][1005];
int maxx(int u,int v)
{
    if(u>v)return u;
    else return v;
}
void dfs(int u)
{
    int i,Max0=0,Max1=0;
    visited[u]=1;
    for(i=u; i<=n; i++)if(gra[u][i]&&!visited[i])dfs(i);
    printf("\n%d\n",u);
    for(i=u; i<=n; i++)
    {
        if(gra[u][i])
        {
            if(dp0[i]>Max0)Max0=dp0[i];
            if(dp1[i]>Max1)Max1=dp1[i];
        }
    }
    if(Max0>Max1)Max1=Max0;
    dp1[u]=r[u]+Max0;
    dp0[u]=Max1;
     printf("%d %d\n",dp0[u],dp1[u]);
}

int main(void)
{
    int T,s;
    int i,j;
    cin>>T;
    while(T--)
    {
        cin>>n>>r[1];
        for(i=2; i<=n; i++)
        {
            cin>>s>>r[i];
            gra[s][i]=1;
        }
        dfs(1);
        printf("%d\n",maxx(dp0[1],dp1[1]));
    }

}
