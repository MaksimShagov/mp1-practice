#pragma once
#include <fstream>
#include <iostream>
#include <string>

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
	const Time& operator=(const Time&);

	friend std::ostream& operator<<(std::ostream&, const Time&);
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
	bool operator==(const Date&);

	friend std::ostream& operator<<(std::ostream&, const Date&);
};

/**************************************/

class Task
{
public:
	Date designated_date;
	std::string ToDo;
	unsigned int id;
	Task();
	virtual ~Task();

	virtual void print() = 0;
};

/**************************************/

class TypeDay: public Task 
{
public:
	TypeDay();
	~TypeDay();
	Time get_start();
	Time get_end();

	virtual void print();
};

/**************************************/

class TypeNoAllDay: public Task
{
private:
	Time designated_time, time_2;
public:
	TypeNoAllDay();
	~TypeNoAllDay();
	Time get_start();
	Time get_end();
	Time set_start(Time);
	Time set_end(Time);

	virtual void print();
	
};

/**************************************/

class ToDoList
{
public:
	Task** tasks;
	int number;
	int read_number();
	void read_tasks();
	void print_tasks();
	void print_task_date();
};
