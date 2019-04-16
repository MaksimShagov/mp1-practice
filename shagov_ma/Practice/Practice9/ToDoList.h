#pragma once
#include <fstream>
#include <iostream>
class Time
{
	unsigned int hour;
	unsigned int min;
public:
	Time();
	Time(unsigned int, unsigned int);
	Time(const Time&);
	~Time();
	unsigned int getTime_hour();
	unsigned int getTime_min();
	Time putTime_hour(unsigned int);
	Time putTime_min(unsigned int);
	Time operator+(const Time&);
	const Time& operator=(const Time&);
	void print_time();
};

/**************************************/

class Date
{
	unsigned int day;
	unsigned int mon;
	unsigned int year;
public:
	Date();
	Date(unsigned int, unsigned int, unsigned int);
	Date(const Date&);
	~Date();
	unsigned int getDate_day();
	unsigned int getDate_mon();
	unsigned int getDate_year();
	Date putDate_day(unsigned int);
	Date putDate_mon(unsigned int);
	Date putDate_year(unsigned int);
	const Date& operator=(const Date&);
	void print_date();
};

/**************************************/

class Task
{
public:
	Date designated_date;
	char* ToDo;
	Task();
	~Task();
};

/**************************************/

class TypeDay: public Task 
{
public:
	void print_typeDay();
};

/**************************************/

class TypeNoAllDay: public Task
{
private:
	Time designated_time, duration;
public:
	void print_typeNDay();
	void read_typeNDay();
};

/**************************************/

class ToDoList
{
	Task** tasks;
public:
	void read_tasks();
};