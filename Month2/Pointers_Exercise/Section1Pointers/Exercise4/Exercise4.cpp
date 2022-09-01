#include <iostream>
int main()
{
	int VariableA = 10;
	std::cout << "The value of my variable is: " <<VariableA << std::endl;
	int* Ptr = &VariableA;
	(* Ptr)++;
	int* Ptr2 = &VariableA;
	(* Ptr2++);
	std::cout << "The value of my variable after the pointer stuff I did is: " << VariableA << std::endl;
}