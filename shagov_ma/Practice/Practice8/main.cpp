#include "Matrix.h"
#include <iostream>

int main()
{
	Matrix A(3, 3), B(3, 3), C(2, 2), D(0, 0), F(0, 0);
	A.Rand_elements();
	B.Rand_elements();
	C.Rand_elements();
	std::cout << "Matrix A: ";
	A.Output();
	std::cout << "Matrix B: ";
	B.Output();
	std::cout << "Matrix C: ";
	C.Output();

	std::cout << "\nMatrix element B[2][2]: ";
	try
	{
		std::cout << B[2][2] << "\n";
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "\nMatrix element A[100][41]: ";
	try
	{
		std::cout << A[100][41] << "\n";
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "Matrix addition (A + B): ";
	try
	{
		D = A + B;
		D.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "Matrix addition (A + C): ";
	try
	{
		D = A + C;
		D.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	double x = 3;
	std::cout << "Addition of a matrix with a number (A + " << x << "): ";
	try
	{
		D = A + x;
		D.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "Addition of a matrix with a number (F + " << x << "): ";
	try
	{
		D = F + x;
		D.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "Matrix multiplication (A * B): ";
	try
	{
		D = A * B;
		D.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "Matrix multiplication (A * C): ";
	try
	{
		D = A * C;
		D.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "Matrix multiplication by number (A * " << x << "): ";
	try
	{
		D = A * x;
		D.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "Matrix multiplication by number (F * " << x << "): ";
	try
	{
		D = F * x;
		D.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "Matrix difference (A - B): ";
	try
	{
		D = A - B;
		D.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "Matrix difference (A - C): ";
	try
	{
		D = A - C;
		D.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "Ðàçíîñòü ìàòðèöû è ÷èñëà (A - " << x << "): ";
	try
	{
		C = A - x;
		C.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}

	std::cout << "Matrix and number difference (f - " << x << "): ";
	try
	{
		C = F - x;
		C.Output();
	}
	catch (const char* k)
	{
		std::cout << k;
	}
}
