#include "Polinom.h"
#include <iostream>	

Monom::Monom()
{
	next = nullptr;
	degr = 0;
	a = 0.0;
}

Monom::Monom(const Monom& b)
{
	next = b.next;
	degr = b.degr;
	a = b.a;
}

Monom::~Monom()
{

}

Monom::Monom(int v, double q)
{
	a = q;
	degr = v;
	next = nullptr;
}

Monom Monom::operator+(Monom & x)
{
	Monom tmp;
	tmp.next = this->next;
	tmp.a = this->a + x.a;
	return tmp;
}

Monom Monom::operator*(Monom & x)
{
	Monom tmp;
	tmp.a = this->a * x.a;
	tmp.degr = this->degr * x.degr;
	return tmp;
}

Monom Monom::operator=(Monom & x)
{
	next = x.next;
	a = x.a;
	degr = x.degr;
	return *this;
}

Monom Monom::operator/(Monom & x)
{
	Monom tmp;
	tmp.a = a / x.a;
	tmp.degr = degr - x.degr;
	return tmp;
}

Monom Monom::operator-()
{
	a = -a;
	return Monom();
}

void Monom::output_monom()
{ 
	if (degr == 0)
	{
		std::cout << "+" << a;
		return;
	}
	std::cout << std::showpos << a << "X^" << std::noshowpos << degr;
}

Polinom::Polinom()
{
	head = nullptr;
}

Polinom::~Polinom()
{
	DeleteAll();
}

void Polinom::DeleteAll()
{
	Monom* i = head;
	Monom* del = i;
	while (i != nullptr)
	{
		i = i->next;
		delete del;
		del = i;
	}
	head = nullptr;
}

void Polinom::Add(int v, double q)
{
	Monom* i;
	if (!head) head = new Monom(v, q);
	else
	{
		for (i = head; i->next != 0; i = i->next){}
		i->next = new Monom(v, q);
	}
}

void Polinom::Add(Monom b)
{
	Monom* i;
	if (!head) head = new Monom(b);
	else
	{
		for (i = head; i->next != 0; i = i->next) {}
		i->next = new Monom(b);
	}
	diminution();
}

void Polinom::_Add(Monom b)
{
	Monom* i;
	if (!head) head = new Monom(-b);
	else
	{
		for (i = head; i->next != 0; i = i->next) {}
		i->next = new Monom(-b);
	}
}

void Polinom::Output()
{
	Monom* i = head;
	int k;
	ret_Max(&k);
	if (!head) std::cout << "Полином пуст" << std::endl;
	for (; k >= 0; k--)
	{
		i = Search(k);
		if (i == nullptr) continue;
		i->output_monom();
		std::cout << std::endl;
	}
}

void Polinom::Output1()
{
	if (!head)
	{
		std::cout << "Ïîëèíîìà íåò.";
	}
	else
	{
		for (Monom* i = head; i; i = i->next)
			if (i->degr == 0)
				std::cout << "+" << std::noshowpoint << i->a;
			else
				std::cout << "+" << std::noshowpoint << i->a << "X^(" << i->degr << ")";
	}
	std::cout << std::endl;
}

void Polinom::Input_Polinom()
{
	int v;
	double q;
	Monom* i;
	q = 1;
	for (i = head; i->next != 0; i = i->next) {}
	while (1)
	{
		std::cout << "Введите коэфициент и степень ";
		std::cin >> q >> v;
		if (q == 0) break;
		i->next = new Monom(v, q);
		i = i->next;
	}
	diminution();
}

Monom* Polinom::Search(int v)
{
	Monom* i;
	if (!head) return nullptr;
	for (i = head; i; i = i->next)
	{
		if (i->degr == v) return i;
	}
	return nullptr;
}

void Polinom::ret_Max(int *k)
{
	Monom* i;
	int max = 0;
	for (i = head; i; i = i->next)
	{
		if (i->degr > max) max = i->degr;
	}
	*k = max;
}

void Polinom::DeletedNulls()
{
	Monom* i;
	for (i = head; i; i = i->next)
	{
		if (i->a == 0)
		{
			DeletedMonom(i);
		}
	}
}

void Polinom::diminution()
{
	if (!head)
		return;
	for (Monom* i = head; i; i = i->next)
	{
		while (Monom* temp = SearchDegr(i->degr, i->next))
		{
			i->a += temp->a;
			DeletedMonom(temp);
		}
	}
}

void Polinom::DeletedMonom(Monom* k)
{
	if (!head)
		return;
	for (Monom* i = head; i; i = i->next)
	{
		if (i->next == k)
		{
			i->next = k->next;
			delete k;
		}
	}
}

