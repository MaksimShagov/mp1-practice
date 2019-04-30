#include "Container.h"

int main() 
{
	Container<int, 10> a1;
	try
	{
		//a1.print_all();
		a1.Add(1);
		cout << a1[0] << endl;
		cin >> a1[0];
		cout << a1[0] << endl;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
		system("pause");
		return 0;
	}
	system("pause");
	return 0;
}