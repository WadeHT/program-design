#include<stdio.h>
int main(void)
{
    unsigned long long int x,y,p,r;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        r=1;
        scanf("%llu%llu%llu",&x,&y,&p);
        while(y)
        {
            if(y&1)r=r*x%p;
            x=(x%p)*(x%p)%p;
            y>>=1;
        }
        printf("%llu\n",r);
    }
}
