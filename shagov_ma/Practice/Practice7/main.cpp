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
		cout << "������� ����������� ��������: " << endl;
		do
		{
			cout << "�������(a): ";
			cin >> q;
			cout << "�������(b): ";
			cin >> w;
			a = Vector(q);
			for (i = 0; i < a.dim; i++)
			{
				cout << i << " ���������� ������� a: ";
				cin >> a.comp[i];
			}
			b = Vector(w);
			for (i = 0; i < b.dim; i++)
			{
				cout << i << " ���������� ������� b: ";
				cin >> b.comp[i];
			}
			c = Vector(q);
		} while ((q == 0) && (w == 0));
		cout << "������ a: " << endl;
		a.print_vector();
		cout << "������ b: " << endl;
		b.print_vector();
		cout << "������� 1 ��� ��������� ������� ����� �������� a � b. " << endl;
		cout << "������� 2 ��� ��������� ������� �������� �������� a � b. " << endl;
		cout << "������� 3 ��� ��������� ���������� ������������ �������� a � b. " << endl;
		cout << "������� 4 ��� ��������� ���� ����� ��������� a � b. " << endl;
		cout << "������� 5 ��� ��������� ����� ������� a ��� ������� b. " << endl;
		cout << "������� 0 ��� ������ ������ ������." << endl;

		do
		{
			cout << "�������� �����: " << endl;
			cin >> i;
			switch (i)
			{
			case 1:
				c = a + b;
				cout << "������ ����� � + b " << endl;
				c.print_vector();
				break;
			case 2:
				c = a - b;
				cout << "������ �������� � - b " << endl;
				c.print_vector();
				break;
			case 3:
				tmp = a * b;
				cout << "��������� ������������ a � b ����� " << tmp << endl;
				break;
			case 4:
				tmp = a.angle(b);
				cout << "���� ����� ��������� a � b (� ��������) ����� " << tmp << endl;
				break;
			case 5:
				cout << "������� 1 ��� ��������� ����� ������� �, 2 - ��� ��������� ������� b " << endl;
				cin >> s;
				if (s == 1)
				{
					tmp = a.lenght();
					cout << "����� ������� � = " << tmp << endl;
				}
				else if (s == 2)
				{
					tmp = b.lenght();
					cout << "����� ������� b = " << tmp << endl;
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
		cout << "������� ����������#: " << k << '\n';
	}
	int t;
	cin >> t;
}