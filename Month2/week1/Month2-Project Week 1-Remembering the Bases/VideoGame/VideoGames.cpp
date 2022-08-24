#include "VideoGames.h"

FVideoGame::FVideoGame()
{
}
FVideoGame::FVideoGame(const FVideoGame& OtherVideoGame)
{
	GameName = OtherVideoGame.GameName;
	StudioName = OtherVideoGame.StudioName;
	ReleaseDay = OtherVideoGame.ReleaseDay;
	ReleaseMonth = OtherVideoGame.ReleaseMonth;
	ReleaseYear = OtherVideoGame.ReleaseYear;


}
FVideoGame::FVideoGame(const std::string& NewGameName, const std::string& NewStudioName, const int NewDayCreation, const int NewMonthCreation, const int NewYearCreation)
{
	GameName = NewGameName;
	StudioName = NewStudioName;
	ReleaseDay = NewDayCreation;
	ReleaseMonth = NewMonthCreation;
	ReleaseYear = NewYearCreation;
}
FVideoGame::~FVideoGame()
{

}
const std::string& FVideoGame::GetGameName() const
{
	return GameName;
}
const std::string& FVideoGame::GetStudioName() const
{
	return StudioName;
}
int FVideoGame::GetReleaseDay() const
{
	return ReleaseDay;
}
int FVideoGame::GetReleaseMonth() const
{
	return ReleaseMonth;
}
int FVideoGame::GetReleaseYear() const
{
	return ReleaseYear;
}
void FVideoGame::SetGameName(const std::string NewGameName)
{
	GameName = NewGameName;
}
void FVideoGame::SetStudioName(const std::string NewStudioName)
{
	StudioName = NewStudioName;
}
void FVideoGame::SetDayCreation(int NewDayCreation)
{
	ReleaseDay = NewDayCreation;
}
void FVideoGame::SetMonthCreation(const int NewMonthCreation)
{
	ReleaseMonth = NewMonthCreation;
}
void FVideoGame::SetYearCreation(const int NewYearCreation)
{
	ReleaseYear = NewYearCreation;
}
std::string FVideoGame::GetFormattedReleaseDate() const
{
	std::string FormatedDate = "Day " + std::to_string(ReleaseDay) + "/Month " + std::to_string(ReleaseMonth) + "/Year " + std::to_string(ReleaseYear);
	return FormatedDate;
}
bool FVideoGame::IsValid() const
{
	if (ReleaseDay <= 0 || ReleaseDay > 31)
	{
		return false;
	}
	if (ReleaseDay == 31) 
	{
		switch (ReleaseMonth)
		{
		case 11:
		case 4:
		case 9:
		case 6:
		case 2:
			return false;
		}
	}
	if ((ReleaseMonth == 11 && ReleaseDay == 31) || (ReleaseMonth == 4 && ReleaseDay == 31) || (ReleaseMonth == 9 && ReleaseDay == 31) || (ReleaseMonth == 6 && ReleaseDay == 31))
	{
		return false;
	}
	 if (ReleaseMonth <= 0 || ReleaseMonth > 12)
	{
		return false;
	}
	 if (ReleaseYear > 2022 || ReleaseYear < 1993)
	{
		return false;
	}
	 return true;
}




