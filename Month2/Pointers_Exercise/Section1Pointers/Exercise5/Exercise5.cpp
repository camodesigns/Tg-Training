#include <iostream>

int main()
{
	int Array[10] = { 4,3,1,7,9,14,15,10,8,5 };
	int Sum = 0;
	std::cout << "When I use this array:" << std::endl;
	for (int CurrentIndex = 0; CurrentIndex < 10; CurrentIndex++)
	{
		std::cout << Array[CurrentIndex] << " ";
		 Sum += Array[CurrentIndex];
	}
	std::cout << std::endl;
	std::cout << "This is the sum when I loop through the array:" << std::endl;
	std::cout << Sum << std::endl;

	 Sum = 0;
	int* Pointer { Array };
	for ( int CurrentIndex = 0 ; CurrentIndex < 10; CurrentIndex++) 
	{
		Sum += Pointer[CurrentIndex];
	}
	std::cout << "This is the sum when I loop through the array using a pointer:" << std::endl;
	std::cout << Sum << std::endl;



	Sum = 0;
	for (int CurrentIndex = 0; CurrentIndex < 35; CurrentIndex++)
	{
		Sum += Pointer[CurrentIndex];
	}
	std::cout << "This is the sum when I loop through the array using a pointer and out-of-bounds indices:" << std::endl;
	std::cout << Sum << std::endl;
}