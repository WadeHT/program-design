#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0
int Engilsh(char w)
{
    if(w<='z'&&w>='a')
        return true;
    else if(w<='Z'&&w>='A')
        return true;
    else
        return false;
}
int Number(char w)
{
    if(w<='9'&&w>='0')
        return true;
    else
        return false;
}
int At(char word[])
{
    int i,j;
    for(i=0;; i++)
        if(word[i]=='@')
            return i;
}
int Vaild(char word[])
{
    int i=0;
    int L;
    L=strlen(word);
    //printf("\n%d\n",L);
    if(L<3)
    {
        printf("\nFail\n");
        return false;
    }
    if(At(word)>29||At(word)<5)
    {
        printf("\nFail ads has to length between 6 to 30 words\n ");
        return false;
    }
    while(i<L)
    {
       // printf("%c",word[i]);
        if(!(Engilsh(word[i])||Number(word[i])||(word[i]=='@')||(word[i]=='_')||word[i]=='.'))
        {
            printf("\nFail not dot, number, English or _\n");
            return false;
        }
        else if(word[i]=='@')
        {
            if(word[i-1]=='.')
            {
                printf("\nFail after dot is not English or number\n");
                return false;
            }
            break;
        }
        else if(word[i]=='.')
        {
            if(!(Engilsh(word[i-1])||Number(word[i-1])))
            {
                printf("\nFail b4 dot is not English or number\n");
                return false;
            }
            else if(i==0)
            {
                printf("\nFail dot is first\n");
                return false;
            }
        }
        i++;
    }
    // printf("%d %d",i,L);
    if(i==L)
    {
        printf("\nFail no domain\n");
        return false;
    }
    i++;
    while(i<L)
    {
        //printf("%c",word[i]);
        if(!(Engilsh(word[i])||Number(word[i])||(word[i]=='.')||(word[i]=='_')))
        {
            printf("\nFail after @ not dot, number, English or _\n");
            return false;
        }
        else if(word[i]=='.')
        {
            if(!(Engilsh(word[i-1])||Number(word[i-1])))
            {
                printf("\nFail b4 dot is not English or number\n");
                return false;
            }
            else if(i==L-1)
            {
                printf("\nFail dot last\n");
                return false;
            }
        }
        i++;
    }
    printf("\nVaild\n");
    return true;
}

int cmp(const void*e1,const void *e2)
{
    return (*(char*)e1)-(*(char*)e2);
}

int main(void)
{
    char word[100][140];
    int n;
    int i,j,k,L;
    freopen("test.txt","r",stdin);
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s",&word[i][0]);
    }
    for(i=0; i<n; i++)
    {
        printf("%s",&word[i][0]);
        Vaild(&word[i][0]);
    }
    printf("\n\n");
    //qsort(&word[At(word)+1][0],n,sizeof(char)*)

}
