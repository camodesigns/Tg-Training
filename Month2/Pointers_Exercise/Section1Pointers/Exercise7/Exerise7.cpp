#include <iostream>
void IncrementNumber(int* NumberPtr)
{
	if (NumberPtr)
	{
		(*NumberPtr) += 1;
	}
}
void PrintValue(int Value) 
{
	std::cout << Value << std::endl;
}

int main() 
{
	int Variable = 10;
	
	PrintValue(Variable);
	
	int* NumberPtr = nullptr;
	
	IncrementNumber(NumberPtr);
	
	PrintValue(Variable);
}