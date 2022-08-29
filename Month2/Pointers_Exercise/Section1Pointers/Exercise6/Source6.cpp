#include<iostream>
#include <stdlib.h>
#include <time.h>
 
int main()
{
	int Array[10] = {};
	int* Ptr = {Array};
	srand(time(0));

	for (int CurrentIndex = 0; CurrentIndex < 10; CurrentIndex++) 
	{
		Ptr[CurrentIndex] = rand();
		CurrentIndex++;

	}
	std::cout << "I have looped through the following numbers:" << std::endl;
	

	for (int i = 0; i < 1; i++)
		std::cout << rand() << " ";
}