#include<stdio.h>
#include<stdlib.h>
int cmpL(const void *a,const void *b)
{
    long int t;
    t=(*(long int*)a)-(*(long int*)b);
    if(t<0)//False have to (t==0&&t>0||t<0)
        return -1;
    else
        return 1;
}
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
int parti(void *A[],int n,int size,int(*cmp)(const void*,const void*))
{
    int i,j,same=0;
    swap(A,0,rand()%n);
    j=1;
    for(i=1; i<n; i++)
        if((*cmp)(&A[0],&A[i])>=0)
        {
            if(A[0]==A[i])
                continue;
            swap(A,i,j);
            j++;
        }
    swap(A,0,j-1);
    return j+1;
}
void quicksort(void *A[],int n,int size,int(*cmp)(const void*,const void*))
{
    int p;
    if(n<3)
    {
        if((*cmp)(&A[0],&A[1])>=0)
            swap(A,0,1);
        return;
    }
    p=parti(A,n,size,cmp);
    quicksort(A,p,size,cmp);
    quicksort(&A[p-1],n-p,size,cmp);
}
int main(void)
{
    int i,n;
    long int A[10000];
    // i=parti(A,10,sizeof(long int),cmpL);
    FILE *fptr1=fopen("input.txt","r");
    FILE *fptr2=fopen("output.txt","w");
    fscanf(fptr1,"%d",&n);
    for(i=0;i<n;i++)
        fscanf(fptr1,"%ld",&A[i]);
    quicksort(A,n,sizeof(long int),cmpL);
    for(i=0;i<n;i++)
        fprintf(fptr2,"%ld ",A[i]);

    //for(i=0; i<10; i++)
      //  printf("%d ",A[i]);
}
