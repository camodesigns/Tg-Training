/*Exercise 1 - Understanding Memory Addresses
Create a program that will ask the user to enter an integer and assign the given value to a
variable. Then, print the value to the console, and print the memory address of that variable.
Then, ask for another value and assign that value to the same variable. Print the value and the
memory address to the console.
Finally, ask for one more value. This time, assign the value to a different variable. Print the
value and the memory address to the console. Do the results make sense to you?*/
#include<iostream>

int ValidateIntInput() 
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
	std::cout << "Please enter a number:" << std::endl;
	int Number= ValidateIntInput();
	const int* Numberptr = &Number;
	std::cout << "The value of your variable is: " << Number << std::endl;
	std::cout << "The memory adress where you variable is store is: " << Numberptr << std::endl;
	std::cin.ignore(1000, '\n');

	std::cout << "Enter another number:" << std::endl;
	int Number = ValidateIntInput();
	
	std::cout << "The value of your variable is: " << Number << std::endl;
	std::cout << "The memory adress where you variable is store is:" << Numberptr << std::endl;
	std::cin.ignore(1000, '\n');

	std::cout << "Please enter one more number:" << std::endl;
	int NewNumber = ValidateIntInput();
	Numberptr = &NewNumber;
	std::cout << "The value of your variable is: " << NewNumber << std::endl;
	std::cout << "The memory adress where you variable is store is:" << Numberptr << std::endl;

}
