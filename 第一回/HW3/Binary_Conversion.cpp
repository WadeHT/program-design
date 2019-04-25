#include<stdio.h>
#include<string.h>
int main(void)
{
    int N;
    char d[50];
    int i,j,n[50],s[50],c[50];
    scanf("%d",&N);
    while(N)
    {
        memset(s,0,sizeof(s));
        for(i=0; i<N; i++)
        {
            scanf("%s",d);
            memset(c,0,sizeof(c));
            memset(n,0,sizeof(n));
            for(j=strlen(d)-1; j>=0; j--)n[strlen(d)-j-1]=d[j]-'0';
            for(j=0; j<20; j++)
            {
                c[j+1]=c[j]&s[j]|s[j]&n[j]|c[j]&n[j];
                s[j]=s[j]^c[j]^n[j];
            }
        }
        j=0;
        for(i=0; i<20; i++)if(s[i])j|=1<<i;
        printf("%d\n",j);
        scanf("%d",&N);
    }
}

