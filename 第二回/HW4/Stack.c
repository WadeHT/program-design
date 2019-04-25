#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return (*(int *)b)-(*(int *)a);
}
typedef struct
{
    int w,h;
} Block;
int main(void)
{
    int T,n,d1,d2;
    int high;
    Block block[12005];
    int i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0; i<2*n; i+=2)
        {
            scanf("%d%d",&d1,&d2);
            block[i].h=d1;
            block[i].w=d2;
            block[i+1].h=d2;
            block[i+1].w=d1;
        }
        qsort(block,2*n,sizeof(Block),cmp);
        j=0;
        high=0;
        for(i=0; i<2*n; i++)
        {
            if(block[i].w<block[j].w)
            {
                high+=block[j].h;
                j=i;
               // printf("\n..%d %d\n",i,2*n-1);
                if(i>=2*n-1)
                    high+=block[j].h;
            }
            else if(block[j].w==block[i].w)
            {
                //printf("\n%d %d\n",i,2*n-1);
                if(block[j].h<block[i].h)
                {
                    j=i;
                }
                if(i>=2*n-1)
                    high+=block[j].h;
            }
        }
        printf("%d\n",high);
    }
}
