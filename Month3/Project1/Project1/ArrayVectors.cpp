#include "ArrayVectors.h"
FShape::FShape() 
{

}

FCircle::FCircle(float& NewRadius)
{
	Radius = NewRadius;

}

 int ValidateIntInput() 
 {
	 int Input;
	 std::cin.ignore(100, '\n');
	 while (std::cin.peek() == '\n')
	 {
		 std::cin.ignore(100, '\n');
		 std::cout << "Invalid input, try again" << std::endl;
	 }

	 std::cin >> Input;
	 while (!std::cin.good() || Input <= 0 ) 
	 {
		 std::cin.clear();
		 std::cin.ignore(100, '\n');
		 std::cout << "Invalid input,try again" << std::endl;
		 std::cin >> Input;
	 }
	 return Input;
 }

 float ValidateFloatInput() 
 {
	 float Input;
	 std::cin.ignore(100, '\n');

	 while (std::cin.peek() == '\n')
	 {
		 std::cin.ignore(100, '\n');
		 std::cout << "Invalid input, try again" << std::endl;
	 }
	 std::cin >> Input;
	 while (!std::cin.good() || Input <= 0)
	 {
		 std::cin.clear();
		 std::cin.ignore(100, '\n');
		 std::cout << "Invalid input,try again" << std::endl;
		 std::cin >> Input;
	 }
	 return Input;
 }




 float FCircle::GetPerimeter() const
 {
	 return M_PI * pow(Radius, 2);
 }

float FCircle::GetArea() const 
{
	const float Area = (2*M_PI) * Radius;
	return  Area;
}




float FSquare::GetArea() const
{
	return pow(SideLenght, 2);
}
float FSquare::GetPerimeter() const
{
	return SideLenght * 4;
}


void BuiltInArray() 
{
	std::cout << "How many shapes you want to create" << std::endl;
	int ShapesNumber = ValidateIntInput();
	FShape** ArrShapes = new FShape*[ShapesNumber];
	int Position;
	int Shape;
	float Radius;
	float SideLeght;
	
	for (int CurrentIndex = 0; CurrentIndex < ShapesNumber ; CurrentIndex++) 
	{
		Position = CurrentIndex + 1;
		std::cout << "What shape are you looking for your position number " << Position << std::endl;
		std::cout << "1. Circle" << std::endl;
		std::cout << "2. Square" << std::endl;
		Shape = ValidateIntInput();

		while (Shape > 2) 
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Sorry, You only can Select Cicle or Square, try again" << std::endl;
			Shape = ValidateIntInput();
		}

		if (Shape == 1) 
		{
			std::cout << "you select circle, now please enter a radius for the circle" << std::endl;
			Radius = ValidateFloatInput();
			ArrShapes[CurrentIndex] = new FCircle(Radius);
		}
		if (Shape == 2) 
		{
			std::cout << "you select square, now please enter side lenght" << std::endl;
			SideLeght = ValidateFloatInput();
			ArrShapes[CurrentIndex] = new FCircle(SideLeght);
		}
	
	}
	system("CLS");
	for (int CurrentIndex = 0; CurrentIndex < ShapesNumber ; CurrentIndex++) 
	{
		std::cout << "The Area of your shape is: " << ArrShapes[CurrentIndex]->GetArea() << std::endl;
		std::cout << "The Perimeter of your shape is: " << ArrShapes[CurrentIndex]->GetPerimeter() << std::endl;
		std::cout << std::endl;
	}
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
	

}