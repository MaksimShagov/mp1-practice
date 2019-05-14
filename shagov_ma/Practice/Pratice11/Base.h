#pragma once
#include <iostream>
#include <string.h>
#include <string>

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

template <typename T, int maxsize>
class Container
{
	T* arr;
	int size;
public:
	Container();
	Container(const T&);
	~Container();
	bool IsFull() const;
	bool IsEmpty() const;
	int find(T) const;
	void Add(T);
	void Delete(T);
	T& operator[](int);
	void print_all();
};

class Address
{
	std::string contry;
	std::string	subject;
	std::string town;
	std::string outside;
	std::string	house;
	std::string flat;
public:
	Address();
	~Address();
	std::string get_contry();
	std::string get_subject();
	std::string get_town();
	std::string get_outside();
	std::string get_house();
	std::string get_flat();
	void set_contry(std::string);
	void set_subject(std::string);
	void set_town(std::string);
	void set_outside(std::string);
	void set_house(std::string);
	void set_flat(std::string);
};

class Fio
{
	std::string Name;
	std::string Surname;
	std::string Patronymic;
public:
	std::string get_Name();
	void set_Name(std::string);
	std::string get_Surname();
	void set_Surname(std::string);
	std::string get_Patronymic();
	void set_Patronymic(std::string);
};

class Pasport
{
	Fio person;
	Container<int, 4> series;
	Container<int, 6> number;
	Date date_of_issue;
	Date birthday;
	std::string issued_by;
	Address	registration;
public:
	Pasport();
	~Pasport();
	int get_series();
	void set_series(int);
	int get_number();
	void set_number(int);
	std::string get_person();
	void set_person(std::string);
};

class Work
{
	std::string	position;
	std::string	subdivision;
	double salary;
	Date last;
	Date start;
};

class Education
{
	std::string name_of_institute;
	std::string specialty;
	std::string type;
	Date date_of_issue;
public:

};

