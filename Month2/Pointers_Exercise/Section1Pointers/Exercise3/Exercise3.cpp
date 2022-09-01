#include <iostream>
int InputIntValidation()
{
	int Input;
	while (std::cin.peek() == '\n')
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Enter Key is not a number, please try again" << std::endl;
	}
	std::cin >> Input;
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid input, please try again:" << std::endl;
		std::cin >> Input;
	}
	return Input;
}
int main() 
{
	std::cout << "Please enter a value for variable a:" << std::endl;
	int VariableA = InputIntValidation();

	std::cin.ignore(1000, '\n');

	std::cout << "Please enter a value for variable b:" << std::endl;
	int VariableB = InputIntValidation();

	int* P = &VariableA;
	std::cout << "Using pointer variable p, I’ve determined that:" << std::endl;
	std::cout << "The value of a is " << *P << std::endl;
	std::cout << "The memory address of variable a is" << P << std::endl;
	std::cout << "The value of variable p is" << P << std::endl;
	std::cout << "The memory address of variable p is" << &P << std::endl;
	std::cout << std::endl;

	std::cout << "Using pointer variable p, I’ve determined that:" << std::endl;
	P = &VariableB;
	std::cout << "The value of b is " << *P << std::endl;
	std::cout << "The memory address of variable b is" << P << std::endl;
	std::cout << "The value of variable p is" << P << std::endl;
	std::cout << "The memory address of variable p is" << &P << std::endl;

}