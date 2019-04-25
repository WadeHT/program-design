#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    unsigned long long int d,t;
}LD;
unsigned long long int cmpLit(const void *a,const void *b)
{
    return (*(unsigned long long int*)a)-(*(unsigned long long int*)b);
}
int main(void)
{
    int T,N;
    LD TD[105];
    unsigned long long int t;
    int i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%llu",&TD[i].t);
        }
        for(i=0;i<N;i++)
        {
            scanf("%llu",&TD[i].d);
        }
        qsort(&TD[0].d,N,sizeof(LD),cmpLit);
       /* for(i=0;i<N;i++)
        {
            printf("%llu ",TD[i].t);
        }
        printf("\n");
        for(i=0;i<N;i++)
        {
            printf("%llu ",TD[i].d);
        }*/
        t=0;
        for(i=0;i<N;i++)
        {
            t+=TD[i].t;
            if(t>TD[i].d)
            {
                printf("No\n");
                break;
            }
        }
        if(i==N)
            printf("Yes\n");

    }
}
