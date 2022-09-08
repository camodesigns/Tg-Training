#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

class FShape
{
private:

public:
	FShape();
	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;

};





