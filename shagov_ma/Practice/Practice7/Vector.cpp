#include "Vector.h"
#include <iostream>
#include <math.h>
#define M_PI  3.14159265358979323846

void Vector::create(int user_dim)
{
	int i;
	dim = user_dim;
	if (user_dim == 0)
	{
		throw 3;
	}
	comp = new double[user_dim];
}

void Vector::destr()
{
	dim = 0;
	delete [] comp;
}

Vector & Vector::operator+(const Vector & a)
{
	Vector tmp;
	tmp.create(dim);
	if (!(a.dim == dim))
	{
		throw 1;
	}
	for (int i = 0; i < tmp.dim; i++)
	{
		tmp.comp[i] = a.comp[i] + comp[i];
	}
	return tmp;
}

const Vector & Vector::operator=(const Vector & a)
{
	dim = a.dim;
	delete[] comp;
	comp = new double[dim];
	for (int i = 0; i < dim; i++)
	{
		comp[i] = a.comp[i];
	}
	return *this;
}

Vector & Vector::operator-(const Vector & a)
{
	Vector tmp;
	tmp.create(dim);
	if (!(a.dim == dim))
	{
		throw 1;
	}
	for (int i = 0; i < tmp.dim; i++)
	{
		tmp.comp[i] = a.comp[i] - comp[i];
	}
	return tmp;
}

const Vector & Vector::operator+=(const Vector & a)
{
	return *this = *this + a;
}

const Vector & Vector::operator-=(const Vector & a)
{
	return *this = *this - a;
}

const double Vector::operator[](int index)
{
	if (!comp[index]) throw 2;
	return comp[index];
}


Vector & Vector::operator*(double a)
{
	int i;
	double scal = 0;
	if (dim == 0) throw 3;
	for (i = 0; i < dim; i++)
	{
		comp[i] = a * comp[i];
	}
	return *this;
}

double Vector::operator*(const Vector & a)
{
	int i;
	double scal = 0;
	if (!(a.dim == dim))
	{
		throw 2;
	}
	for (i = 0; i < a.dim; i++)
	{
		scal += a.comp[i] * comp[i];
	}
	return scal;
}

double Vector::angle(Vector & a)
{
	double angl;
	double tmp;
	if ((this->lenght() * a.lenght()) == 0)
	{
		throw 4;
	}
	tmp =  *this*a / (a.lenght() * lenght());
	angl = acos(tmp * 180.0 / M_PI);
	return angl;
}

double Vector::lenght()
{
	double leng;
	int i;
	double tmp = 0;
	for (i = 0; i < dim; i++)
	{
		tmp += (comp[i])*(comp[i]);
	}
	leng = sqrt(tmp);
	return leng;
}

void Vector::print_vector(void)
{
	for (int i = 0; i < dim; i++)
	{
		std::cout << this->comp[i];
	}
}
