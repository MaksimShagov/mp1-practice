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
		std::cout << "������� ����������� ��������";
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
		cout << "�������� ������� ��� ����������";
		cout << "1 - ��������. 2 - ��������. 3 - ��������� ������������ ��������. 4 - ����. 5 - ����� �������. 6 - ��������� ������� �� �����";
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
			cout << "��������� ������������ =" << tmp;
			break;
		case 4:
			tmp = a.angle(b);
			cout << "���� ����� ��������� = " << tmp;
			break;
		case 5:
			cout << "����� ������� 1 - �, 2 - b";
			cin >> s;
			if (s == 1)
			{
				tmp = a.lenght();
				cout << "����� ������� � = " << tmp;
			}
			else
			{
				tmp = b.lenght();
				cout << "����� ������� b = " << tmp;
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
		cout << "������� ����������#: " << k << '\n';
	}
}