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
class Printer
{
private:
	std::string OutputString;
public:
	Printer()
	{
	}
	Printer(std::string OutputString)
	{
		OutputString = "";
	}
	void InputString() 
	{
		std::string Outputstring;
		std::cout << "Welcome! Please enter a string:" << std::endl;
		std::getline( std::cin,Outputstring);
		while(!std::cin.good())
		{
			std::cout << "Invalid input, please enter " << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> Outputstring;
		}
		OutputString = Outputstring;
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
	void PrintSpaced() 
	{
		for (int SpacePosition = 0; SpacePosition < OutputString.length(); SpacePosition++)
		{
			std::cout << OutputString[SpacePosition] << "\t";
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
	Printer string;
	string.InputString();
	string.Print();
	string.PrintReversed();
	string.PrintSpaced();
	string.PrintVertically();
}