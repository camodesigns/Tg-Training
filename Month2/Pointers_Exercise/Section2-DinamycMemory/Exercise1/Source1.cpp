#include <iostream>

int main() 
{
	int* SomeInt = new int;
	*SomeInt = 10;
	std::cout << "I’ve dynamically allocated an integer. Its value is: "<< *SomeInt << " and its memory address is:"<<SomeInt << std::endl;
	delete SomeInt;
}