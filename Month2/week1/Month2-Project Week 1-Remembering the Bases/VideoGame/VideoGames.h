#pragma once
#include<iostream>
#include <string>

class FVideoGame
{
	private:
		std::string GameName = "";
		std::string	StudioName = "";
		int ReleaseDay = 0;
		int ReleaseMonth = 0;
		int ReleaseYear = 0;
	public:
		FVideoGame();
		FVideoGame(const std::string NewGameName, const std::string NewStudioName, const int NewDay, const int NewMonth, const int NewYear);

		std::string GetGameName() const;
		std::string GetStudioName() const;
		int GetReleaseDay()const;
		int GetReleaseMonth()const;
		int GetReleaseYear()const;
		std::string GetFormattedReleaseDate() const;

		void SetGameName(std::string NewGameName);
		void SetStudioName(std::string NewStudioName);
		void SetDayCreation(const int NewDayCreation);
		void SetMonthCreation(const int NewMonthCration);
		void SetYearCreation(const int NewYearCreation);
	
		bool IsValid()const;
		
};

