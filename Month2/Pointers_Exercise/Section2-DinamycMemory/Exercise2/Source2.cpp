#include<iostream>

int main() 
{
	int StackInt1 = 10;
	int StackInt2 = 5;
	int	StackInt3 = 12;
	std::cout << "I created three stack variables:" << std::endl;
	std::cout << "Their values are:" << std::endl;
	std::cout << StackInt1 << std::endl;
	std::cout << StackInt2 << std::endl;
	std::cout << StackInt3 << std::endl;

	std::cout << "Their memory addresses are:" << std::endl;
	std::cout << &StackInt1 << std::endl;
	std::cout << &StackInt2 << std::endl;
	std::cout << &StackInt3 << std::endl;

	int* HeapInt1 = new int;
	*HeapInt1 = 1;
	int* HeapInt2 = new int;
	*HeapInt2 = 2;
	int* HeapInt3 = new int;
	*HeapInt3 = 3;

	std::cout << "I created three heap variables." << std::endl;
	std::cout << "Their values are:" << std::endl;
	std::cout << *HeapInt1 << std::endl;
	std::cout << *HeapInt2 << std::endl;
	std::cout << *HeapInt3 << std::endl;

	std::cout << "Their memory addresses are:" << std::endl;
	std::cout << HeapInt1 << std::endl;
	std::cout << HeapInt2 << std::endl;
	std::cout << HeapInt3 << std::endl;
	
	std::cout << "I need to manually create and remove the variables from the heap beacuse the heap memory is Dinamic and this variables dont destroy itself.In the other situation with Stack Variables, they destroy themselves when the program terminates." << std::endl;
	
	delete HeapInt1, HeapInt2, HeapInt3;

}