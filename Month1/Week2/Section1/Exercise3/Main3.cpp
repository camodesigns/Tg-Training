
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
		SideLenght = 0.0f;
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
			std::cin >>EntrySide;
		}
		SideLenght = EntrySide;
	}
	float GetAreaSquare()
	{
		float const AreaSquare = pow(SideLenght, 2);
		std::cout << "Your square area: " << AreaSquare << std::endl;
		return AreaSquare;
	}
	float GetPerimeterSquare()
	{
		float const PerimeterSquare = SideLenght *4;
		std::cout << "Your square perimeter: " << PerimeterSquare << std::endl;
		return PerimeterSquare;
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
		RadiusCircle = 0.0f;
		DiameterCircle = 0.0f;
	}
	
	void InPutDataCircle()
	{
		float EntryRadius;
		float EntryDiameter;
		std::cout << "what is the area of Your Circle:" << std::endl;
		std::cin >>EntryRadius;
		while (!std::cin.good() || EntryRadius < 0)
		{
			std::cout << "Invalid input, please enter the radius of Your circle again:" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> EntryRadius;
		}		
		RadiusCircle = EntryRadius;

		std::cout << "what is the diameter of Your Circle:" << std::endl;
		std::cin >> EntryDiameter;
		while (!std::cin.good() || EntryDiameter < 0)
		{
			std::cout << "Invalid input, please enter the diameter of Your circle again" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> EntryDiameter;
		}
		DiameterCircle=EntryDiameter;
	}
	float GetAreaCicle( )
	{
		float AreaCircle = M_PI * (pow(RadiusCircle,2));
		std::cout << "Your circle area: " << AreaCircle << std::endl;
		return AreaCircle;	
	}
	float GetPerimeterCircle( )
	{
		 float PerimeterCircle = M_PI * DiameterCircle;
		 std::cout << "Your circle perimeter: " << PerimeterCircle << std::endl;
		return PerimeterCircle;
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
		FCircle circle;
		circle.InPutDataCircle();
		circle.GetAreaCicle();
		circle.GetPerimeterCircle();
	}
	if (Choice == 2)
	{
		FSquare square;
		square.InputDataSquare();
		square.GetAreaSquare();
		square.GetPerimeterSquare();
	}
}