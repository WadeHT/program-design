#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double intergrate(double(*f)(double),double from,double to,double t)
{
    double i,Ans=0.0;
    for(i=from; i<to; i+=t)
        Ans+=f(i);
    return Ans;
}
double axb(double a,double b,double from,double to,double t)
{
    double i,Ans=0.0;
    for(i=from; i<to; i+=t)
        Ans=Ans+(a*i+b);
    return Ans;
}
int main(int avgc,char *avgv[])
{
    double Ans,from,to,t,a,b;
    //char str[50];
    //scanf("%s",str);
    //scanf("%lf%lf%lf",&from,&to,&t);
    if(!strcmp("sin",avgv[1]))
        Ans=intergrate(sin,atof(avgv[2]),atof(avgv[3]),atof(avgv[4]));
    else if(!strcmp("cos",avgv[1]))
        Ans=intergrate(cos,atof(avgv[2]),atof(avgv[3]),atof(avgv[4]));
    else if(!strcmp("axb",avgv[1]))
    {
        Ans=axb(atof(avgv[5]),atof(avgv[6]),atof(avgv[2]),atof(avgv[3]),atof(avgv[4]));
    }
    printf("%lf\n",Ans);
}
