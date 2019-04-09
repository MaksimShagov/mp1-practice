#pragma once
#include <iostream>
class Matrix
{
	int cols;
	int rows;
	double* elements;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	Matrix operator+(const Matrix&);
	Matrix operator+(double);
	Matrix operator-(const Matrix&);
	Matrix operator-(double);
	Matrix operator*(const Matrix&);
	Matrix operator*(double);
	const Matrix& operator=(const Matrix&);
	const double* operator[](int) const;
	double* operator[](int);
	void Output();
	void Input();
	void Rand_elements();
};