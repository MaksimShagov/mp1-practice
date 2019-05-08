#include "Container.h"

int main() 
{
	Container<int, 10> a1;
	cout << "Check Add" << endl;
	for (int i = 0; i < 10; i++)
	{
		a1.Add(i);
	}
	a1.print_all();
	cout << "Check a1[0]" << endl;
	cout << a1[0] << endl;
	cout << "Check delete a1[0]" << endl;
	a1.Delete(0);
	cout << "Check a1[0]" << endl;
	cout << a1[0] << endl;
	cout << "Check a1[0] = 100" << endl;
	a1[0] = 100;
	cout << a1[0] << endl;
	Container<int, 10> a2(a1);
	cout << "Check all a2" << endl;
	a2.print_all();
	try
	{
		cout << "Check a1[11] exception" << endl;
		cout << a1[11] << endl;
	}
	catch (const char *k)
	{
		cout << k << endl;
	}
	try
	{
		cout << "Check a1.Add(20) exception" << endl;
		a1.Add(20);
		a1.Add(20);
	}
	catch (const char *k)
	{
		cout << k << endl;
	}
	try
	{
		cout << "Check Delete exception" << endl;
		for (int i = 0; i < 10; i++)
		{
			a1.Delete(i);
		}
		a1.Delete(0);
	}
	catch (const char *k)
	{
		cout << k << endl;
	}
	Container<int*, 10> b1;
	cout << "Check Add" << endl;
	for (int i = 0; i < 10; i++)
	{
		b1.Add(i);
	}
	b1.print_all();
	cout << "Check b1[0]" << endl;
	cout << b1[0] << endl;
	cout << "Check delete b1[0]" << endl;
	b1.Delete(0);
	cout << "Check b1[0]" << endl;
	cout << b1[0] << endl;
	cout << "Check b1[0] = 100" << endl;
	b1[0] = 100;
	cout << b1[0] << endl;
	Container<int*, 10> b2(b1);
	cout << "Check all b2" << endl;
	b2.print_all();
	try
	{
		cout << "Check b1[11] exception" << endl;
		cout << b1[11] << endl;
	}
	catch (const char *k)
	{
		cout << k << endl;
	}
	try
	{
		cout << "Check b1.Add(20) exception" << endl;
		b1.Add(20);
		b1.Add(20);
	}
	catch (const char *k)
	{
		cout << k << endl;
	}
	try
	{
		cout << "Check Delete exception" << endl;
		for (int i = 0; i < 10; i++)
		{
			b1.Delete(i);
		}
		b1.Delete(0);
	}
	catch (const char *k)
	{
		cout << k << endl;
	}
	system("pause");
	return 0;
}
