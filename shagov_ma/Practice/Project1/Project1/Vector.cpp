#include "Vector.h"

Vector::Vector()
{
	size = 10;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = 0;
}

Vector::Vector(Vector& x)
{
	size = x.size;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = x.elements[i];
}

Vector::Vector(int _size = 10)
{
	size = _size;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = 0;
}


Vector::Vector(int _size, int* array)
{
	if (array == NULL)
		return;
	size = _size;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = array[i];
}

Vector::~Vector()
{
	size = 0;
	delete []elements;
}

void Vector::PrintVector()
{
	for (int i = 0; i < size; i++)
		std::cout << elements[i] << std::endl;
}
/*void Vector::getsize();
{
	
}
*/
