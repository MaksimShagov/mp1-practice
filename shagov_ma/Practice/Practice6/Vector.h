#pragma once

typedef struct 
{
	int dim;
	double* comp;
} Vector;

Vector create(int dim); // ��������
void delete(Vector a);// ��������
Vector sum(Vector a, Vector b);//a+b
Vector sub(Vector a, Vector b);
double scalar(Vector a, Vector b);
double angle(Vector a, Vector b);
double length(Vector a);
Vector null();