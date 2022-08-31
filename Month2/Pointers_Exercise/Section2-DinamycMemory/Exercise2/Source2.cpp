#include<iostream>

int main() 
{
	int StackInt1 = 10, StackInt2 = 5, StackInt3 = 12 ;
	std::cout << "I created three stack variables:" << std::endl;
	std::cout << "Their values are:" << std::endl;
	std::cout << StackInt1 << std::endl;
	std::cout << StackInt2 << std::endl;
	std::cout << StackInt3 << std::endl;

	std::cout << "Their memory addresses are:" << std::endl;
	std::cout << &StackInt1 << std::endl;
	std::cout << &StackInt2 << std::endl;
	std::cout << &StackInt3 << std::endl;

	int* HealpInt1 = new int;
	*HealpInt1 = 1;
	int* HealpInt2 = new int;
	*HealpInt2 = 2;
	int* HealpInt3 = new int;
	*HealpInt3 = 3;

	std::cout << "I created three heap variables." << std::endl;
	std::cout << "Their values are:" << std::endl;
	std::cout << *HealpInt1 << std::endl;
	std::cout << *HealpInt2 << std::endl;
	std::cout << *HealpInt3 << std::endl;

	std::cout << "Their memory addresses are:" << std::endl;
	std::cout << HealpInt1 << std::endl;
	std::cout << HealpInt2 << std::endl;
	std::cout << HealpInt3 << std::endl;
	
	std::cout << "I need to manually create and remove the variables from the heap beacuse the heap memory is Dinamic and this variables dont destroy itself.In the other situation with Stack Variables, they destroy themselves when the program terminates." << std::endl;
	
	delete HealpInt1, HealpInt2, HealpInt3;

}