#pragma once

struct Vector
{
	int dim;
	double *comp;
	Vector();
	Vector(int _dim);
	Vector(const Vector& a);
	~Vector();
	Vector operator+(const Vector& a);
	const Vector& operator=(const Vector& a);
	Vector operator-(const Vector& a);
	Vector& operator+=(const Vector& a);
	Vector& operator-=(const Vector& a);
	const double& operator[](int index) const;
	double& operator[](int index);
	Vector operator*(double a);
	Vector operator/(double a);
	Vector operator-(double a);
	Vector operator+(double a);
	double operator*(const Vector& a);
	double operator*(const Vector& a) const;
	double angle(const Vector& a) const;
	double lenght() const;
	void print_vector() const;
};