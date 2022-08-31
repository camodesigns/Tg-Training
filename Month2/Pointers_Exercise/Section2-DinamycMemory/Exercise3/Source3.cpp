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
	int* Ptr = NULL;
	MemoryLeak2(Ptr);

	std::cout << "The first funtion create a memory leak beacuse  it allocates a variable in the heap, but  we cannot acces it outside  the function" << std::endl;
	std::cout << "the integer will be there indefinitely " << std::endl;

}
