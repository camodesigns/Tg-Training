#pragma once
#include "ArrayVectors.h"
class FSquare : public FShape
{
private:
	float SideLenght = 0.0f;
public:
	FSquare(float& NewSideLenghtPtr);
	virtual float GetPerimeter() const override;
	virtual float GetArea() const override;
};