/*Exercise 1 - Understanding classes
Create a class called FirstClass with a public constructor and destructor. Have the constructor output “I’m in the constructor!” and have the destructor output “I’m in the destructor!”. Then, instantiate 5 classes and run your program, are the constructor and destructor calls where you expected them to be?

Now create a loop of at least five iterations. For each iteration, instantiate your class once. Run your program, are the constructor and destructor calls where you expected them to be?

*/
#include <iostream>

#include<string>

class FFirstClass
{
public:
	std::string ConstructorOutput;
	FFirstClass()
	{
		ConstructorOutput = "I am printing the constructor";
	}
	~FFirstClass()
	{
		std::cout << "I am in the destructor!" << std::endl;
	}
};
void FFirstTest()
{
	FFirstClass Test1;
	FFirstClass Test2;
	FFirstClass Test3;
	FFirstClass Test4;
	FFirstClass Test5;
}
void FSecondTest()
{
	for (int TestLoop = 0; TestLoop < 5; TestLoop++)
	{
		FFirstClass Test;
	}
}
int main()
{
	std::cout << "First test constructor and destructor Output" << std::endl;
	FFirstTest();

	std::cout << "Second Test constructor and destructor Output" << std::endl;
	FSecondTest();
}
