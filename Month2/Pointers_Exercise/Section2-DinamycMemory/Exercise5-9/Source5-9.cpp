#include<iostream>
#include <string>
class FStudent
{

private:
	int Age;
	char* Name;
public:

	FStudent()
	{
		Name = nullptr;
		Age = 0;
	}


	FStudent(int EntryAge)
	{
		Name = nullptr;
		Age = EntryAge;
	}

	~FStudent()
	{
		delete Name;
	}
	
	void SetAge(const int NewAge)
	{
		Age = NewAge;
	}
	
	void SetName(const char* NewName)
	{
		int CharNameLength = 0;
		if (Name)
		{
			delete Name;
			Name = nullptr;
		}

		for (int CurrentCharIndex = 0; NewName[CurrentCharIndex] != '\0'; CurrentCharIndex++)
		{
			CharNameLength++;
		}

		Name = new char[CharNameLength + 1];
		memcpy_s(Name, sizeof(char) * (CharNameLength + 1), NewName, sizeof(char) * (CharNameLength + 1));
	}

	void PrintStudentData()
	{
		std::cout << "Name: " << Name << std::endl;
		std::cout << "Age: " << Age << std::endl;
	}
};
int ValidateIntInput()
{
	int Input;
	std::cin >> Input;
	while (!std::cin.good() || Input <= 0 )
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid input, please try again:" << std::endl;
		std::cin >> Input;
	}
	return Input;
}
//revisar
bool ValidateCharInput(char* Name)
{
	std::cin.ignore(100, '\n');
	while (std::cin.peek() == '\n')
	{
		std::cin.ignore(100, '\n');
		std::cout << "Invalid input, try again" << std::endl;
	}
	
	std::cin >> Name;
	
	while (!std::cin.good() || Name == "" )
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Input,try again:" << std::endl;
		std::cin >> Name;
	}
	return true;
		
}




int main()
{

	FStudent* Student = new FStudent(5);
	Student->SetName("Santiago");
	delete Student;

	std::cout << "The student was deleted from memory, but the name remains. The class FStudent tries to call the destructor for delete all the data but the name is primitive and cannot be deleted automatically" << std::endl;


	std::cout << "How many students do you want? " << std::endl;

	int StudentsNumber = ValidateIntInput();

	FStudent* Students = new FStudent[StudentsNumber];

	std::cout << "You  have " << StudentsNumber << " students!" << std::endl;

	for (int CurrentIndex = 0; CurrentIndex < StudentsNumber; CurrentIndex++)
	{
		std::cout << "Enter the name of the student number" << CurrentIndex + 1 << ": ";
		char Name[32] ;
		ValidateCharInput(Name);
		

		std::cout << "Enter the age of the student number" << CurrentIndex + 1 << ": ";
		int Age = ValidateIntInput();
	
		Students[CurrentIndex].SetAge(Age);
		Students[CurrentIndex].SetName(Name);
	}


	std::cout << "Your students:" << std::endl;

	for (int StudentsIndex = 0; StudentsIndex < StudentsNumber; StudentsIndex++)
	{
		std::cout << "Student " << StudentsIndex + 1 << std::endl;
		Students[StudentsIndex].PrintStudentData();
	}
	delete[] Students;
}