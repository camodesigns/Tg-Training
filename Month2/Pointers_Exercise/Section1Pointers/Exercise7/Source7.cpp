#include <iostream>

int IncrementNumber(int NewIncreasedValue)
{
	return NewIncreasedValue +=1;
}
void PrintValue(int Value) 
{
	std::cout << Value << std::endl;
}

int main() 
{
	int Variable = 10;
	PrintValue(Variable);
	int* Ptr = NULL;
	//Ptr = &Variable;

	*Ptr = IncrementNumber(*Ptr);

	PrintValue(Variable);
}