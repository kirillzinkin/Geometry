#pragma once
#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

#include <typeinfo> 

using namespace std;
class Base
{
public:
    virtual ~Base() {}

    virtual ostream& print(ostream& os) = 0;

    friend ostream& operator<<(ostream& os, Base& other)
    {
        return other.print(os);
    }

};

