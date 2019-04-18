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

unsigned int Time::getTime_hour()
{
	return hour;
}

unsigned int Time::getTime_min()
{
	return min;
}

Time Time::putTime_hour(unsigned int _hour)
{
	if ((_hour >= 24) || (_hour < 0))
	{
		throw "Invalid time - hour";
	}
	hour = _hour;
	return *this;
}

Time Time::putTime_min(unsigned int _min)
{
	if ((_min > 59) || (_min < 0))
	{
		throw "Invalid time - min";
	}
	min = _min;
	return *this;
}

Time Time::operator+(const Time & _Time)
{
	Time tmp(hour, min);
	if (min + _Time.min >= 60)
	{
		tmp.hour++;
		tmp.min = (min + _Time.min) % 60;
	}
	if (tmp.hour + _Time.hour >= 24)
	{
		tmp.hour = (tmp.hour + _Time.hour) % 24;
		//Date++;
	}
	return tmp;
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

unsigned int Date::getDate_day()
{
	return day;
}

unsigned int Date::getDate_mon()
{
	return mon;
}

unsigned int Date::getDate_year()
{
	return year;
}

Date Date::putDate_day(unsigned int _day)
{
	if ((_day < 0) || (_day > 31))
	{
		throw "Invalid date - day";
	}
	if (((year % 400) == 0) || ((year % 100 != 0) && (year % 4 == 0)))
	{
		if ((mon == 2) && (_day > 29))
			throw "Invalid date - month #2";
	}
	if ((mon == 4) || (mon == 6) || (mon == 9) || (mon == 11))
	{
		if (_day >= 31)
			throw "Invalid date - month";
	}
	day = _day;
	return *this;
}

Date Date::putDate_mon(unsigned int _mon)
{
	if ((_mon < 0) || (_mon > 12))
	{
		throw "Invalid date - month";
	}
	mon = _mon;
	return *this;
}

Date Date::putDate_year(unsigned int _year)
{
	if (_year < 0)
	{
		throw "Invalid date - year";
	}
	year = _year;
	return *this;
}

const Date & Date::operator=(const Date & _Date)
{
	day = _Date.day;
	mon = _Date.mon;
	year = _Date.year;
	return *this;
}

Task::Task()
{
	id = 0;
}

Task::~Task()
{
	id = 0;
	ToDo = nullptr;
	designated_date.putDate_day(0);
	designated_date.putDate_mon(0);
	designated_date.putDate_year(0);
}

Time Task::set_start(Time x)
{
	return Time();
}

Time Task::set_end(Time x)
{
	return Time();
}

TypeNoAllDay::TypeNoAllDay()
{
	id = 2;
	ToDo = nullptr;
}

TypeNoAllDay::~TypeNoAllDay()
{
	id = 2;
	ToDo = nullptr;
}

Time TypeNoAllDay::get_start()
{
	return designated_time;
}

Time TypeNoAllDay::set_start(Time x)
{
	designated_time = x;
	return x;
}

Time TypeNoAllDay::get_end()
{
	return time_2;
}

Time TypeNoAllDay::set_end(Time x)
{
	time_2 = x;
	return x;
}

void TypeNoAllDay::print()
{
	std::cout << " " << ToDo << " " << designated_date << " start:" << designated_time << " end:" << time_2 << std::endl;
}

TypeDay::TypeDay()
{
	id = 1;
}

TypeDay::~TypeDay()
{
	id = 1;
	ToDo = nullptr;
}

Time TypeDay::get_start()
{
	return Time();
}

Time TypeDay::get_end()
{
	return Time();
}

void TypeDay::print()
{
	std::cout << ToDo << " " << designated_date << std::endl;
}

int ToDoList::read_number()
{
	char number_tasks[2];
	std::ifstream istm;
	istm.open("test.txt");
	if (!istm.is_open())
	{
		throw "1";
	}
	istm >> number_tasks;
	number = atoi(number_tasks);
}

void ToDoList::read_tasks()
{
	read_number();
	std::string buff;
	std::ifstream istm;
	istm.open("test.txt");
	this->tasks = new Task*[number];
	getline(istm, buff);
	for (int i = 0; i < number; i++)
	{
		getline(istm, buff);
		char _type = (char)stoul(buff);
		unsigned long _day = stoul(buff.substr(2, 2));
		unsigned long _mon = stoul(buff.substr(5, 2));
		unsigned long _year = stoul(buff.substr(8, 4));
		Date tmp(_day, _mon, _year);
		if (_type == 1)
		{
			Task* Type1 = new TypeDay;
			Type1->designated_date = tmp;
			Type1->ToDo = buff.substr(13);
			tasks[i] = Type1;
		}
		if (_type == 0)
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
	for (int i = 0; i < number; i++)
		tasks[i]->print();
}

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
