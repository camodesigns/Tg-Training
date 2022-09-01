#include <iostream>

int main() 
{
	int* HeapPointer = new int;
	delete HeapPointer;
	if (HeapPointer)
	{
		std::cout << "The pointer is valid" << std::endl;
	}
	else 
	{
		std::cout << "The pointer is not valid" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "This happening beacuse deleting a pointer to dinamyc memory does not turn this to zero" << std::endl;
	std::cout << "this it's still 'valid' since it's pointing to something, to be specific to the memory space it had before it was erased. " << std::endl;
}