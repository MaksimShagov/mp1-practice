#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Container
{
	T* arr;
	int size;
	int maxsize = 0;
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
	void resize();
	void print_all();
};

template <typename T>
class Container<T* >
{
	T** arr;
	int size;
	int maxsize = 0;
public:
	Container();
	Container(const Container<T* >&);
	~Container();
	bool IsFull() const;
	bool IsEmpty() const;
	int find(T) const;
	void Add(T);
	void Delete(T);
	T& operator[](int);
	void print_all();
	void resize();
};

template<typename T>
Container<T>::Container()
{
	size = 0;
	arr = new T[maxsize];
}

template<typename T>
Container<T*>::Container()
{
	size = 0;
	arr = new T*[maxsize];
}

template<typename T>
Container<T* >::Container(const Container<T*>& a)
{
	size = a.size;
	arr = new T*[a.maxsize];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new T(*(a.arr[i]));
	}
}

template<typename T>
Container<T>::Container(const T & a)
{
	size = a.size;
	arr = new T[maxsize];
	for (int i = 0; i < size; i++)
	{
		arr[i] = a.arr[i];
	}
}

template<typename T>
Container<T >::~Container()
{
	size = 0;
	delete[] arr;
}

template<typename T>
Container<T* >::~Container()
{
	size = 0;
	for (int i = 0; i < size; i++)
		delete arr[i];
	delete[] arr;
}

template<typename T>
bool Container<T >::IsFull() const
{
	return (size == maxsize);
}

template<typename T>
bool Container<T* >::IsFull() const
{
	return (size == maxsize);
}

template<typename T>
bool Container<T >::IsEmpty() const
{
	return (size == 0);
}

template<typename T>
bool Container<T* >::IsEmpty() const
{
	return (size == 0);
}

template<typename T>
int Container<T >::find(T a) const
{
	if (IsEmpty()) throw "No elements in container";
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == a)
			return i;
	}
	return -1;
}

template<typename T>
int Container<T* >::find(T a) const
{
	if (IsEmpty()) throw "No elements in container";
	for (int i = 0; i < size; i++)
	{
		if (**(arr + i) == a)
			return i;
	}
	return -1;
}

template<typename T>
void Container<T >::Add(T a)
{
	if (IsFull()) resize();
	arr[size] = a;
	size++;
}

template<typename T>
void Container<T* >::Add(T a)
{
	if (IsFull()) resize();
	arr[size] = new T(a);
	size++;
}

template<typename T>
void Container<T >::Delete(T a)
{
	if (IsEmpty()) throw "No elements in container";
	arr[find(a)] = arr[--size];
	size--;
}

template<typename T>
void Container<T*>::Delete(T a)
{
	int tmp = find(a);
	if (tmp == -1) throw "There is no such element";
	delete arr[tmp];
	arr[tmp] = arr[--size];
}

template<typename T>
T& Container<T>::operator[](int i)
{
	if (i > maxsize) throw "Out of range";
	return arr[i];
}

template<typename T>
inline void Container<T>::resize()
{
	maxsize += 10;
	T* tmp_arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		tmp_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new T[maxsize];
	for (int i = 0; i < size; i++)
	{
		arr[i] = tmp_arr[i];
	}
	delete[] tmp_arr;
}

template<typename T>
inline void Container<T*>::resize()
{
	maxsize += 10;
	T** tmp_arr = new T*[size];
	for (int i = 0; i < size; i++)
	{
		tmp_arr[i] = new T(*(arr[i]));
	}
	delete[] arr;
	arr = new T*[maxsize];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new T(*(tmp_arr[i]));
	}
	delete[] tmp_arr;
}

template<typename T>
T& Container<T* >::operator[](int i)
{
	if (i > maxsize) throw "Out of range";
	return *arr[i];
}

template<typename T>
void Container<T>::print_all()
{
	if (IsEmpty()) throw "No elements in container";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

template<typename T>
void Container<T*>::print_all()
{
	if (IsEmpty()) throw "No elements in container";
	for (int i = 0; i < size; i++)
	{
		cout << *arr[i] << endl;
	}
}