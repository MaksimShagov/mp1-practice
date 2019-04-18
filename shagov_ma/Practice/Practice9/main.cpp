#include "ToDoList.h"

void main()
{
	ToDoList list;
	int n;
	try
	{
		list.read_tasks();
		list.print_tasks();
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	std::cin >> n;
}