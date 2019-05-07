#include "Container.h"

int main() 
{
	/*
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
	*/
	Container<int*, 10> a1;
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
	Container<int*, 10> a2(a1);
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
	system("pause");
	return 0;
}