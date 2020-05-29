#pragma once
#include "Triangle.h"

template<class T>
class Quadrilateral : public Triangle<T>
{
protected:
	T* D;
public:
	Quadrilateral();
	Quadrilateral(int n);
	Quadrilateral(const Quadrilateral& q);
	virtual ~Quadrilateral();

	T* GetD() const;
	T*& SetD();

	double GetPerimeter() const;
	double GetArea() const;
	bool IsSquare() const;

	ostream& print(ostream& os) override;
};

template<class T>
inline Quadrilateral<T>::Quadrilateral()
{
	this->SetDim() = 0;
	this->SetA() = new T[0];
	this->SetB() = new T[0];
	this->SetC() = new T[0];
	D = new T[0];
}

template<class T>
inline Quadrilateral<T>::Quadrilateral(int n)
{
	this->SetDim() = n;
	this->SetA() = new T[n];
	this->SetB() = new T[n];
	this->SetC() = new T[n];
	D = new T[n];
	for (int i = 0; i < n; i++)
	{
		this->SetA()[i] = 0;
		this->SetB()[i] = 0;
		this->SetC()[i] = 0;
		D[i] = 0;
	}
}

template<class T>
inline Quadrilateral<T>::Quadrilateral(const Quadrilateral& q)
{
	this->SetDim() = q.GetDim();
	this->SetA() = new T[q.GetDim()];
	this->SetB() = new T[q.GetDim()];
	this->SetC() = new T[q.GetDim()];
	D = new T[q.GetDim()];
	for (int i = 0; i < q.GetDim(); i++)
	{
		this->SetA()[i] = q.GetA()[i];
		this->SetB()[i] = q.GetA()[i];
		this->SetC()[i] = q.GetA()[i];
		D[i] = q.D[i];
	}
}

template<class T>
inline Quadrilateral<T>::~Quadrilateral()
{
	delete[] D;
}

template<class T>
inline T* Quadrilateral<T>::GetD() const
{
	return D;
}

template<class T>
inline T*& Quadrilateral<T>::SetD()
{
	return D;
}

template<class T>
inline double Quadrilateral<T>::GetPerimeter() const
{
	double sum = 0, temp = 0;
	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetB()[i] - this->GetA()[i]), 2);
	sum += sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetC()[i] - this->GetB()[i]), 2);
	sum += sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetC()[i] - D[i]), 2);
	sum += sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetA()[i] - D[i]), 2);
	sum += sqrt(temp);
	temp = 0;

	return sum;
}

template<class T>
inline double Quadrilateral<T>::GetArea() const
{
	double p = GetPerimeter() * 0.5;
	double temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetB()[i] - this->GetA()[i]), 2);
	double a = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetC()[i] - this->GetB()[i]), 2);
	double b = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetC()[i] - D[i]), 2);
	double c = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetA()[i] - D[i]), 2);
	double d = sqrt(temp);
	temp = 0;

	return sqrt((p - a) * (p - b) * (p - c) * (p - d));
}

template<class T>
inline bool Quadrilateral<T>::IsSquare() const
{
	double temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetA()[i] - this->GetB()[i]), 2);
	double a = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetB()[i] - this->GetC()[i]), 2);
	double b = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetC()[i] - D[i]), 2);
	double c = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetA()[i] - D[i]), 2);
	double d = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetA()[i] - this->GetC()[i]), 2);
	double ac = sqrt(temp);
	temp = 0;

	for (int i = 0; i < this->GetDim(); i++)
		temp += pow((this->GetB()[i] - D[i]), 2);
	double bd = sqrt(temp);
	temp = 0;

	if ((a == b) & (b == c) & (c == d) & (ac == bd))
		return true;
	else
		return false;
}

template<class T>
inline ostream& Quadrilateral<T>::print(ostream& os)
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

	os << "C: (";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->C[i] << ", ";
		else
			os << this->C[i];
	}
	os << ")" << endl;

	os << "D: (";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->D[i] << ", ";
		else
			os << this->D[i];
	}
	os << ")" << endl;

	os << "Perimeter: " << GetPerimeter() << endl;
	os << "Area: " << GetArea() << endl;
	auto x = IsSquare() ? "Yes" : "No";
	os << "Square: " << x << endl;

	return os;
}