#include "ToDoList.h"

using namespace std;

Time::Time()
{
	hour = 0;
	min = 0;
}

Time::Time(unsigned int _hour, unsigned int _min)
{
	if ((_hour >= 24) || (_hour < 0))
	{
		throw "Invalid time - hour";
	}
	if ((_min > 59) || (_min < 0))
	{
		throw "Invalid time - min";
	}
	hour = _hour;
	min = _min;
}

Time::Time(const Time & _Time)
{
	hour = _Time.hour;
	min = _Time.min;
}

Time::~Time()
{
	hour = 0;
	min = 0;
}

const Time & Time::operator=(const Time & _Time)
{
	hour = _Time.hour;
	min = _Time.min;
	return *this;
}

/****************************************************************/

Date::Date()
{
	day = 1;
	mon = 1;
	year = 1;
}

Date::Date(unsigned int _day, unsigned int _mon, unsigned int _year)
{
	if ((_day < 0) || (_day > 31))
	{
		throw "Invalid date - day";
	}
	if ((_mon < 0) || (_mon > 12))
	{
		throw "Invalid date - month";
	}
	if (_year < 0)
	{
		throw "Invalid date - year";
	}
	if (((_year % 400) == 0) || ((_year % 100 != 0) && (_year % 4 == 0)))
	{
		if ((_mon == 2) && (_day > 29))
			throw "Invalid date - month #2";
	}
	else
	{
		if ((_mon == 2) && (_day > 28))
			throw "Invalid date - month #2";
	}
	if ((_mon == 4) || (_mon == 6) || (_mon == 9) || (_mon == 11))
	{
		if (_day >= 31)
		throw "Invalid date - month";
	}
	day = _day;
	mon = _mon;
	year = _year;
}

Date::Date(const Date & _Date)
{
	day = _Date.day;
	mon = _Date.mon;
	year = _Date.year;
}

Date::~Date()
{
	day = 0;
	mon = 0;
	year = 0;
}

const Date & Date::operator=(const Date & _Date)
{
	day = _Date.day;
	mon = _Date.mon;
	year = _Date.year;
	return *this;
}

bool Date::operator==(const Date & x) const
{
	if (day == x.day)
		if (mon == x.mon)
			if (year == x.year) return true;
	return false;
}

/****************************************************************/

Task::Task()
{

}

Task::~Task()
{

}

/****************************************************************/

TypeNoAllDay::TypeNoAllDay()
{

}

TypeNoAllDay::~TypeNoAllDay()
{

}

/****************************************************************/

Time TypeNoAllDay::get_start()
{
	return designated_time;
}

void TypeNoAllDay::set_start(Time x)
{
	designated_time = x;
}

Time TypeNoAllDay::get_end()
{
	return time_2;
}

void TypeNoAllDay::set_end(Time x)
{
	time_2 = x;
}

void TypeNoAllDay::print()
{
	std::cout << ToDo << " " << designated_date;
	std::cout << " start:" << designated_time << " end:" << time_2 << std::endl;
}

/****************************************************************/

TypeDay::TypeDay()
{
	
}

TypeDay::~TypeDay()
{
	
}

void TypeDay::print()
{
	std::cout << ToDo << " " << designated_date << std::endl;
}

/****************************************************************/

void ToDoList::read_tasks(std::string in_string)
{
	std::string buff;
	std::ifstream istm;
	istm.open(in_string);
	if (!istm.is_open())
	{
		throw "No such path";
	}
	char number_tasks[2];
	istm >> number_tasks;
	number = atoi(number_tasks);
	this->tasks = new Task*[number];
	getline(istm, buff);
	for (int i = 0; i < number; i++)
	{
		getline(istm, buff);
		unsigned long _day = stoul(buff.substr(2, 2));
		unsigned long _mon = stoul(buff.substr(5, 2));
		unsigned long _year = stoul(buff.substr(8, 4));
		Date tmp(_day, _mon, _year);
		if (buff.find(':') == std::string::npos)
		{
			Task* Type1 = new TypeDay;
			Type1->designated_date = tmp;
			Type1->ToDo = buff.substr(13);
			tasks[i] = Type1;
		}
		if (buff.find(':') == ':')
		{
			Task* Type2 = new TypeNoAllDay;
			Type2->designated_date = tmp;
			unsigned long _h_start = stoul(buff.substr(13, 2));
			unsigned long _m_start = stoul(buff.substr(16, 2));
			Time _start(_h_start, _m_start);
			Type2->set_start(_start);
			unsigned long _h_end = stoul(buff.substr(19, 2));
			unsigned long _m_end = stoul(buff.substr(22, 2));
			Type2->ToDo = buff.substr(25);
			Time _end(_h_end, _m_end);
			Type2->set_end(_end);
			tasks[i] = Type2;
		}
	}
	istm.close();
}

void ToDoList::print_tasks()
{
	cout << "All tasks: " << endl;
	for (int i = 0; i < number; i++)
		tasks[i]->print();
}

void ToDoList::print_task_date(const Date& tmp) const
{
	int flag = 0;
	for (int i = 0; i < number; i++)
	{
		if (tmp == tasks[i]->designated_date)
		{
			tasks[i]->print();
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "No tasks" << endl;
	}
}

/****************************************************************/

std::ostream & operator<<(std::ostream & out, const Date & _Date)
{
	if (_Date.day < 10)
		out << "0" << _Date.day << ".";
	else
		out << _Date.day << ".";
	if (_Date.mon < 10)
		out << "0" << _Date.mon << ".";
	else
		out << _Date.mon << ".";
	out << _Date.year;
	return out;
}

std::ostream & operator<<(std::ostream & out, const Time & _Time)
{
	if (_Time.hour < 10)
		out << "0" << _Time.hour << ":";
	else
		out << _Time.hour << ":";
	if (_Time.min < 10)
		out << "0" << _Time.min;
	else
		out << _Time.min;
	return out;
}
