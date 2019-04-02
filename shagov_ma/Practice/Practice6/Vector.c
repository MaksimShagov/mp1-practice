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
	if (dim == 0)
	{
		printf("\nОшибка создания вектора - размер равен нулю");
		a.comp = NULL;
		return a;
	}
	a.dim = dim;
	a.comp = (double*)malloc(dim * (sizeof(double)));
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
		tmp.comp = nullptr;
		return tmp;
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
		printf("\nОшибка при вычислении разности векторов - разная размерность");
		tmp.comp = nullptr;
		return tmp;
	}
	for (i = 0; i < tmp.dim; i++)
	{
		tmp.comp[i] = a.comp[i] - b.comp[i];
	}
	return tmp;
}

double scalar(Vector a, Vector b, int *flag)
{
	int i;
	double scal = 0;
	if (!(a.dim == b.dim))
	{
		printf("\nОшибка при скалярном умножении векторов - разная размерность");
		*flag = 0;
		return 0;
	}
	for (i = 0; i < a.dim; i++)
	{
		scal += a.comp[i] * b.comp[i];
	}
	*flag = 1;
	return scal;
}

double angle(Vector a, Vector b, int *flag)
{
	double angl;
	double tmp;
	if (length(a, flag)*length(b, flag) == 0)
	{
		printf("\nОшибка вычисления угла между векторами - нулевая длина вектора");
		*flag = 0;
		return 0;
	}
	tmp = scalar(a, b, flag) / (length(a)*length(b));
	angl = acos(tmp * 180.0 / M_PI);
	flag = 1;
	return angl;
}

double length(Vector a, int *flag)
{
	double leng;
	int i;
	double tmp = 0;
	if (a.dim != 0)
	{
		for (i = 0; i < a.dim; i++)
		{
			tmp += (a.comp[i])*(a.comp[i]);
		}
		leng = sqrt(tmp);
		*flag = 1;
		return leng;
	}
	*flag = 0;
}

void print_vector(Vector a)
{
	int i = 0;
	for (i = 0; i < a.dim; i++)
	{
		printf("%lf\n", &a.comp[i]);
	};
}