#pragma once
#include "Line.h"

template<class T>
class Triangle : public Line<T>
{
protected:
	T* C;
public:
	Triangle();
	Triangle(int n);
	Triangle(const Triangle& t);
	virtual ~Triangle();

	virtual double GetPerimeter() const;
	virtual double GetArea() const;

	T* GetC() const;
	T*& SetC();

	ostream& print(ostream& os) override;
};


template<class T>
inline Triangle<T>::Triangle()
{
	this->SetDim() = 0;
	this->SetA() = new T[0];
	this->SetB() = new T[0];
	C = new T[0];
}

template<class T>
inline Triangle<T>::Triangle(int n)
{
	this->SetDim() = n;
	this->SetA() = new T[n];
	this->SetB() = new T[n];
	C = new T[n];
	for (int i = 0; i < n; i++)
	{
		this->SetA()[i] = 0;
		this->SetB()[i] = 0;
		C[i] = 0;
	}
}

template<class T>
inline Triangle<T>::Triangle(const Triangle& t)
{
	this->SetDim() = t.GetDim();
	this->SetA() = new T[t.GetDim()];
	this->SetB() = new T[t.GetDim()];
	C = new T[t.GetDim()];
	for (int i = 0; i < t.GetDim(); i++)
	{
		this->SetA()[i] = t.GetA()[i];
		this->SetB()[i] = t.GetB()[i];
		C[i] = t.C[i];
	}
}

template<class T>
inline Triangle<T>::~Triangle()
{
	delete[] C;
}

template<class T>
inline double Triangle<T>::GetPerimeter() const
{
	double sum = 0, temp = 0;
	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetB()[i] - this->GetA()[i]), 2);
	sum += sqrt(temp);
	temp = 0;
	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((C[i] - this->GetB()[i]), 2);
	sum += sqrt(temp);
	temp = 0;
	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetA()[i] - C[i]), 2);
	sum += sqrt(temp);
	temp = 0;

	return sum;
}

template<class T>
inline double Triangle<T>::GetArea() const
{
	double p = GetPerimeter() * 0.5;
	double temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetB()[i] - this->GetA()[i]), 2);
	double a = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((C[i] - this->GetB()[i]), 2);
	double b = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetA()[i] - C[i]), 2);
	double c = sqrt(temp);
	temp = 0;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

template<class T>
inline T* Triangle<T>::GetC() const
{
	return C;
}

template<class T>
inline T*& Triangle<T>::SetC()
{
	return C;
}

template<class T>
inline ostream& Triangle<T>::print(ostream& os)
{
	os << "Type: " << typeid(*this).name() << endl <<
		"Dime: " << this->GetDim() << endl <<
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
			os << this->GetB()[i] << ", ";
		else
			os << this->GetB()[i];
	}
	os << ")" << endl;

	os << "C: (";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << C[i] << ", ";
		else
			os << C[i];
	}
	os << ")" << endl;

	os << "Perimeter: " << GetPerimeter() << endl;
	os << "Area: " << GetArea() << endl;

	return os;
}
