#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    unsigned long long int start,end;
} Sted;
int cmp(const void *a,const void *b)
{
    if (((Sted*)a)->start<((Sted*)b)->start) return -1;
    else return 1;
}
void Re(Sted L[],int m)
{
    int i;
    for(i=0; i<m; i++)
    {
        L[i].end=0;
        L[i].start=0;
    }
}
int main(void)
{
    int n,m;
    unsigned long long int end,len;
    int i,j;
    Sted L[100000];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            scanf("%llu%llu",&L[i].start,&L[i].end);
        }
        qsort(L,m,sizeof(Sted),cmp);
        end=0;
        len=0;
        for(i=0; i<m; i++)
        {
            if(end<=L[i].start)
            {
                len=len+L[i].end-L[i].start;
                end=L[i].end;
            }
            else if(end<L[i].end)
            {
                len=len+L[i].end-end;
                end=L[i].end;
            }
        }
        printf("%llu\n",len);
        Re(L,m);
    }
}
