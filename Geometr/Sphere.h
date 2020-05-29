#pragma once
#include "Circle.h"

template<class T>
class Sphere : public Circle<T>
{
	using Circle<T>::GetArea;
public:
	Sphere() : Circle<T>() {}
	Sphere(int n) : Circle<T>(n)
	{
		if (n < 3)
			throw "Yikes";

	}
	Sphere(const Sphere& s) : Circle<T>(s) {}
	virtual ~Sphere() {};

	double GetVolume() const;

	ostream& print(ostream& os);
};

template<class T>
inline double Sphere<T>::GetVolume() const
{
	return (4.0 / 3) * pow(this->GetRadius(), 3) * M_PI;
}


template<class T>
inline ostream& Sphere<T>::print(ostream& os)
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

	os << "Radius: " << this->GetRadius() << endl;
	os << "Volume: " << GetVolume() << endl;

	return os;
}