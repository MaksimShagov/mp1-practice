#include "Vector.h"


int main()
{
	int *a;
	a = new int[10];
	Vector* Artem = new Vector();
	Vector* Artem1 = new Vector(*Artem);
	Vector* Artem2 = new Vector(10);
	Vector* Artem3 = new Vector(10, a);//Будем знакомы, Артем
	Artem->sum(*Artem1);
	Artem->PrintVector();
	int n;
	std::cin >> n;
}