#include <stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 100005
typedef struct nu
{
    int vertex;
    struct nu *link;
} node;
node *graph[MAX_VERTICES];
int n=0;
int visited[MAX_VERTICES];
unsigned long long int val[5005],max=0;
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
    visited[v]= TRUE;
    if(max<val[v])
        max=val[v];
    for (w=graph[v]; w; w=w->link)
        if (!visited[w->vertex])
            dfs(w->vertex);
}
void ReG(int n)
{
    int i;
    node *q,*p;
    for(i=0; i<n; i++)
    {
        visited[i]=0;
        if(graph[i]!=NULL)
            graph[i]=NULL;
    }
}
int main()

{
    int n,m,t;
    int start[105];
    int i,j,k;
    node *p;
    scanf("%d%d%d",&n,&m,&t);
    while(n+m+t)
    {
        for(i=0; i<t; i++)  scanf("%d",&start[i]);
        for(i=0; i<n; i++)  scanf("%llu",&val[i]);
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&j,&k);
            insert(j,k);
        }
        max=0;
        for(i=0; i<t; i++)
            if(!visited[start[i]])
                dfs(start[i]);
        printf("%llu\n",max);
        ReG(n);
        scanf("%d%d%d",&n,&m,&t);

    }

}
