#include "ArrayVectors.h"
FShape::FShape() 
{

}
 float FShape::  GetArea() const 
{
	 float Area = 0.0f;
	 return Area;
}
 float FShape:: GetPerimeter() const
{
	 float Perimeter = 0.0f;
	 return Perimeter;
}

 int ValidateIntInput() 
 {
	 int Input;
	 std::cin >> Input;
	 while (!std::cin.good() || Input <= 0 ) 
	 {
	 
	 }
	
 }

float FCircle::GetArea()const 
{
	const float Area = (2*M_PI) * Radius;
	return  Area;
}

void BuiltInArray() 
{
	std::cout << "How many shapes you want to create" << std::endl;
	int ShapesNumber;
	

}

int main()
{
	enum Choice
	{
		BuiltInArrays = 1,
		StaticArray,
		DinamycArray
	};
	std::cout << "Hi user" << std::endl;
	std::cout << "What method do you want to use to create a number of shapesand print their perimeterand area" << std::endl;
	std::cout << "1. Built-in Array " << std::endl;
	std::cout << "2. Static Array" << std::endl;
	std::cout << "3. Dinamyc Array" << std::endl;
	int Choice;
	std::cin >> Choice;
	switch (Choice)
	{
	case BuiltInArrays:

		BuiltInArray();
		break;
	case StaticArray:
		break;
	case DinamycArray:
		break;
	default:
		break;
	}
	std::cout << M_PI << std::endl;

}