#include<iostream>
#include <stdlib.h>
#include <time.h>
 
int main()
{
	int Array[10] ;
	int* Ptr = Array;
	srand(time(0));

	int Sum = 0;
	std::cout << "I have looped through the following numbers:" << std::endl;
	for (int CurrentIndex = 0; CurrentIndex < 10; CurrentIndex++) 
	{
		Ptr[CurrentIndex] = rand();
		std::cout << Ptr[CurrentIndex] << "\t";
		Sum += Ptr[CurrentIndex];
	}
	std::cout << std::endl;
	std::cout << "The sum of all those numbers is: " << Sum << std::endl;

}