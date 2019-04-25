#include"Matrix.h"
/***Row****/
istream &operator>>(istream& is,Row& right)
{
	for(int i=0;i<right.row.size();i++)is>>right.row[i];
	return is;
}
ostream &operator<<(ostream& os,const Row& right)
{
	for(int i=0;i<right.row.size();i++)os<<setw(10)<<right.row[i];
	return os;
}
Row operator*(double n,const Row& original)
{
	return original*n;
}
Row Row::operator*(double n)const
{
	Row temp(row.size());
	for(int i=0;i<row.size();i++)temp(i) = row[i]*n;
	return temp;
}
double& Row::operator()(const int n)const
{
	return const_cast<double&>(row[n]);
}
Row& Row::operator=(const Row& Right)
{
	row = Right.row;
	return *this;
}
Row Row::operator-(const Row& Right)const
{
	Row temp(row.size());
	if(Right.row.size()!=row.size())
	{
		cout<<"row size error\n";
		return temp;
	}
	for(int i=0;i<Right.row.size();i++)temp.row[i] = row[i]-Right.row[i];
	return temp;
}
double Row::operator*(const Row& Right)const
{
	double temp = 0;
	if(Right.row.size()!=row.size())
	{
		cout<<"row size error\n";
		return temp;
	}
	for(int i=0;i<Right.row.size();i++)temp += row[i]*Right.row[i];
	return temp;
}
Row Row::operator+(const Row& Right)const
{
	Row temp(row.size());
	if(Right.row.size()!=row.size())
	{
		cout<<"row size error\n";
		return temp;
	}
	for(int i=0;i<Right.row.size();i++)temp.row[i] = row[i]+Right.row[i];
	return temp;
}
Row::Row(int n):row(n){}
Row::~Row(){}
/****Matrix****/
Matrix::Matrix(const int m,const int n):row(m),col(n),matr(m,n){}
Matrix::Matrix(const Matrix& right):matr(right.matr),row(right.row),col(right.col){}
Matrix::~Matrix(){}
Row& Matrix::operator()(const int m)const
{
	return const_cast<Row&>(matr[m]);
}
double& Matrix::operator()(const int m,const int n)const
{
	return const_cast<double&>(matr[m](n));
}
Matrix& Matrix::operator=(const Matrix &right)
{
	if(&right == this)return *this;
	row = right.row;col = right.col;
	matr = right.matr;
	return *this;
}
Matrix Matrix::operator+(const Matrix& right)
{
	Matrix temp(row,col);
	if(right.matr.size()!=matr.size())
	{
		cout<<"colum error\n";
		return temp;
	}
	for(int i=0;i<matr.size();i++)temp.matr[i] = matr[i]+right.matr[i];
	return temp;
}
Matrix& Matrix::operator+=(const Matrix& right)
{
	*this = *this+right;
	return *this;
}
Matrix Matrix::operator^(const char tran)const
{
	Matrix temp(col,row);
	if(tran != 'T' && tran != 't')
	{
		cout<<"invalid operator\n";
		return temp;
	}
	for(int i=0;i<row;i++)for(int j=0;j<col;j++)temp(j,i) = matr[i](j);
	return temp;
}
Matrix& Matrix::operator^=(const char tran)
{
	*this = *this^tran;
	return *this;
}
Matrix Matrix::operator*(const Matrix& right)const
{
	Matrix temp(row,right.col),rightT(right^T);
	if(col != right.row)
	{
		cout<<"invalid inner_product\n";
		return temp;
	}
	for(int i=0;i<temp.row;i++)for(int j=0;j<temp.col;j++)temp(i,j) = (*this)(i)*rightT(j);
	return temp;
}
Matrix Matrix::operator*(double n)const
{
	Matrix temp(*this);
	for(int i=0;i<row;i++)temp(i) = matr[i]*n;
	return temp;
}
Matrix operator*(double n,const Matrix& original)
{
	return original*n;
}
Matrix& Matrix::operator*=(const Matrix& right)
{
	*this = *this * right;
	return *this;
}
Matrix I(const int n)
{
	Matrix temp(n,n);
	for(int i=0;i<n;i++)temp(i,i) = 1;
	return temp;
}
Matrix Matrix::operator^(int n)const
{
	Matrix temp(I(row)),now(*this);
	if(row != col)
	{
		cout<<"row not equal to col\n";
		return temp;
	}
	while(n>0)
	{
		if(n&1)temp *= now;
		now = now*now;
		n>>=1;
	}
	return temp;
}
Matrix& Matrix::operator^=(int n)
{
	*this = *this^n;
	return *this;
}
istream &operator>>(istream& is,Matrix& right)
{
	for(int i=0;i<right.row;i++)is>>right.matr[i];	
	return is;
}
ostream &operator<<(ostream& os,const Matrix& right)
{
	for(int i=0;i<right.row;i++)os<<right.matr[i]<<endl;
	return os;
}
