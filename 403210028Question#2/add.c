#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    int SUM =0;
    for(i=1; i< argc; i++)
        SUM += atoi(argv[i]);
    printf("%d",SUM);
    return 0;
}
