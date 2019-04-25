#include<stdio.h>
#include<ctype.h>
#include<string.h>
void Re(char str[],int n)
{
    int i;
    for(i=0; i<n; i++)
        str[i]='\0';
}
int main(void)
{
    int i;
    char wor[10000];
    Re(wor,10000);
    while(gets(wor))
    {
        for(i=0; wor[i]!='\0'; i++)
        {
            if(wor[i]<='8'&&wor[i]>='0')
                wor[i]++;
            else if(wor[i]=='9')
                wor[i]='0';
            else if(wor[i]<='Z'&&wor[i]>='A')
                wor[i]='z'+'A'-wor[i];
            else if(wor[i]<='z'&&wor[i]>='a')
                wor[i]='Z'+'a'-wor[i];
        }
        printf("%s\n",wor);
        Re(wor,i);
    }
}
