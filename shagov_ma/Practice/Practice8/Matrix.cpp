#include "Matrix.h"

Matrix::Matrix()
{
	cols = 0;
	rows = 0;
	elements = nullptr;
}

Matrix::Matrix(int _cols, int _rows)
{
	cols = _cols;
	rows = _rows;
	elements = new double[rows * cols];
}

Matrix::Matrix(const Matrix &x)
{
	cols = x.cols;
	rows = x.rows;
	elements = new double[rows * cols];
	memcpy(elements, x.elements, rows*cols);
}

Matrix::~Matrix()
{
	cols = 0;
	rows = 0;
	delete[] elements;
}

Matrix Matrix::operator+(const Matrix & x)
{
	if ((cols != x.cols) || (rows != x.rows)) throw "Cols != rows";
	Matrix tmp(cols, rows);
	for (int i = 0; i < (rows * cols); i++)
	{
		tmp.elements[i] = this->elements[i] + x.elements[i];
	}
	return tmp;
}

Matrix Matrix::operator+(double x)
{
	if ((cols == 0) || (rows == 0)) throw "ERROR cols = rows = 0";
	Matrix tmp(cols, rows);
	for (int i = 0; i < (rows * cols); i++)
	{
		tmp.elements[i] = this->elements[i] + x;
	}
	return tmp;
}

Matrix Matrix::operator-(const Matrix &x)
{
	if ((cols != x.cols) || (rows != x.rows)) throw "Cols != rows";
	Matrix tmp(cols, rows);
	for (int i = 0; i < (rows * cols); i++)
	{
		tmp.elements[i] = this->elements[i] - x.elements[i];
	}
	return tmp;
}

Matrix Matrix::operator-(double x)
{
	if ((cols == 0) || (rows == 0)) throw "ERROR cols = rows = 0";
	Matrix tmp(cols, rows);
	for (int i = 0; i < (rows * cols); i++)
	{
		tmp.elements[i] = this->elements[i] - x;
	}
	return tmp;
}

Matrix Matrix::operator*(const Matrix & x)
{
	if (cols != x.rows) throw "Cols != Rows";
	Matrix tmp(x.cols, rows);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			for (int k = 0; k < tmp.cols; k++)
				tmp.elements[i * cols + j] += elements[i * tmp.cols + k] * x.elements[k * x.cols + j];
	return tmp;
}

Matrix Matrix::operator*(double x)
{
	if ((cols == 0) || (rows == 0)) throw "ERROR cols = rows = 0";
	Matrix tmp(cols, rows);
	for (int i = 0; i < (rows * cols); i++)
	{
		tmp.elements[i] = this->elements[i] * x;
	}
	return tmp;
}

const Matrix & Matrix::operator=(const Matrix & x)
{
	cols = x.cols;
	rows = x.rows;
	delete[] elements;
	elements = new double[rows * cols];
	memcpy(elements, x.elements, rows*cols);
}

const double * Matrix::operator[](int x) const
{
	if (x > rows - 1) throw "There is no such row";
	return elements + x * cols;
}

double * Matrix::operator[](int x)
{
	if (x > rows - 1) throw "There is no such row";
	return elements + x * cols;
}

std::ostream& operator << (std::ostream& s, const Matrix& x)
{
    s << "\n";
	for (int i = 0; i < x.rows; i++)
    {
        s << "| ";
        for (int j = 0; j < x.cols; j++)
            s << x.arr[i * x.cols + j] << " ";
        s << "| \n";
    }
    s << "\n";
    return s;
}

void Matrix::Rand_elements()
{
	double left = 1.0, right = 10.0;
	for (int i = 0; i < rows * cols; i++)
	{
		elements[i] = left + ((double)rand() / RAND_MAX) * 9.0;
	}
}

