#pragma once
#include "Base.h"

template<class T>
class Point : public Base
{
protected:
	int dim;
	T* A;
public:
	Point();
	Point(int n);
	Point(const Point& p);
	virtual ~Point();

	T* GetA() const;
	int GetDim() const;

	T*& SetA();
	int& SetDim();

	ostream& print(ostream& os) override;
};


template<class T>
inline Point<T>::Point()
{
	dim = 0;
	A = new T[0];
}

template<class T>
inline Point<T>::Point(int n)
{
	dim = n;
	A = new T[n];
	for (int i = 0; i < n; i++)
		A[i] = 0;
}

template<class T>
inline Point<T>::Point(const Point& p)
{
	dim = p.dim;
	A = new T[p.dim];
	for (int i = 0; i < p.dim; i++)
		A[i] = p.A[i];
}

template<class T>
inline Point<T>::~Point()
{
	delete[] A;
	dim = 0;
}

template<class T>
inline T* Point<T>::GetA() const
{
	return A;
}

template<class T>
inline T*& Point<T>::SetA()
{
	return A;
}

template<class T>
inline int& Point<T>::SetDim()
{
	return dim;
}

template<class T>
inline int Point<T>::GetDim() const
{
	return dim;
}

template<class T>
inline ostream& Point<T>::print(ostream& os)
{
	os << "Type: " << typeid(*this).name() << endl <<
		"Dim: " << GetDim() << endl <<
		"Coord point: (";
	for (int i = 0; i < GetDim(); i++)
	{
		if (i != GetDim() - 1)
			os << GetA()[i] << ", ";
		else
			os << GetA()[i];
	}

	os << ")" << endl;
	return os;
}