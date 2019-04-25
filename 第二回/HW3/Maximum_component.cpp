#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
int visited[5005],val[5005],Max;
vector<int>vec[5005];
void dfs(int u)
{
    int i;
    visited[u]=1;
    if(Max<val[u])Max=val[u];
    for(i=0; i<vec[u].size(); i++)if(!visited[vec[u][i]])dfs(vec[u][i]);
}
int main(void)
{
    int n,m,t,start[105];
    int i,u,v;
    cin>>n>>m>>t;
    while(n+m+t)
    {
        memset(visited,0,sizeof(visited));
        for(i=0; i<t; i++)cin>>start[i];
        for(i=0; i<n; i++)cin>>val[i];
        for(i=0; i<m; i++)
        {
            cin>>u>>v;
            vec[u].push_back(v);
        }
        for(i=0; i<t; i++)if(!visited[start[i]])dfs(start[i]);
        cout<<Max<<"\n";
        cin>>n>>m>>t;
    }

}
