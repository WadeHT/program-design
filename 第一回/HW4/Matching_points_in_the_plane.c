#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Cmp(const void *e1,const void *e2)
{
    return (*(unsigned long long int*)e2)-(*(unsigned long long int*)e1);
}
int cmp(const void *e1,const void *e2)
{
    return (*(unsigned long long int*)e1)-(*(unsigned long long int*)e2);
}
int satoi(unsigned long long int x[],char num[])
{
    int i,j,k;
    j=strlen(num);
    // printf("%d\n",j);
    for(i=0,k=0; i<j; i++)
    {
        //printf("%d ",num[i]);
        if(num[i]==32&&i!=j-1)
        {
            x[k]=atoll(&num[i+1]);
            //printf("%llu\n",x[k]);
            k++;
        }
        else if(i==0)
        {
            x[k]=atoll(&num[i]);
            // printf("%llu\n",x[k]);
            k++;
        }
    }
    return k;
}
int main(void)
{
    int i,j,k;
    int n;
    char num[10005];
    unsigned long long int x[1005],y[1005],t0,t1,s;
    double S;
    //freopen("testgreedy.txt","r",stdin);
    scanf("%d\n",&n);
    for(k=0;k<n;k++)
    {
        gets(num);
        satoi(x,num);
        gets(num);
        i=satoi(y,num);
        qsort(x,i,sizeof(unsigned long long int),Cmp);
        qsort(y,i,sizeof(unsigned long long int),cmp);
        t0=x[0]*x[0]+y[0]*y[0];
        t1=x[1]*x[1]+y[1]*y[1];
        S=t0+t1+2*sqrt(t0*t1);
        for(j=2; j<i; j++)
        {
            t0=x[j]*x[j]+y[j]*y[j];
            S=S+t0+2*sqrt(S*t0);
        }
        s=sqrt(S);
        printf("%llu\n",s);
    }
}
