#pragma once
#include <vector>
#include "Base.h"

using namespace std;

class Container
{
protected:
	Base** Array;
	vector<string> names;
	int size;
public:
	Container();
	Container(const Container& c);
	virtual ~Container();

	template <class A>
	void Add(A& elem, string name);
	void Remove(int r);
	void ShowAll();
	void Show(int i);

	Base* operator[](const int i);
};

Container::Container()
{
	size = 0;
	Array = 0;
	names = {};
}

Container::Container(const Container& c)
{
	size = c.size;
	Array = c.Array;
	names = c.names;
}

Container::~Container()
{
	delete[] Array;
	names.clear();
}

Base* Container::operator[](const int i)
{
	return Array[i];
}

template<class A>
void Container::Add(A& elem, string name)
{
	Base** tmp = new Base * [size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = Array[i];
	}
	delete[]Array;
	size++;
	Array = new Base * [size];
	for (int i = 0; i < size - 1; i++)
	{
		Array[i] = tmp[i];
	}
	Array[size - 1] = &elem;
	delete[]tmp;

	names.push_back(name);
}

void Container::Remove(int r)
{
	Base** tmp = new Base * [size];
	int j = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == r)
		{
			k = 1;
		}
		else
		{
			tmp[j] = Array[i];
			j++;
		}
	}
	if (k == 0)
		throw - 1;
	delete[] Array;
	Array = new Base * [size - 1];
	size = size - 1;
	for (int i = 0; i < size; i++)
		Array[i] = tmp[i];
	delete[] tmp;

	names.erase(names.begin() + r);
}

void Container::ShowAll()
{
	cout << "Objects: " << endl;
	for (int i = 0; i < size; i++)
		cout << i << ") " << names[i] << " of " << typeid(*Array[i]).name() << endl;
}

inline void Container::Show(int i)
{
	cout << "Object no. " << i << ":" << endl << *Array[i] << endl;
}