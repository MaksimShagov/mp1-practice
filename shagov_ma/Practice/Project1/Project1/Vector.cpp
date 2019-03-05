#include "Vector.h"

Vector::Vector()
{
	size = 1;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = 0;
}

Vector::Vector(const Vector& x)
{
	size = x.size;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = x.elements[i];
}

Vector::Vector(int _size)
{
	size = _size;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = 0;
}


Vector::Vector(int _size, int* array)
{
	if (array == NULL)
		return;
	size = _size;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = array[i];
}

Vector::~Vector()
{
	size = 0;
	delete []elements;
}

void Vector::PrintVector()
{
	for (int i = 0; i < size; i++)
		std::cout << elements[i] << std::endl;
}

int Vector::getsize()
{
	return size;
}

Vector & Vector::sum(Vector& b)
{
	if (size < b.size) size = b.size;
	for (int i = 0; i < size; i++) elements[i] + b.elements[i];
	return *this;
}

Vector & Vector::dif(Vector& b)
{
	if (size < b.size) size = b.size;
	for (int i = 0; i < size; i++) elements[i] - b.elements[i];
	return *this;
}

int Vector::length()
{
	int t = 0;
	for (int i = 0; i < size; i++) t += sqrt(elements[i]* elements[i]);
	return t;
}

int Vector::scal(Vector& b)
{
	if (size != b.size) return 1;
	int t = 0;
	for (int i = 0; i < size; i++) t += elements[i]*b.elements[i];
	return t;
}

Vector & Vector::operator+(const Vector& b)
{
	Vector tmp(size);
	if (size < b.size) tmp.size = b.size;
	for (int i = 0; i < tmp.size; i++)
		tmp.elements[i] = elements[i] + b.elements[i];
	return tmp;
}

Vector & Vector::operator=(const Vector& b)
{
	size = b.size;
	for (int i = 0; i < size; i++)
		elements[i] = b.elements[i];
	return *this;
}

Vector & Vector::operator-(const Vector& b)
{
	Vector tmp(size);
	if (size < b.size) tmp.size = b.size;
	for (int i = 0; i < tmp.size; i++)
		tmp.elements[i] = elements[i] - b.elements[i];
	return tmp;
}

Vector & Vector::operator*(int a)
{
	for (int i = 0; i < size; i++) elements[i] = elements[i] * a;
	return *this;
}

Vector & Vector::operator/(int a)
{
	for (int i = 0; i < size; i++) elements[i] = elements[i] / a;
	return *this;
}

int Vector::operator*(const Vector & b)
{
	double tmp = 0;
	for (int i = 0; i < size; i++)
		tmp += elements[i] * b.elements[i];
	return tmp;
}

bool Vector::operator==(const Vector & b)
{
	if (size != b.size) return false;
	for (int i = 0; i < size; i++)
		if (elements[i] != b.elements[i]) return false;
}

int& Vector::operator[](int index) //нет проверки исключений
{
	if ((index < size) && (index >= 0))
		return elements[index];
}

const int& Vector::operator[](int index) const //нет проверки исключений
{
	if ((index < size) && (index >= 0))
		return elements[index];
}