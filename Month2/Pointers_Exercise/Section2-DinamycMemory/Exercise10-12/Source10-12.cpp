#include <iostream>
#include "FClassA.h"
#include "FClassB.h"

int main()
{
	FClassA ClassA;
	FClassB ClassB;

	std::cout << "The  error  occurring a reason of the order of declaration and definition." << std::endl;
	std::cout << " FClassA didn't know about FClassB's existence before setting it as a property" << std::endl;
	std::cout << "this happened due to the order in which it was declared" << std::endl;

	std::cout << "Forward declarations are espectaculars and useful for C++ development, allowing us to include header files where we need actually using them." << std::endl;
	std::cout<< " Allows better management and reading of header files, avoiding ambiguities and ignoring other header files that are previously called" << std::endl;

	std::cout << "It is logical that you only work with pointers, because then you do not automatically access a default constructor after it is declared at the beginning of the code." << std::endl;
	std::cout << "In this case, it is mandatory to know in depth the useand operation of a constructor, while a pointer can be initialized or instantiated in a null value or nullptr and when necessary, that instance can be modified to be used in a more precise way. " << std::endl;
	
	return 0;
}