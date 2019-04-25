#include"Matrix.h"
Matrix Gas(Matrix original)
{
	for(int i=0;i<original.row-1;i++)for(int j=i+1;j<original.row;j++)
			original(j) = original(j)-original(i)*(original(j,i)/original(i,i));
	return original;
}