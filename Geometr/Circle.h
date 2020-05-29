#pragma once
#include "Line.h"

template<class T>
class Circle : public Line<T>
{
	using Line<T>::GetLength;
public:
	Circle() : Line<T>() {}
	Circle(int n) : Line<T>(n) {}
	Circle(const Circle& c) : Line<T>(c) {}
	virtual ~Circle() {};

	double GetRadius() const;
	double GetArea() const;

	ostream& print(ostream& os);
};

template<class T>
inline double Circle<T>::GetRadius() const
{
	return this->GetLength();
}

template<class T>
inline double Circle<T>::GetArea() const
{
	return pow(this->GetLength(), 2) * M_PI;
}

template<class T>
inline ostream& Circle<T>::print(ostream& os)
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
			os << this->GetB()[i] << ", ";
		else
			os << this->GetB()[i];
	}
	os << ")" << endl;

	os << "Radius: " << GetRadius() << endl;
	os << "Area: " << GetArea() << endl;

	return os;
}