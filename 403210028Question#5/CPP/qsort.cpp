#include<iostream>
#include<string.h>
#include<stdlib.h>
template<class T>
int parti(T[],const int,const int,int(*cmp)(const void*,const void*));
template<class T>
void swap(T&, T&);
template<class T>
void quicksort(T A[],const int num,const int sizeOf,int(*cmp)(const void*,const void*))
{
	if(num == 2)
	{
		((*cmp)(&A[0],&A[1])>=0)?swap(A[0],A[1]):swap(A[0],A[0]);
		return;
	}
	else if(num <=1)return;
    int p = parti(A,num,sizeOf,cmp);
    quicksort(A,p,sizeOf,cmp);
    quicksort(&A[p],num-p,sizeOf,cmp);
	return;
}

template<class T>
void swap(T &a,T &b)
{
	T t=a;
	a=b;
	b=t;
	return;
}

template<class T>
int parti(T A[],const int n,const int size,int(*cmp)(const void*,const void*))
{
    int i,j,same=0;
    swap(A[0],A[rand()%n]);
    for(i=1,j=1; i<n; i++)
        if((*cmp)(&A[0],&A[i])>=0)swap(A[j++],A[i]);
    swap(A[0],A[j-1]);
    return j;
}