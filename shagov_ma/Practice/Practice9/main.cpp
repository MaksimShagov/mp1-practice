#include "ToDoList.h"

void main()
{
	ToDoList list;
	
	int n = 0;
	do {
		try
		{
			std::string in_string;
			std::cout << "Enter the path" << std::endl;
			std::cin >> in_string;
			list.read_tasks(in_string);
			n = 1;
		}
		catch (const char* k)
		{
			n = 0;
			std::cout << k << std::endl;
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
			unsigned int day, mon, year;
			std::cout << "Enter day" << std::endl;
			std::cin >> day;
			std::cout << "Enter month" << std::endl;
			std::cin >> mon;
			std::cout << "Enter year" << std::endl;
			std::cin >> year;
			Date tmp(day, mon, year);
			list.print_task_date(tmp);
			n = 1;
		}
		catch (const char* k)
		{
			n = 0;
			std::cout << k << std::endl;
		}
	} while (n != 1);
}