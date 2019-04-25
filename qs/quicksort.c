#include<stdio.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define MAX 100000
void qs(int a[],int left,int right)
{
    int pivot,i,j;
    int temp;
    if(left<right)
    {
        i=left;
        j=right+1;
        pivot = a[left];
        do
        {
           do i++; while(a[i]<pivot);
           do j--; while(a[j]>pivot);
           if(i<j) SWAP(a[i],a[j],temp);
        }while(i<j);
        SWAP(a[left],a[j],temp);
        qs(a,left,j-1);
        qs(a,j+1,right);
    }
}
int main(void)
{
    FILE *fptr1=fopen("input.txt","r");
    FILE *fptr2=fopen("output.txt","w");
    int n,i,a[MAX];
    fscanf(fptr1,"%d",&n);
    for(i=0;i<n;i++)
        fscanf(fptr1,"%d",&a[i]);
    qs(a,0,n-1);
    for(i=0;i<n;i++)
        fprintf(fptr2,"%d ",a[i]);
    return 0;
}
