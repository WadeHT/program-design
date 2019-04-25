#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n,m,p[55][2];
    int i,j,Max;
    scanf("%d",&n);
    while(n--)
    {
        Max=0;
        scanf("%d",&m);
        for(i=0;i<m;i++)scanf("%d%d",&p[i][0],&p[i][1]);
        for(i=0;i<m-1;i++)for(j=i+1;j<m;j++)if(Max<abs((p[i][0]-p[j][0])*(p[i][1]-p[j][1])))Max=abs((p[i][0]-p[j][0])*(p[i][1]-p[j][1]));
        printf("%d\n",Max);
    }
}

