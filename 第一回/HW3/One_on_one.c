#include<stdio.h>
#include<stdlib.h>
int cmpn(const void *e1, const void *e2)
{
    return (*(int*)e2)-(*(int*)e1);
}

int main(void)
{
    int n;
    int win,ncase[2][10001];
    int i,j;
    scanf("%d",&n);
    while(n)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&ncase[0][i]);
        }
        for(i=0; i<n; i++)
        {
            scanf("%d",&ncase[1][i]);
        }
        qsort(&ncase[0][0],n,sizeof(int),cmpn);
        qsort(&ncase[1][0],n,sizeof(int),cmpn);
        win=0;
        i=0;
        for(j=0; j<n; j++)
        {
            while(i<n)
            {
                if(ncase[1][j]>ncase[0][i])
                {
                    win++;
                    i++;
                    break;
                }
                i++;
            }
            if(i==n)
                break;
        }
        printf("%d\n",win);
        scanf("%d",&n);
    }
}
