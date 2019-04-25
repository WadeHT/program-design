#include<stdio.h>
#define HB 1001005
int book[HB];
void Re(int C[],int B)//Âk¹s
{
    int T;
    for(T=0; T<=B; T++)
    {
        C[T]=0;
    }
}

int main()
{
    int p,q,T;
    scanf("%d%d",&p,&q);
    while(q)
    {
        Re(book,q);
        for(T=1;;T++)
        {
            //printf("book[%d=p]=%d\n",p,book[p]);
            if(book[p]>0)
            {
                printf("%d\n",T-book[p]);
                break;
            }
            book[p]=T;
            p=p*10%q;
        }
        scanf("%d%d",&p,&q);
    }
    return 0;
}
