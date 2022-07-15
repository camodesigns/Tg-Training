/*Exercise 1 - Understanding classes
Create a class called FirstClass with a public constructor and destructor. Have the constructor output “I’m in the constructor!” and have the destructor output “I’m in the destructor!”. Then, instantiate 5 classes and run your program, are the constructor and destructor calls where you expected them to be?

Now create a loop of at least five iterations. For each iteration, instantiate your class once. Run your program, are the constructor and destructor calls where you expected them to be?

*/
#include <iostream>

#include<string>

class FirstClass 
{
public:
	std::string Texto;
	FirstClass() 
	{
		
	}
	FirstClass(std::string texto) 
	{
		Texto = "I’m in the constructor!";
	}

	~FirstClass() 
	{
		std::cout << "I’m in the destructor!" << std::endl;
	}
	void Print() 
	{
		std::cout << Texto << std::endl;
	}

};



int main()
{
	FirstClass Construct("adsjksjkald");
	for (int i = 0; i < 5; i++) {
		Construct.Print();
	
		
	}

}