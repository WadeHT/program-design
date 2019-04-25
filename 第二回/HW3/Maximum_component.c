#include<stdio.h>
typedef struct nu
{
    int vertex;
    struct nu *link;
} node;
node *graph[1000005];
int visited[1000005],Tval,val[1000005];

void insert(int vi,int vj)
{
    node *p,*q;
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->link=NULL;
    if(graph[vi]==NULL)
        graph[vi]=q;
    else
    {
        p=graph[vi];
        q->link=p;
        graph[vi]=q;
    }
}
void dfs(int v)
{
    node *w;
    visited[v]=1;
    Tval=Tval+val[v];
    for (w=graph[v]; w; w=w->link)
        if (!visited[w->vertex])
            dfs(w->vertex);
}
void ReG(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        graph[i]=NULL;
        visited[i]=0;
    }
}
int main(void)
{
    int T,n,m;
    int start,max;
    int i,j,u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
            scanf("%d",&val[i]);
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
                insert(u,v);
                insert(v,u);
        }
        max=0;
        for(i=0; i<n; i++)
        {
            Tval=0;
            dfs(i);
           // printf("%d\n",Tval);
            if(Tval>max)
                max=Tval;
        }
        ReG(n);
        printf("%d\n",max);
    }
}
