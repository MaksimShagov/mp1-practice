#pragma once

struct Vector
{
	int dim;
	double *comp;
	void create(int dim);
	void destr();
	Vector& operator+(const Vector& a);
	const Vector& operator=(const Vector& a);
	Vector& operator-(const Vector& a);
	const Vector& operator+=(const Vector& a);
	const Vector& operator-=(const Vector& a);
	const double operator[](int index);
	Vector& operator*(double a);
	double operator*(const Vector& a);
	double angle( Vector& a);
	double lenght();
	void print_vector();
};