#include<stdio.h>
#include<stdlib.h>
int cmpLit(const void *a,const void *b)
{
    return (*(int*)a)-(*(int*)b);
}
int sceLes(int len[],int t,int head,int tail)
{
    int i;
    for(i=head; i<=tail; i++)
    {
        if(len[i]>=t)
            break;
    }
    return i-1;
}
int main(void)
{
    int n;
    int len[35],can;
    int i,j,t;
    scanf("%d",&n);
    while(n)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&len[i]);
        }
        qsort(len,n,sizeof(int),cmpLit);
        can=0;
        for(i=0; i<n-2; i++)
        {
            if(len[i]>0)
                for(j=i+1; j<n-1; j++)
                {
                    t=len[i]+len[j];
                    can=can+sceLes(len,t,j+1,n-1)-j;
                }
        }
        printf("%d",can);
        scanf("%d",&n);
        if(n!=0)
            printf("\n");
    }
}
