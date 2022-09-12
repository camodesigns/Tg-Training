#pragma once
#include "ArrayVectors.h"
class FCircle : public FShape
{
private:
	float Radius = 0.0f;
public:
	FCircle(float& NewRadius);
	virtual float GetArea() const override;
	virtual float GetPerimeter() const override;
};