#pragma once
#include <iostream>
class Vector
{
	int size;
	int* elements;
public:
	Vector();
	Vector(const Vector&);
	Vector(int);
	Vector(int, int*);
	~Vector();
	
	void PrintVector();
	int getsize();
	Vector& sum(Vector&);
	Vector& dif(Vector&);
	int length();
	int scal(Vector&);

	Vector& operator+(const Vector&);
	Vector& operator=(const Vector&);
	Vector& operator-(const Vector&);
	Vector& operator*(int);
	Vector& operator/(int);

	int operator*(const Vector&);
	bool operator==(const Vector&);

	int& operator[](int index);
	const int& operator[](int index) const;
};