#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Time
{
public:
	unsigned int hour;
	unsigned int min;
	Time();
	Time(unsigned int, unsigned int);
	Time(const Time&);
	~Time();
	const Time& operator=(const Time&);

	friend std::ostream& operator<<(std::ostream&, const Time&);
};

/**************************************/

class Date
{
public:
	unsigned int day;
	unsigned int mon;
	unsigned int year;
	Date();
	Date(unsigned int, unsigned int, unsigned int);
	Date(const Date&);
	~Date();
	const Date& operator=(const Date&);
	bool operator==(const Date&) const;

	friend std::ostream& operator<<(std::ostream&, const Date&);
};

/**************************************/

class Task
{
public:
	Date designated_date;
	std::string ToDo;
	Task();
	virtual ~Task();
	Time set_start(Time);
	Time set_end(Time);

	virtual void print() = 0;
};

/**************************************/

class TypeDay: public Task 
{
public:
	TypeDay();
	~TypeDay();

	virtual void print();
};

/**************************************/

class TypeNoAllDay: public Task
{
public:
	Time designated_time, time_2;
	TypeNoAllDay();
	~TypeNoAllDay();
	Time get_start();
	Time get_end();
	void set_start(Time);
	void set_end(Time);

	virtual void print();
	
};

/**************************************/

class ToDoList
{
public:
	Task** tasks;
	int number;
	void read_tasks(std::string);
	void print_tasks();
	void print_task_date(const Date&) const;
};
