#pragma once
#include <iostream>
class Vector
{
	int size;
	int* elements;
public:
	Vector();
	Vector(Vector&);
	Vector(int);
	Vector(int, int*);
	~Vector();
	void PrintVector();
	void getsize();
};
