
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

class Square
{
private:
	float Side;
	float AreaSquare;
	float PerimeterSquare;
public:
	Square()
	{
	}
	Square(float Radius, float Diameter)
	{
		Side = 0;
	}
	void DataSquare()
	{
		float side;
		std::cout << "what is the side of Your Square:" << std::endl;
		std::cin >> side;

		while (!std::cin.good() || side < 0)
		{
			std::cout << "Invalid input, please enter The side of Your square again" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >>side;
		}
		Side = side;
	}
	float GetAreaSquare( )
	{
		AreaSquare = pow(Side, 2);
		return AreaSquare;
	}
	float GetPerimeterSquare()
	{
		PerimeterSquare = Side*4;
		return PerimeterSquare;
	}
	void PrinterSquare() 
	{
		std::cout<<"Your square area: " << AreaSquare << std::endl;
		std::cout<<"Your square perimeter: " << PerimeterSquare << std::endl;
	}

};
class Circle
{
private:
	float AreaCircle ;
	float PerimeterCircle;
	float Radius;
	float Diameter;
public:
	Circle()
	{
	}
	Circle(float Radius, float Diameter)
	{
		Radius = 0;
		Diameter = 0;
	}
	void DataCircle()
	{
		int radius;
		int diameter;
		std::cout << "what is the area of Your Circle:" << std::endl;
		std::cin >>radius;
		while (!std::cin.good() || radius<0)
		{
			std::cout << "Invalid input, please enter the radius of Your circle again:" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> radius;
		}		
		Radius = radius;

		std::cout << "what is the diameter of the Circle:" << std::endl;
		std::cin >> diameter;
		while (!std::cin.good() || diameter < 0)
		{
			std::cout << "Invalid input, please enter the diameter of Your circle again" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> diameter;
		}
		Diameter=diameter;
	
	}
	float GetAreaCicle( )
	{
		AreaCircle =M_PI*(pow(Radius,2));
		return AreaCircle;	
	}
	float GetPerimeterCircle( )
	{
		PerimeterCircle = M_PI * Diameter;
		return PerimeterCircle;
	}
	void PrinterCircle()
	{
		std::cout << "Your circle area: " << AreaCircle << std::endl;
		std::cout << "Your circle perimeter: " << PerimeterCircle << std::endl;
	}
};

int main()
{
	int Choice;
	std::cout << "Welcome to create-a-shape, what type of shape do you want?" << std::endl;
	std::cout << "1 - Circle" << std::endl;
	std::cout << "2 - Square" << std::endl;
	std::cin >> Choice;
	while (!std::cin.good() ||(Choice<1||Choice>2)) 
	{
		std::cout << "Invalid input,enter Your choice again:" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> Choice;
	}
	std::cout << "Your choice: " << Choice << std::endl;
	if (Choice == 1) 
	{
		Circle circle;
		circle.DataCircle();
		circle.GetAreaCicle();
		circle.GetPerimeterCircle();
		circle.PrinterCircle();
	}
	if (Choice == 2)
	{
		Square square;
		square.DataSquare();
		square.GetAreaSquare();
		square.GetPerimeterSquare();
		square.PrinterSquare();
	}
}