Polinom & Polinom::operator+(Polinom & b)
{
	if (!head)
		return *this;
	else
	{
		Polinom* tmp = new Polinom(*this);
		for (Monom* i = b.head; i; i = i->next)
		{
			Monom* tm = tmp->Search(i->degr);
			if (tm)
			{
				tm->a += i->a;
			}
			else
			{
				tmp->Add(*i);
			}
		}
		return *tmp;
	}
	DeletedNulls();
	diminution();
}

Polinom & Polinom::operator-(Polinom & b)
{
	if (!head)
		return *this;
	else
	{
		Polinom* tmp = new Polinom(*this);
		for (Monom* i = b.head; i; i = i->next)
		{
			Monom* tm = tmp->Search(i->degr);
			if (tm)
			{
				tm->a -= i->a;
			}
			else
			{
				tmp->_Add(*i);
			}
		}
		return *tmp;
	}
	diminution();
	DeletedNulls();
}

Polinom & Polinom::operator*(double b)
{
	Monom* i;
	for (i = head; i; i = i->next)
	{
		i->a = i->a * b;
	}
	return *this;
}

Polinom & Polinom::operator*(Polinom & b)
{
	Monom* i, *k;
	if (!b.head)
	{
		Polinom* tmp = new Polinom(*this);
		return *tmp;
	}
	Polinom* tmp = new Polinom();
	for (i = head; i; i = i->next)
	{
		for (k = b.head; k; k = k->next)
		{
			tmp->Add(*i * *k);
		}
	}
	tmp->diminution();
	tmp->DeletedNulls();
	return *tmp;
}

Polinom & Polinom::operator*(Monom & x)
{
	if (!head)
		return *this;
	Polinom* tmp = new Polinom(*this);
	for (Monom* i = tmp->head; i; i = i->next)
	{
		i->a *= x.a;
		i->degr += x.degr;
	}
	tmp->DeletedNulls();
	return *tmp;
}

Monom* Polinom::SearchDegr(int _degr, Monom* start)
{
	if (!head)
		return nullptr;
	if (!start)
		return nullptr;
	for (Monom* i = start; i; i = i->next)
	{
		if (i->degr == _degr)
		{
			return i;
		}
	}
	return nullptr;
}

Monom* Polinom::SearchMaxDeg(Monom* start)
{
	if (!start)
		return nullptr;
	Monom* tmp = start;
	int tmp_max_deg = start->degr;
	for (Monom* i = start->next; i; i = i->next)
	{
		if (i->degr > tmp_max_deg)
		{
			tmp = i;
		}
	}
	return tmp;
}

Monom* Polinom::SearchMaxDeg()
{
	if (!head)
		return nullptr;
	if (!head->next)
		return head;
	Monom* tmp = head;
	for (Monom* i = head; i; i = i->next)
		if (i->degr > tmp->degr)
			tmp = i;
	return tmp;
}

void Polinom::PlaceBefore(Monom* move, Monom* next)
{
	if (!head)
		return;
	if (move == head)
		head = head->next;
	for (Monom* i = head; i; i = i->next)
		if (i->next == move)
		{
			i->next = move->next;
			break;
		}
	if (next == head)
	{
		move->next = head;
		head = move;
		return;
	}
	for (Monom* i = head; i; i = i->next)
	{
		if (i->next == next)
		{
			i->next = move;
			move->next = next;
			break;
		}
	}
}

void Polinom::PlaceAfter(Monom* move, Monom* prev)
{
	if (!head)
		return;
	if (move == head)
		head = head->next;
	for (Monom* i = head; i; i = i->next)
		if (i->next == move)
		{
			i->next = move->next;
			break;
		}
	Monom* tmp = prev->next;
	prev->next = move;
	move->next = tmp;
}

void Polinom::Sort()
{
	if (!head)
		return;
	if (!head->next)
		return;
	Monom* max = SearchMaxDeg();
	max->output_monom();
	PlaceBefore(max, head);
	for (Monom* i = head->next; i; i = i->next)
	{
		Monom* tmax = SearchMaxDeg(i);
		if (!tmax)
			break;
		PlaceAfter(tmax, max);
		max = tmax;
	}
}

Polinom & Polinom::operator/(Polinom & b)
{
	Monom* i, *k, *tmp = head;
	Polinom* result = new Polinom(*this);
	Polinom* del = new Polinom(b);
	result->Sort();
	del->Sort();
	for (i = result->head, k = del->head; SearchMaxDeg()>= del->SearchMaxDeg(); k = k->next, i = i->next)
	{
		*tmp = *i / *k;
		*result = *result - b * *tmp;
	}
	return *result;
}