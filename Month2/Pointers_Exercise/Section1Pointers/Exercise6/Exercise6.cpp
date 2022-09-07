#include<iostream>
#include <stdlib.h>
#include <time.h>
 
int main()
{
	int Array[10] ;
	int* Ptr = Array;
	srand(time(0));

	
	std::cout << "I have looped through the following numbers:" << std::endl;
	for (Ptr = Array; Ptr < Array; Ptr++) 
	{
		*Ptr = rand();
		std::cout << *Ptr<< "\t";
		
	}
	std::cout << std::endl;
	

	int Sum = 0;
	for (Ptr = Array + 9; Ptr > Array; Ptr--) 
	{
		Sum += *Ptr;
	}
	std::cout << "The sum of all those numbers is: " << Sum << std::endl;
}