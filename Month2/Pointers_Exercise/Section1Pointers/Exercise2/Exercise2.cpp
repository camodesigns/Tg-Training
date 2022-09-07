#include<iostream>
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
	int VariableA= InputIntValidation();

	int* Numberptr = &VariableA;
	std::cout << "The Value of the a variable is: " << VariableA << std::endl;

	std::cin.ignore(1000, '\n');

	std::cout << "Please enter a new value for variable a:" << std::endl;
	*Numberptr = InputIntValidation();
	std::cout << "The value of variable a is now:" << VariableA << std::endl;
	std::cout << "Fun fact: I didn’t have to touch a directly to change its value :)" << std::endl;
	
	
}