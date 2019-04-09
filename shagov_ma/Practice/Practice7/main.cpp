#include "Vector.h"
#include <iostream>
using namespace std;

void main()
{
	Vector a, b, c;
	setlocale(LC_ALL, "Rus");
	int s, q = 1, w = 1, i;
	double tmp;
	try
	{
		cout << "Введите размерность векторов: " << endl;
		do
		{
			cout << "Первого(a): ";
			cin >> q;
			cout << "Второго(b): ";
			cin >> w;
			a = Vector(q);
			for (i = 0; i < a.dim; i++)
			{
				cout << i << " координата вектора a: ";
				cin >> a.comp[i];
			}
			b = Vector(w);
			for (i = 0; i < b.dim; i++)
			{
				cout << i << " координата вектора b: ";
				cin >> b.comp[i];
			}
			c = Vector(q);
		} while ((q == 0) && (w == 0));
		cout << "Вектор a: " << endl;
		a.print_vector();
		cout << "Вектор b: " << endl;
		b.print_vector();
		cout << "Введите 1 для получения вектора суммы векторов a и b. " << endl;
		cout << "Введите 2 для получения вектора разности векторов a и b. " << endl;
		cout << "Введите 3 для получения скалярного произведения векторов a и b. " << endl;
		cout << "Введите 4 для получения угла между векторами a и b. " << endl;
		cout << "Введите 5 для получения длины вектора a или вектора b. " << endl;
		cout << "Введите 0 для отмены выбора режима." << endl;

		do
		{
			cout << "Выберите режим: " << endl;
			cin >> i;
			switch (i)
			{
			case 1:
				c = a + b;
				cout << "Вектор суммы а + b " << endl;
				c.print_vector();
				break;
			case 2:
				c = a - b;
				cout << "Вектор разности а - b " << endl;
				c.print_vector();
				break;
			case 3:
				tmp = a * b;
				cout << "Скалярное произведение a и b равно " << tmp << endl;
				break;
			case 4:
				tmp = a.angle(b);
				cout << "Угол между векторами a и b (в градусах) равен " << tmp << endl;
				break;
			case 5:
				cout << "Введите 1 для получения длины вектора а, 2 - для получение вектора b " << endl;
				cin >> s;
				if (s == 1)
				{
					tmp = a.lenght();
					cout << "Длина вектора а = " << tmp << endl;
				}
				else if (s == 2)
				{
					tmp = b.lenght();
					cout << "Длина вектора b = " << tmp << endl;
				}
				break;
			case 6:
				int f;
				cin >> f;
				c = a * f;
				c.print_vector();
				break;
			}
		} while (i != 0);
	}
	catch (int k)
	{
		cout << "Вызвано исключение#: " << k << '\n';
	}
	int t;
	cin >> t;
}