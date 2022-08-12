#pragma once
#include<iostream>
#include <string>

class FVideoGame
{
	private:
		std::string GameName;
		std::string	StudioName;
		int DayCreation;
		int MonthCreation;
		int YearCreation;
	public:
		FVideoGame();
		FVideoGame(const std::string NewGameName, const std::string NewStudioName, const int NewDay, const int NewMonth, const int NewYear);
		std::string GetGameName()const;
		std::string GetStudioName()const;
		int GetDayCreation()const;
		int GetMonthCreation()const;
		int GetYearCreation()const;
		std::string SetGameName(std::string NewGameName);
		std::string SetStudioName(std::string NewStudioName);
		int SetDayCreation(const int NewDayCreation);
		int SetMonthCreation(const int NewMonthCration);
		int SetYearCreation(const int NewYearCreation);
		std::string GetFormatedDate()const;
		bool GameIsValid()const;
		
};

int main()
{
}