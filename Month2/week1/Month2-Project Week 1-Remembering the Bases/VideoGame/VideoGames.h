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
		std::string GetFormatedDate()const;

		void SetGameName(std::string NewGameName);
		void SetStudioName(std::string NewStudioName);
		void SetDayCreation(const int NewDayCreation);
		void SetMonthCreation(const int NewMonthCration);
		void SetYearCreation(const int NewYearCreation);
	
		bool GameIsValid()const;
		
};

