#include<stdio.h>
#include<string.h>
int book[1001005];
int main(void)
{
    int p,q,T;
    scanf("%d%d",&p,&q);
    while(q)
    {
        memset(book,0,sizeof(book));
        for(T=1;;T++)
        {
            if(book[p])break;
            book[p]=T;
            p=p*10%q;
        }
        printf("%d\n",T-book[p]);
        scanf("%d%d",&p,&q);
    }
}
