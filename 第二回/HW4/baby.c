#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int start,end;
} Time;
int cmp(const void *a,const void *b)
{
    return (*(int*)a)-(*(int*)b);
}
int main(void)
{
    int m;
    int Ans;
    Time time[55];
    char num[25];
    int now,Mend;
    int i,j;
    scanf("%d\n",&m);
    while(m--)
    {
        gets(num);
        j=0;
        while(num[0])
        {
            sscanf(num,"%d %d",&time[j].start,&time[j].end);
            if(time[j].start>time[j].end)time[j].end^=time[j].start^=time[j].end;
            j++;
            if(gets(num)==NULL)break;
        }
        qsort(time,j,sizeof(Time),cmp);
        now=0;
        Ans=1;
        if(j>1)
        {
            Ans=2;
            for(i=1; time[i].start==time[0].start; i++)
            {
                if(time[i].end>time[now].end)
                    now=i;
            }
            Mend=now;
            for(; i<j; i++)
            {
                if(time[i].start<=time[now].end+1)
                {
                    if(time[i].end>time[Mend].end)
                    {
                        Mend=i;
                    }
                }
                else
                {
                    now=Mend;
                    Mend=i;
                    Ans++;
                }
                if(time[Mend].end==199)
                {
                    break;
                }
            }
        }
        printf("%d\n",Ans);
    }
}
