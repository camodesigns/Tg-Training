/*
Exercise 4 - Printer!
Create a printer class. This class should allow you to store a string and then output it in different formats. Ask the user to input a string and then show what your printer can do! Remember to use char arrays instead of strings and avoid the std namespace.
You class should have the following methods:
Printer();
Printer(std::string outputString);
void Print();
void PrintReversed();
void PrintSpaced(int spaces);
void PrintVertically();
Example output
Welcome! Please enter a string: Hello!
Hello!
!olleH
H   e   l   l   o   !
H
e
l
l
o
!

*/
#include<iostream>
#include<string>
class FPrinter
{
private:
	std::string OutputString;
	
public:
	FPrinter()
	{
		std:: string OutputString = "";
	}
	FPrinter(std::string EntryString)
	{
		OutputString = EntryString;
	}
	
	void InputString() 
	{
		std::string EntryString;
		std::cout << "Welcome! Please enter a string:" << std::endl;
		std::getline(std::cin, EntryString);
		while(!std::cin.good()||EntryString==" ")
		{
			std::cout << "Invalid input, please enter your String again" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::getline(std::cin, EntryString);
		}
		OutputString = EntryString;
	}
	void Print()
	{
		std::cout << OutputString << std::endl;
	}
	void PrintReversed() 
	{
		for (int ReversePositionString = OutputString.length() - 1; ReversePositionString >= 0; ReversePositionString--)
		{
			std::cout << OutputString[ReversePositionString];
		}
		std::cout << std::endl;
	}
	void PrintSpaced( int NumberOfSpaces) 
	{
		
		for (int SpacePosition = 0; SpacePosition < OutputString.length(); SpacePosition++)
		{
			std::cout << OutputString[SpacePosition];
			for (int Spaces = 0; Spaces <= NumberOfSpaces; Spaces++)
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	void PrintVertically()
	{
		for (int PositionChractersString = 0; PositionChractersString < OutputString.length(); PositionChractersString++)
		{
			std::cout << OutputString[PositionChractersString] << std::endl;
		}
	}
};
int main() 
{
	FPrinter Prints;
	Prints.InputString();
	Prints.Print();
	Prints.PrintReversed();
	Prints.PrintSpaced(3);
	Prints.PrintVertically();
}