#pragma once
#include "Point.h"

template<class T>
class Line : public Point<T>
{
protected:
	T* B;
public:
	Line();
	Line(int n);
	Line(const Line& l);
	virtual ~Line();

	double GetLength() const;

	T* GetB() const;

	T*& SetB();

	ostream& print(ostream& os) override;
};


template<class T>
inline Line<T>::Line()
{
	this->SetDim() = 0;
	this->SetA() = new T[0];
	B = new T[0];
}

template<class T>
inline Line<T>::Line(int n)
{
	this->SetDim() = n;
	this->SetA() = new T[n];
	B = new T[n];
	for (int i = 0; i < n; i++)
	{
		this->SetA()[i] = 0;
		B[i] = 0;
	}
}

template<class T>
inline Line<T>::Line(const Line& l)
{
	this->SetDim() = l.GetDim();
	this->SetA() = new T[this->dim];
	B = new T[this->dim];
	for (int i = 0; i < this->dim; i++)
	{
		this->SetA()[i] = l.GetA()[i];
		B[i] = l.B[i];
	}
}

template<class T>
inline Line<T>::~Line()
{
	delete[] B;
}

template<class T>
inline double Line<T>::GetLength() const
{
	double sum = 0;
	for (int i = 0; i < this->GetDim(); i++)
		sum += pow((B[i] - this->GetA()[i]), 2);
	return sqrt(sum);
}

template<class T>
inline T* Line<T>::GetB() const
{
	return B;
}

template<class T>
inline T*& Line<T>::SetB()
{
	return B;
}

template<class T>
inline ostream& Line<T>::print(ostream& os)
{
	os << "Type: " << typeid(*this).name() << endl <<
		"Dim: " << this->GetDim() << endl <<
		"A: (";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->GetA()[i] << ", ";
		else
			os << this->GetA()[i];
	}
	os << ")" << endl;

	os << "B: (";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << GetB()[i] << ", ";
		else
			os << GetB()[i];
	}
	os << ")" << endl;

	os << "Len: " << GetLength() << endl;

	return os;
}