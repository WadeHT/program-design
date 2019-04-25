#include<cstdio>
#include<string.h>
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
const char T = 'T';
struct Row
{
	friend istream &operator>>(istream&,Row&);
	friend ostream &operator<<(ostream&,const Row&);
	friend Row operator*(double,const Row&);
	double& operator()(const int)const;
	Row &operator=(const Row&);
	Row operator+(const Row&)const;
	Row operator-(const Row&)const;
	Row operator*(double n)const;
	double operator*(const Row&)const;
	vector<double>row;
	Row(int n);
	~Row();
};
class Matrix
{
	friend istream &operator>>(istream&,Matrix&);
	friend ostream &operator<<(ostream&,const Matrix&);
	friend Matrix I(const int);
	friend Matrix operator*(double,const Matrix&);
	vector<Row>matr;
public:
	int row,col;
	Matrix(const int m=1,const int n=1);
	Matrix(const Matrix&);
	~Matrix();
	double& operator()(const int,const int)const;
	Row &operator()(const int)const;
	Matrix & operator=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix &operator+=(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix &operator-=(const Matrix&);
	Matrix operator^(const char)const;
	Matrix &operator^=(const char);
	Matrix operator*(const Matrix&)const;
	Matrix &operator*=(const Matrix&);
	Matrix operator^(int)const;
	Matrix &operator^=(int);
	Matrix operator*(double)const;
	
};


