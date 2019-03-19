#include <iostream>
#include "Polinom.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Polinom l1, l2;
	l1.Add(2, -3);
	l1.Add(1, 6);
	l1.Add(3, 9);
	l1.Add(3, 9);
	l1.Add(3, 9);
	l2.Add(2, -3);
	l2.Add(1, 6);
	l2.Add(3, 9);
	l2.Add(3, 9);
	l2.Add(3, 9);
	l1.Output1();
	l1 = l1/l2;
	l1.Output1();
	int n;
	std::cin >> n;
}