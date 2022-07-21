
/*Exercise 3 - Shapes and Areas
Create two classes: a Circle class and a Square class. For each class, take in the necessary information to calculate its area and perimeter.  Remember to validate input.

Ask the user if they want to create a circle or a square. For their pick, ask the necessary information to create the shape. Then, tell them the area and the perimeter of their shape.

Your class should have the following methods:
ExampleShape();
ExampleShape(/* Params );
float GetArea();
float GetPerimeter();

Welcome to create-a-shape, what type of shape do you want?
1 - Circle
2 - Square
Your choice: 1

Enter radius for your circle: 30
Your shape’s area: 2827.43
Your shape’s perimeter: 188.5

*/


#define _USE_MATH_DEFINES
#include <iostream>
#include<string>
#include <cmath>

class FSquare
{
private:
	float SideLenght;
	

public:
	FSquare() 
	{
	}
	FSquare(float SideLenght, float PerimeterSquare, float AreaSquare)
	{
		SideLenght = 0.0f;
		PerimeterSquare = 0.0f;
		AreaSquare = 0.0f;
	}
	
	
	void InputDataSquare()
	{
		float EntrySide;
		std::cout << "what is the side of Your Square:" << std::endl;
		std::cin >> EntrySide;

		while(!std::cin.good() || EntrySide < 0.0f)
		{
			std::cout << "Invalid input, please enter The side of Your square again" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> EntrySide;
		}
		SideLenght = EntrySide;
	}
	const float GetAreaSquare()
	{
		const float  AreaSquare = pow(SideLenght, 2);
		
		return AreaSquare;
	}
	const float GetPerimeterSquare()
	{
		return SideLenght * 4;
	}
};
class FCircle
{
private:
	float RadiusCircle;
	float DiameterCircle;
public:
	FCircle()
	{
	}
	FCircle(float RadiusCircle,float DiameterCircle)
	{
		RadiusCircle = 0.0f;
		DiameterCircle = 0.0f;
	}
	
	void InputDataCircle()
	{
		float EntryRadius;
		float EntryDiameter;
		std::cout << "what is the area of Your Circle:" << std::endl;
		std::cin >> EntryRadius;
		while (!std::cin.good() || EntryRadius < 0.0f)
		{
			std::cout << "Invalid input, please enter the radius of Your circle again:" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> EntryRadius;
		}		
		RadiusCircle = EntryRadius;

		std::cout << "what is the diameter of Your Circle:" << std::endl;
		std::cin >> EntryDiameter;
		while (!std::cin.good() || EntryDiameter < 0.0f)
		{
			std::cout << "Invalid input, please enter the diameter of Your circle again" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> EntryDiameter;
		}
		DiameterCircle = EntryDiameter;
	}
	const float GetAreaCicle( )
	{
		return M_PI * (pow(RadiusCircle, 2));
	}
	const float GetPerimeterCircle( )
	{	
		return M_PI * DiameterCircle;
	}
};

int main()
{
	int Choice;
	std::cout << "Welcome to create-a-shape, what type of shape do you want?" << std::endl;
	std::cout << "1 - Circle" << std::endl;
	std::cout << "2 - Square" << std::endl;
	std::cin >> Choice;
	while (!std::cin.good() || (Choice < 1 || Choice > 2)) 
	{
		std::cout << "Invalid input,enter Your choice again:" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> Choice;
	}
	std::cout << "Your choice: " << Choice << std::endl;
	if (Choice == 1) 
	{
		FCircle Circle;
		Circle.InputDataCircle();
		Circle.GetAreaCicle();
		Circle.GetPerimeterCircle();
		std::cout << "Your circle area: " << Circle.GetAreaCicle() << std::endl;
		std::cout << "Your square perimeter: " << Circle.GetPerimeterCircle() << std::endl;
	}
	
	if (Choice == 2)
	{
		FSquare Square;
		Square.InputDataSquare();
		Square.GetAreaSquare();
		Square.GetPerimeterSquare();
		std::cout << "Your square area: " << Square.GetAreaSquare() << std::endl;
		std::cout << "Your square perimeter: " << Square.GetPerimeterSquare() << std::endl;
	}
}