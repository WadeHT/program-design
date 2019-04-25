#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int Max,n,m,pos[55][3];
    int N,i,j,temp;
    scanf("%d",&n);
    for(N=0; N<n; N++)
    {
        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&pos[i][0],&pos[i][1]);
        }
        Max=0;
        for(i=0; i<m-1; i++)
        {
            for(j=i+1; j<m; j++)
            {
                    temp=abs((pos[i][0]-pos[j][0])*(pos[i][1]-pos[j][1]));
                    if(Max<temp)
                        Max=temp;

            }
        }
        printf("%d\n",Max);
    }
}
