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
		FVideoGame(const FVideoGame& OtherVideoGame);
		FVideoGame(const std::string& NewGameName, const std::string& NewStudioName, const int NewDay, const int NewMonth, const int NewYear);
		~FVideoGame();

		const std::string& GetGameName() const;
		const std::string& GetStudioName() const;
		int GetReleaseDay()const;
		int GetReleaseMonth()const;
		int GetReleaseYear()const;
		std::string GetFormattedReleaseDate() const;

		void SetGameName(const std::string NewGameName);
		void SetStudioName(const std::string NewStudioName);
		void SetDayCreation(const int NewDayCreation);
		void SetMonthCreation(const int NewMonthCration);
		void SetYearCreation(const int NewYearCreation);

		bool IsValid()const;
		
};

