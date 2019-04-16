#include "ToDoList.h"

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
}

void Time::print_time()
{

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

void Date::print_date()
{
	//
}
