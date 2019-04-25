#include<stdio.h>
#include<stdlib.h>
int Cmp(const void *e1,const void *e2)
{
    return (*(int*)e1)-(*(int*)e2);
}
int main(void)
{
    int i,j;
    int T,N,M,student[10005],goods[10005],pay;
    //freopen("testgreedy.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for(i=0; i<N; i++)
        {
            scanf("%d",&goods[i]);
        }
        for(i=0; i<M; i++)
        {
            scanf("%d",&student[i]);
        }
        if(N>M)
        {
            printf("-1\n");
            continue;
        }
        qsort(goods,N,sizeof(int),Cmp);
        qsort(student,M,sizeof(int),Cmp);
        j=0;
        pay=0;
        for(i=0; i<N; i++)
        {
            // printf("%d  %d\n",student[j],goods[i]);
            while(student[j]<goods[i])
            {
                //printf("%d  %d\n",student[j],goods[i]);
                j++;
                if(j>=M)
                {
                    //printf("j= %d  ",j);
                    printf("-1\n");
                    break;
                }
            }
            if(j>=M)
                break;
            pay+=student[j];
            j++;
        }
        if(i==N)
            printf("%d\n",pay);
    }
}
