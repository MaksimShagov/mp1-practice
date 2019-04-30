#include "ToDoList.h"

void main()
{
	ToDoList list;

	int n = 0;
	do {
		try
		{
			list.read_tasks();
			n = 1;
		}
		catch (const char* k)
		{
			n = 0;
			std::cout << k << std::endl;
			system("pause");
			return;
		}
	} while (n != 1);

	do {
		try
		{
			list.print_tasks();
			n = 1;
		}
		catch (const char* k)
		{
			n = 0;
			std::cout << k << std::endl;
		}
	} while (n != 1);

	do {
		try
		{
			list.print_task_date();
			n = 1;
		}
		catch (const char* k)
		{
			n = 0;
			std::cout << k << std::endl;
		}
	} while (n != 1);
	system("pause");
}