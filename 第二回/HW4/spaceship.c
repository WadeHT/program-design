#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int up,low;
} Road;
void Re(int n,Road road[])
{
    int i;
    for(i=0; i<n; i++)
    {
        road[i].up=0;
        road[i].low=0;
    }
}
int main(void)
{
    int n;
    int up,low;
    Road road[1005],min[1005];
    int i;
    scanf("%d",&n);
    while(n)
    {
        Re(n,min);
        for(i=0; i<n; i++)
            scanf("%d%d",&road[i].up,&road[i].low);
        min[0].up=abs(road[0].up-1000);
        min[0].low=abs(road[0].low-1000);
        i=0;
        //printf("%d %d\n",min[i].up,min[i].low);
        for(i=1; i<n; i++)
        {
            up=abs(road[i].up-road[i-1].up)+min[i-1].up;
            low=abs(road[i].up-road[i-1].low)+min[i-1].low;
            if(up<low)
                min[i].up=up;
            else
                min[i].up=low;
            up=abs(road[i].low-road[i-1].up)+min[i-1].up;
            low=abs(road[i].low-road[i-1].low)+min[i-1].low;
            if(up<low)
                min[i].low=up;
            else
                min[i].low=low;
          //  printf("%d %d\n",min[i].up,min[i].low);
        }
        if(min[n-1].low<min[n-1].up)
            printf("%d\n",min[n-1].low);
        else
            printf("%d\n",min[n-1].up);
        scanf("%d",&n);
    }
}
