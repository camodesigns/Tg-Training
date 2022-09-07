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
	virtual float GetArea() const;
	virtual float GetPerimeter() const;

};

class FCircle : public FShape
{
private:
	float Radius = 0.0f;
public:
	FCircle();
	FCircle(float* NewRadiusPtr);
	virtual float GetArea() const override;
	virtual float GetPerimeter() const override;

};

class FSquare : public FShape
{
private:
	float SideLenght = 0.0f ;
public:
	FSquare();
	FSquare(float* NewSideLenghtPtr);
	virtual float GetPerimeter() const override;
	virtual float GetArea() const override;
};

