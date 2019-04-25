#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void tran(char w[],char name[],int *age,int *sex)
{
    int i,n=0,t=strlen(w),T=0;
    for(i=0; i<t; i++)
    {
        if(w[i]=='"')
        {
            T++;
            continue;
        }
        if(T==1&&n!=-1)
        {
            //printf("%c",w[i]);
            name[n]=w[i];
            n++;
        }
        else if(w[i]<='9'&&w[i]>='0'&&n!=-1)
        {
            name[n]='\0';
            //printf("%s\n",name);
            *age=atoi(&w[i]);
            //printf("%d\n",*age);
            n=-1;
        }
        else if(w[i]=='F'||w[i]=='f'&&n==-1)
        {
            *sex=0;
            //printf("sex %d\n",*sex);
            break;
        }
        else if(w[i]=='M'||w[i]=='m'&&n==-1)
        {
            *sex=1;
            //printf("sex %d\n",*sex);
            break;
        }
    }
}
typedef struct
{
    char name[16];
    int age;
    enum {female,male} sex;
} Reg;
void Copy(Reg a[],Reg b[],int c)
{
    int i,j,n;
    for(i=0; i<c; i++)
    {
        b[i].age=a[i].age;
        n=strlen(&a[i].name);
        for(j=0;; j++)
        {
            if(j==n)
            {
                b[i].name[j]='\0';
                break;
            }
            b[i].name[j]= a[i].name[j];
        }
        b[i].sex=a[i].sex;
    }

}
int main(void)
{
    int Size=1;
    int i=0,j=4;
    char word[500];
    Reg *reg=malloc(Size*sizeof(Reg));
    Reg *T;
    //freopen("123.txt","r",stdin);
    while(1)
    {
        if(i==Size)
        {
            printf("\nqueue/stack full, allocate double size %d\n\n",Size);
            T=reg;
            Reg *temp=realloc(reg, sizeof(Reg)*(Size<<1));
            Copy(T,reg,Size);
            free(T);
            Size<<=1;
        }
        gets(word);
        tran(word,&reg[i].name,&reg[i].age,&reg[i].sex);
        printf("insert record, name: %s, age: %d sex: ",reg[i].name,reg[i].age);
        if(reg[i].sex==1)
            printf("male\n");
        else
            printf("female\n");
        i++;
    }
    /*printf("\n\n");
    for(i=0; i<5; i++)
    {
        printf("insert record, name: %s age: %d sex: ",reg[i].name,reg[i].age);
        if(reg[i].sex==1)
            printf("male\n");
        else
            printf("female\n");
    }*/
}
