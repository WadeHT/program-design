#include"Gas.cpp"
double determine(Matrix original)
{
	double val = 1;
	Gas(original);
	for(int i=0;i<original.row;i++)val*=original(i,i);
	return val;
}