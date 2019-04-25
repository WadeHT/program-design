#include<stdio.h>
#include<string.h>
int main(void)
{
    int n,sum;
    char num[20];

    int i,j,I,J;

    scanf("%d",&n);
    while(n)
    {
        sum=0;
        for(i=0; i<n; i++)
        {
            scanf("%s",num);
            for(j=strlen(num)-1,J=0; j>=0; J++,j--)
            {

                if(num[j]=='1')
                {
                    I=J;
                    while(((sum>>I)%2)==1)
                    {
                        sum^=(1<<I);
                        I++;
                    }
                    sum|=(1<<I);
                }
            }
           // printf("sum=%d\n",sum);
        }
        printf("%d\n",sum);
        scanf("%d",&n);
    }
}
