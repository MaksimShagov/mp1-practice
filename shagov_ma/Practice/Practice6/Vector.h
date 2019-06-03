#pragma once
typedef struct 
{
	int dim;
	double* comp;
} Vector;

Vector create(int dim); // создание
void delete(Vector a);// удаление
Vector sum(Vector a, Vector b);//a+b
Vector sub(Vector a, Vector b);
double scalar(Vector a, Vector b, double *scal) const;
double angle(Vector a, Vector b, double *angl) const;
double length(Vector a, double *leng) const;
void print_vector(Vector a) const;