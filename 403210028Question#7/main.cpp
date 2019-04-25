#include<stdio.h>
#include<string.h>
#include<iostream>
//#include"Gas.cpp"
#include"determine.cpp"
using namespace std;
int main(void)
{
	freopen("test.txt","r",stdin);
	Matrix m(3,3);
	cin>>m;
	cout<<determine(m)<<endl;
	return 0;
}
