#include<stdio.h>
#define true 1;
#define false -1;
int English(char word)
{
    if(word>='a'&&word<='z')
        return word-'a';
    else if(word>='A'&&word<='Z')
        return word-'A';
    else
        return false;
}
void Re(int c[])
{
    int i;
    for(i=0; i<30; i++)
        c[i]=0;
}
int main(void)
{
    int i,j;
    int n,countAZ[30],Max;
    char word;
    scanf("%d\n",&n);
    while(n--)
    {
        Max=0;
        Re(countAZ);
        while(1)
        {
            scanf("%c",&word);
            if(word!='\n')
            {
                if(English(word)>=0)
                {
                    countAZ[English(word)]++;
                    if(Max<countAZ[English(word)])
                        Max=countAZ[English(word)];
                }
            }
            else
                break;
        }
        for(i=0; i<26; i++)
            if(Max==countAZ[i])
                printf("%c",'A'+i);
        printf("\n");
    }
}
