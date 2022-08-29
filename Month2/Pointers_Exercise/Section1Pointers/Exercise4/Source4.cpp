#include <iostream>
int main()
{
	int VariableA = 10;
	std::cout << "The value of my variable is: " <<VariableA << std::endl;
	int* P = &VariableA;
	*P;
	int* P2 = &VariableA;
	*P2;
	*P = 5;
	*P2 = 12;
	std::cout << "The value of my variable after the pointer stuff I did is: " << VariableA << std::endl;
}