#include<stdio.h>
#include<stdlib.h>

int Re(int a[],int m)
{
    int i;
    for(i=0; i<m; i++)
        a[i]=0;
    return 0;
}

int main(void)
{
    int m,n,p,q,cell[10001],mem[2][10001];
    int cycle;
    int i,j;
    //freopen("123.txt","r",stdin);
    scanf("%d%d",&m,&n);
    while(n!=0)
    {
        for(i=0; i<m; i++)
        {
            scanf("%d",&cell[i]);
        }
        while(n)
        {
            scanf("%d%d",&p,&q);
            if(q!=1)
                q=0;
            Re(mem,2*10001);
            cycle=1;
            while(1)
            {
                if(mem[q][p]!=0&&(p<m-1)&&(p>0))
                {
                    printf("Cycle %d\n",cycle-mem[q][p]);
                    break;
                }
                else if(p>m-1)
                {
                    printf("Forward\n");
                    break;
                }
                else if(p<0)
                {
                    printf("Backward\n");
                    break;
                }
                mem[q][p]=cycle;
                cycle++;
               // printf("p=%d q= %d cell= %d\n",p,q,cell[p]);
                if((q==0)&&(cell[p]<0)||(q==1)&&(cell[p]>0))
                {
                    p=p+abs(cell[p]);
                    q=1;
                }
                else
                {
                    p=p-abs(cell[p]);
                    q=0;
                }
            }
            n--;
        }
        scanf("%d%d",&m,&n);
    }

}
