#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M_PI  3.14159265358979323846

Vector create(int dim)
{
	int i;
	Vector a;
	a.dim = dim;
	a.comp = (double*)malloc(dim * (sizeof(double)));
	for (i = 0; i < dim; i++)
	{
		scanf("%lf", &a.comp[i]);
	}
	return a;
}

void delete(Vector a)
{
	a.dim = 0;
	free(a.comp);
}

Vector sum(Vector a, Vector b)
{
	Vector tmp = create(a.dim);
	int i;
	if (!(a.dim == b.dim))
	{
		printf("\nОшибка сложения векторов - разная размерность");
		return null();
	} 
	for (i = 0; i < tmp.dim; i++)
	{
		tmp.comp[i] = a.comp[i] + b.comp[i];
	}
	return tmp;
}

Vector sub(Vector a, Vector b)
{
	Vector tmp = create(a.dim);
	int i;
	if (!(a.dim == b.dim))
	{
		printf("\nОшибка сложения векторов - разная размерность");
		return null();
	}
	for (i = 0; i < tmp.dim; i++)
	{
		tmp.comp[i] = a.comp[i] - b.comp[i];
	}
	return tmp;
}

double scalar(Vector a, Vector b)
{
	int i;
	double scal = 0;
	if (!(a.dim == b.dim))
	{
		printf("\nОшибка сложения векторов - разная размерность");
		return 0;
	}
	for (i = 0; i < a.dim; i++)
	{
		scal += a.comp[i] * b.comp[i];
	}
	return scal;
}

double angle(Vector a, Vector b)
{
	double angl;
	double tmp;
	if (length(a)*length(b) == 0)
	{
		printf("\nОшибка вычисления угла между векторами - нулевая длина вектора");
		return 0;
	}
	tmp = scalar(a, b) / (length(a)*length(b));
	angl = acos(tmp * 180.0 / M_PI);
	return angl;
}

double length(Vector a)
{
	double leng;
	int i;
	double tmp = 0;
	for (i = 0; i < a.dim; i++)
	{
		tmp += (a.comp[i])*(a.comp[i]);
	}
	leng = sqrt(tmp);
	return leng;
}

Vector null()
{
	Vector Null;
	Null.dim = 0;
	Null.comp = NULL;
	return Null;
}
