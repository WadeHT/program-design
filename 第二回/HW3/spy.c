#include<stdio.h>
typedef struct nu
{
    int vertex;
    struct nu *link;
} node;
node *graph[1000005];
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
int main(void)
{
    int T,N;
    int record;
    int i,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(i=1; i<N; i++)
        {
            scanf("%d",&v);
            insert(i,v);
        }
        insert(0,1);
        record=0;
        for(i=N-1; i>0; i--)
        {
            if(graph[i]!=NULL)
            {
                v=graph[i]->vertex;
                if(graph[v]!=NULL)
                {
                    graph[v]=NULL;
                    record++;
                }
                graph[i]=NULL;
            }
        }
        printf("%d\n",record);
    }
}
