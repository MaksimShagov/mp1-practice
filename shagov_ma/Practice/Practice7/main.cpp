#include "Vector.h"
#include <iostream>
using namespace std;

void main()
{
	Vector a, b, c;
	int s, q, w, i;
	double tmp;
	try
	{
		std::cout << "Введите размерность векторов";
		do
		{
			cin >> q >> w;
			a.create(q);
			for (i = 0; i < a.dim; i++)
			{
				std::cin >> a.comp[i];
			}
			b.create(w);
			for (i = 0; i < b.dim; i++)
			{
				std::cin >> b.comp[i];
			}
			c.create(q);
		} while ((q != 0) && (w != 0));
		a.print_vector();
		a.print_vector();
		cout << "Выберете функцию для сортировки";
		cout << "1 - Сложение. 2 - Разность. 3 - Скалярное произведение векторов. 4 - Угол. 5 - Длина вектора. 6 - Умножение вектора на число";
		cin >> i;
		switch (i)
		{
		case 1:
			c = a + b;
			c.print_vector();
			break;
		case 2:
			c = a - b;
			c.print_vector();
			break;
		case 3:
			tmp = a * b;
			cout << "Скалярное произведение =" << tmp;
			break;
		case 4:
			tmp = a.angle(b);
			cout << "Угол между векторами = " << tmp;
			break;
		case 5:
			cout << "Длину вектора 1 - а, 2 - b";
			cin >> s;
			if (s == 1)
			{
				tmp = a.lenght();
				cout << "Длина вектора а = " << tmp;
			}
			else
			{
				tmp = b.lenght();
				cout << "Длина вектора b = " << tmp;
			}
			break;
		case 6:
			int f;
			cin >> f;
			c = a*f;
			c.print_vector();
			break;
		}
	}
	catch (int k)
	{
		cout << "Вызвано исключение#: " << k << '\n';
	}
}