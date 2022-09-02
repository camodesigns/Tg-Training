#include <iostream>

void MemoryLeak1() 
{
	int* IntPtr = new int;
}
void MemoryLeak2(int* IntPtr)
{
	int* IntPointer = new int;
	IntPointer = IntPtr;
}

int main() 
{
	MemoryLeak1();
	int* Ptr = nullptr;
	MemoryLeak2(Ptr);

	std::cout << "The first funtion create a memory leak beacuse  it allocates a variable in the heap, but  we cannot acces it outside  the function" << std::endl;
	std::cout << "the integer will be there for the rest of the execution of the program " << std::endl;
	std::cout << std::endl;

	std::cout << "The second function create a memory leak, beacuse I allocate memory unto the heap, them the pointer was changed to it, therefore, One of the pointer was deleted and can´t be deleted manually, because  we only can make this in the scope of teh function " << std::endl;
	
}


