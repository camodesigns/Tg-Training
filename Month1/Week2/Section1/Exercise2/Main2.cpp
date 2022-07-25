


/*Exercise 2 - Military Clock
Create a class called MilitaryClock that stores and displays the military time.

Your class should contain the following constructors and methods:
MilitaryClock();
MilitaryClock(short hours, short minutes);
void SetTime(short hours, short minutes);
void DisplayTime();
Example output
0000
0700
1215
*/
#include <iostream>

#include<string>

class FMilitaryClock
{
private:
	short Hours;
	short Minutes;
public:
	std::string Texto;
	FMilitaryClock()
	{
		 Hours = 0;
		 Minutes = 0;
	}
	FMilitaryClock(const short  InitialHours, const short  InitialMinutes)
	{
		 Hours = InitialHours;
		 Minutes = InitialMinutes;
	}
	void SetTime(const short   SetHours, const short  SetMinutes)
	{
		Hours = SetHours;
		Minutes = SetMinutes;
	}
	void DisplayTime()
	{
		if (Hours < 10)
		{
			std::cout << "0" << Hours;
		}
		else
		{
			std::cout << Hours;
		}
		 if (Minutes < 10) 
		{
			std::cout << Minutes << "0" <<std::endl;
		}
		 else
		 {
			 std::cout << Minutes << std::endl;
		 }
	}
};

int main()
{
	FMilitaryClock clock;
	clock.DisplayTime();
	//assign the initial time of the element of type FMilitaryClock
	clock=FMilitaryClock(7, 12);
	clock.DisplayTime();
	//Actualiza el tiempo del elemento tipo FMilitaryClock
	clock.SetTime(12, 15);
	clock.DisplayTime();
}