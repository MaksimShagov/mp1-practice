#include "Vector.h"
#include <iostream>
#include <math.h>
#define M_PI  3.14159265358979323846

Vector::Vector()
{
	dim = 0;
	comp = nullptr;
}

Vector::Vector(int _dim)
{
	dim = _dim;
	comp = new double[dim];
	memset(comp, 0, sizeof(double) * dim);
}

Vector::Vector(const Vector & a)
{
	dim = a.dim;
	comp = new double[a.dim];
	memcpy(comp, a.comp, dim);
}

Vector::~Vector()
{
	delete[] comp;
	dim = 0;
}

Vector Vector::operator+(const Vector & a)
{
	Vector tmp(dim);
	if (a.dim != dim)
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
	memcpy(comp, a.comp, dim);
	return *this;
}

Vector Vector::operator-(const Vector & a)
{
	Vector tmp;
	tmp = Vector(dim);
	if (!(a.dim == dim))
	{
		throw 1;
	}
	for (int i = 0; i < tmp.dim; i++)
	{
		tmp.comp[i] = comp[i] - a.comp[i];
	}
	return tmp;
}

Vector& Vector::operator+=(const Vector & a)
{
	*this = *this + a;
	return *this;
}

Vector& Vector::operator-=(const Vector & a)
{
	*this = *this - a;
	return *this;
}

const double& Vector::operator[](int index) const
{
	if (!comp[index]) throw 2;
	return comp[index];
}

double& Vector::operator[](int index)
{
	if (!comp[index]) throw 2;
	return comp[index];
}

Vector Vector::operator*(double a)
{
	Vector tmp(dim);
	if (dim == 0) throw 3;
	for (int i = 0; i < dim; i++)
	{
		tmp.comp[i] = a * comp[i];
	}
	return tmp;
}

Vector Vector::operator/(double a)
{
	Vector tmp(dim);
	if (dim == 0) throw 3;
	for (int i = 0; i < dim; i++)
	{
		tmp.comp[i] = comp[i] / a;
	}
	return tmp;
}

Vector Vector::operator-(double a)
{
	Vector tmp(dim);
	if (dim == 0) throw 3;
	for (int i = 0; i < dim; i++)
	{
		tmp.comp[i] = comp[i] - a;
	}
	return tmp;
}

Vector Vector::operator+(double a)
{
	Vector tmp(dim);
	if (dim == 0) throw 3;
	for (int i = 0; i < dim; i++)
	{
		tmp.comp[i] = comp[i] + a;
	}
	return tmp;
}

double Vector::operator*(const Vector & a)
{
	double scal = 0;
	if (!(a.dim == dim))
	{
		throw 2;
	}
	for (int i = 0; i < a.dim; i++)
	{
		scal += a.comp[i] * comp[i];
	}
	return scal;
}

double Vector::operator*(const Vector & a) const
{
	double scal = 0;
	if (!(a.dim == dim))
	{
		throw 2;
	}
	for (int i = 0; i < a.dim; i++)
	{
		scal += a.comp[i] * comp[i];
	}
	return scal;
}

double Vector::angle(const Vector & a) const
{
	if ((this->lenght() * a.lenght()) == 0)
	{
		throw 4;
	}
	double tmp =  *this*a / (a.lenght() * lenght());
	double angl = acos(tmp) * 180.0 / M_PI;
	return angl;
}

double Vector::lenght() const
{
	double tmp = 0;
	for (int i = 0; i < dim; i++)
	{
		tmp += (comp[i])*(comp[i]);
	}
	double leng = sqrt(tmp);
	return leng;
}

void Vector::print_vector() const
{
	std::cout << "(" ;
	for (int i = 0; i < dim - 1; i++)
	{
		std::cout << comp[i] << ", ";
	}
	std::cout << comp[dim-1] << ")" << std::endl;
}
