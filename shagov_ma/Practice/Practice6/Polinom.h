#pragma once

class Monom
{
public:
	double a;
	int degr;
	Monom* next;
	Monom();
	Monom(const Monom& b);
	~Monom();
	Monom(int, double);
	Monom operator+(Monom&);
	Monom operator*(Monom & x);
	Monom operator=(Monom & x);
	Monom operator/(Monom & x);
	Monom operator-();
	void output_monom();
};

class Polinom
{
	Monom* head;
public:
	Polinom();
	~Polinom();
	void DeleteAll();
	void Add(int, double);
	void Add(Monom b);
	void _Add(Monom b);
	void Output();
	void Output1();
	void Input_Polinom();
	Polinom& operator+(Polinom& b);
	Polinom & operator-(Polinom & b);
	Polinom & operator*(double b);
	Polinom & operator*(Polinom & b);
	Polinom & operator*(Monom & x);
	Monom * SearchDegr(int _degr, Monom * start);
	Monom * SearchMaxDeg(Monom * start);
	Monom * SearchMaxDeg();
	void PlaceBefore(Monom * move, Monom * next);
	void PlaceAfter(Monom * move, Monom * prev);
	void Sort();
	Polinom & operator/(Polinom & b);
	Monom* Search(int);
	void ret_Max(int * k);
	void DeletedNulls();
	void diminution();
	void DeletedMonom(Monom*);
};