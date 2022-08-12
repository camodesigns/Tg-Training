#include "VideoGames.h"

FVideoGame::FVideoGame()
{
	GameName = "";
	StudioName = "";
	DayCreation = 0;
	MonthCreation = 0;
	YearCreation = 0;
}
FVideoGame::FVideoGame(const std::string NewGameName, const std::string NewStudioName, const int NewDayCreation, const int NewMonthCreation, const int NewYearCreation) 
{
	GameName = NewGameName;
	StudioName = NewStudioName;
	DayCreation = NewDayCreation;
	MonthCreation = NewMonthCreation;
	YearCreation = NewYearCreation;
}
std::string FVideoGame::GetGameName()const
{
	return GameName;
}
std::string FVideoGame::GetStudioName()const
{
	return StudioName;
}
int FVideoGame::GetDayCreation()const
{
	return DayCreation;
}
int FVideoGame::GetMonthCreation()const
{
	return MonthCreation;
}
int FVideoGame::GetYearCreation()const
{
	return YearCreation;
}
std::string FVideoGame::SetGameName(const std::string NewGameName)
{
	GameName = NewGameName;
}
std::string FVideoGame::SetStudioName(const std::string NewStudioName)
{
	GameName = NewStudioName;
}
int FVideoGame::SetDayCreation(int NewDayCreation)
{
	DayCreation = NewDayCreation;
}
int FVideoGame::SetMonthCreation(int NewMonthCreation)
{
	MonthCreation = NewMonthCreation;
}
int FVideoGame::SetYearCreation(int NewYearCreation)
{
	YearCreation = NewYearCreation;
}
std::string FVideoGame::GetFormatedDate()const
{
	std::string FormatedDate = "";
	FormatedDate = "Day " + std::to_string(DayCreation) + "/Month " + std::to_string(MonthCreation) + "/Year " + std::to_string(YearCreation);
	return FormatedDate;
}
bool FVideoGame::GameIsValid()const
{
	if (DayCreation <= 0 || DayCreation > 30)return false;
	else if (MonthCreation <= 0 || MonthCreation > 12)return false;
	else if (YearCreation > 2022 || YearCreation < 1993) return false;
	else return true;
}




