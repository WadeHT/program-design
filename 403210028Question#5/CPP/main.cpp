#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"qsort.cpp"
using namespace std;
int cmpL(const void *a,const void *b)
{
    long int t;
    t=(*(long int*)a)-(*(long int*)b);
    if(t<0)//False have to (t==0&&t>0||t<0)
        return -1;
    else
        return 1;
}
int main(void)
{
	int n;
    long int A[10000];
    FILE *fptr1=fopen("input.txt","r");
	fscanf(fptr1,"%d",&n);
    FILE *fptr2=fopen("output.txt","w");
    for(int i=0;i<n;i++)fscanf(fptr1,"%ld",&A[i]);
    quicksort(A,n,sizeof(long int),cmpL);
    for(int i=0;i<n;i++)fprintf(fptr2,"%ld ",A[i]);
}