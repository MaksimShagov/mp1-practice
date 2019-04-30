#pragma once
#include <iostream>

using namespace std;

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

template<typename T, int maxsize>
Container<T, maxsize>::Container()
{
	size = 0;
	arr = new T[maxsize];
}

template<typename T, int maxsize>
Container<T*, maxsize>::Container()
{
	size = 0;
	arr = new T*[maxsize];
}

template<typename T, int maxsize>
Container<T*, maxsize>::Container(const Container<T*, maxsize>& a)
{
	size = a.size;
	arr = new T*[maxsize];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new T(*(a.arr[i]));
	}
}

template<typename T, int maxsize>
Container<T, maxsize>::Container(const T & a)
{
	size = a.size;
	arr = new T[maxsize];
	for (int i = 0; i < size; i++)
	{
		arr[i] = a.arr[i];
	}
}

template<typename T, int maxsize>
Container<T, maxsize>::~Container()
{
	size = 0;
	delete[] arr;
}

template<typename T, int maxsize>
Container<T, maxsize>::~Container()
{
	size = 0;
	delete[] arr;
}

template<typename T, int maxsize>
bool Container<T, maxsize>::IsFull() const
{
	return (size == maxsize);
}

template<typename T, int maxsize>
bool Container<T, maxsize>::IsEmpty() const
{
	return (size == 0);
}

template<typename T, int maxsize>
int Container<T, maxsize>::find(T a) const
{
	if (IsEmpty()) throw "No elements in container";
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == a)
			return i;
	}
	return -1;
}

template<typename T, int maxsize>
void Container<T, maxsize>::Add(T a)
{
	if (IsFull()) throw "Container is full";
	arr[size] = a;
	size++;
}

template<typename T, int maxsize>
void Container<T, maxsize>::Delete(T a)
{
	if (IsEmpty()) throw "No elements in container";
	arr[find(a)] = arr[size - 1];
	size--;
}

template<typename T, int maxsize>
T& Container<T, maxsize>::operator[](int i)
{
	if (i > maxsize) throw "Out of range";
	return arr[i];
}

template<typename T, int maxsize>
void Container<T, maxsize>::print_all()
{
	if (IsEmpty()) throw "No elements in container";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}


template <typename T, int maxsize>
class Container<T*, maxsize>
{
	T* arr;
	int size;
public:
	Container();
	Container(const Container<T*, maxsize>&);
	~Container();
	bool IsFull() const;
	bool IsEmpty() const;
	int find(T) const;
	void Add(T);
	void Delete(T);
	T& operator[](int);
	void print_all();
};

