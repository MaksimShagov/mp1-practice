#include "ToDoList.h"

void main()
{
	ToDoList list;
	int n = 0;
	do {
		try
		{
			list.read_tasks();
			list.print_tasks();
			list.print_task_date();
			n = 1;
		}
		catch (const char* k)
		{
			n = 0;
			std::cout << k;
		}
	} while (n != 1);
}