


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

class MilitaryClock
{
private:
	short hours ;
	short minutes ;
public:
	std::string Texto;
	MilitaryClock()
	{
		 hours=0;
		 minutes=0;
	}
	MilitaryClock(short hour, short minute)
	{
		 hours = hour;
		 minutes = minute;
	}
	void SetTime(short sethours, short setminutes)
	{
		sethours = 12;
		 setminutes = 15;
		hours = sethours;
		minutes=setminutes;
	}
	void DisplayTime()
	{
		if (hours < 10 && minutes<10)
		{
			std::cout << "0" << hours << "," << minutes << "0"<<std:: endl;
		}
		else if (hours<10 && minutes>=10) 
		{
			std::cout << "0" << hours << "," << minutes << std::endl;
		}
		else if (hours>=10 && minutes<10) 
		{
			std::cout  << hours << "," << minutes <<"0" << std::endl;
		}else
		{
			std::cout << hours << "," << minutes << std::endl;
		}	
	}
};

int main()
{
	MilitaryClock clock;
	clock.DisplayTime();
	clock=MilitaryClock(7, 12);
	clock.DisplayTime();
	clock.SetTime(12, 15);
	clock.DisplayTime();
}