#include "ArrayVectors.h"
#include "TStaticArray.h"
#include "Circle.h"
#include "Square.h"
#include "TDinamicArray.h"



FShape::FShape()
{

}

FCircle::FCircle(float& NewRadius)
{
	Radius = NewRadius;

}
FSquare::FSquare(float& NewSideLenght) 
{
	SideLenght = NewSideLenght;
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
	while (!std::cin.good() || Input <= 0)
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
	return (float)M_PI * (float)pow(Radius, 2);
}

float FCircle::GetArea() const
{
	const float Area = (2 * M_PI) * Radius;
	return  Area;
}




float FSquare::GetArea() const
{
	return (float)pow(SideLenght, 2);
}
float FSquare::GetPerimeter() const
{
	return SideLenght * 4;
}




void BuiltInArray()
{
	std::cout << "How many shapes you want to create" << std::endl;
	int ShapesNumber = ValidateIntInput();
	FShape** ArrShapes = new FShape * [ShapesNumber];
	int Position;
	int Shape;
	float Radius;
	float SideLeght;

	for (int CurrentIndex = 0; CurrentIndex < ShapesNumber; CurrentIndex++)
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
			ArrShapes[CurrentIndex] = new FSquare(SideLeght);
		}

	}
	system("CLS");
	for (int CurrentIndex = 0; CurrentIndex < ShapesNumber; CurrentIndex++)
	{
		std::cout << "The Area of your shape is: " << ArrShapes[CurrentIndex]->GetArea() << std::endl;
		std::cout << "The Perimeter of your shape is: " << ArrShapes[CurrentIndex]->GetPerimeter() << std::endl;
		std::cout << std::endl;
	}
	
	delete[] ArrShapes;
}


void DinamicArray() 
{
	TDinamicArray <FShape*> ArrShapes(1);
	std::cout << "What do you want to do" << std::endl;
	std::cout << "1. Add a Shape" << std::endl;
	std::cout << "2. You want to print the shapes you already have?" << std::endl;
	int Choice = ValidateIntInput();
	while (Choice > 2 || Choice < 1) 
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "invalid Input, you only can choice 1 or 2 option, Try Again" << std::endl;
		Choice = ValidateIntInput();
	}
	float Radius;
	float SideLeght;
	if (Choice == 1)
	{
		std::cout << "you select circle, now please enter a radius for the circle" << std::endl;
		Radius = ValidateFloatInput();
		ArrShapes.PushBack(new FCircle(Radius));
	}

	if (Choice == 2)
	{
		std::cout << "you select square, now please enter side lenght" << std::endl;
		SideLeght = ValidateFloatInput();
		ArrShapes.PushBack(new FSquare(SideLeght));
	}
	
	std::cout << "You want to print the shapes you already have?" << std::endl;
	std::cout << "1.Yes" << std::endl;
	std::cout << "2. Not" << std::endl;
	int Option = ValidateIntInput();
	if (Option == 1) 
	{
		int Counter	= 1;
		for (int CurrentIndex = 0; CurrentIndex <= ArrShapes.GetSize(); CurrentIndex++)
		{
			std::cout << "the Area of your shape number " << Counter << "is: " << ArrShapes[CurrentIndex]->GetArea() << std::endl;
			std::cout << "The perimeter of Yout Shape number " << Counter << "is: " << ArrShapes[CurrentIndex]->GetPerimeter() << std::endl;
			std::cout << std::endl;
		}
	}
	if (Option == 2) 
	{
		return;
	}
}



void StaticArray()
{
	TStaticArray <FShape*, 3> ArrShapes;
	for (int CurrentIndex = 0; CurrentIndex < 3; CurrentIndex++)
	{
		std::cout << "What shape would you like to create?" << std::endl;
		std::cout << "1. Circle" << std::endl;
		std::cout << "2. Square" << std::endl;
		int ChoicedShape = ValidateIntInput();
		float Radius;
		float SideLeght;
		while (ChoicedShape > 2 || ChoicedShape == 0)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Sorry, You only can Select Cicle or Square, try again:" << std::endl;
		}
		if (ChoicedShape == 1)
		{
			std::cout << "you select circle, now please enter a radius for the circle" << std::endl;
			Radius = ValidateFloatInput();
			ArrShapes[CurrentIndex] = new FCircle(Radius);
		}
		if (ChoicedShape == 2)
		{
			std::cout << "you select square, now please enter side lenght" << std::endl;
			SideLeght = ValidateFloatInput();
			ArrShapes[CurrentIndex] = new FCircle(SideLeght);
		}
		int Counter = 1;
		for (int CurrentIndex = 0; CurrentIndex < 3; CurrentIndex++) 
		{
			std::cout << "the Area of your shape number " << Counter << "is: " << ArrShapes[CurrentIndex]->GetArea() << std::endl;
			std::cout << "The perimeter of Yout Shape number " << Counter << "is: " << ArrShapes[CurrentIndex]->GetPerimeter() << std::endl;
			std::cout << std::endl;
			Counter++;
		}
	}

}





int main()
{
	enum Choice
	{
		BuiltInArrays = 1,
		StaticArrays,
		DinamycArrays
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

	case StaticArrays:
		StaticArray();
		break;

	case DinamycArrays:
		DinamicArray();
		break;

	default:
		break;
	}


}