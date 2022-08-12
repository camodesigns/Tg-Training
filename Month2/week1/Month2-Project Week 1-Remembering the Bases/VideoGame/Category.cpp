#include "Category.h"
FCategory::FCategory()
{
	CategoryTitle = "";
	GamesCount = 0;
}
std::string FCategory::GetCategoryTitle()const
{
	return CategoryTitle;
}
std::string FCategory::SetCategoryTitle(std::string NewCategoryTitle)
{
	CategoryTitle = NewCategoryTitle;
}
bool FCategory::AddGame(FVideoGame VideoGame)
{
	if (FVideoGame::GameIsValid)
	{
		Games[GamesCount] = VideoGame;
		GamesCount++;
		return true;
	}
	else return false;
	
}
void FCategory::DisplayGamesCount()const
{
	std::cout << GamesCount << std::endl;
}
FVideoGame FCategory::GetGames(int GameIndex)
{
	return Games[GameIndex];
}

void   FCategory::DisplayGames()
{
	std::cout << "Games" << std::endl;
	std::cout << "Game Title\t\t\t\tStudio Title\t\t\t\tCreation date" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;
	for (int CurrentGameIndex = 0; CurrentGameIndex < MaxGamesCount; CurrentGameIndex++)
	{
		FVideoGame CurrentGame = Games[CurrentGameIndex];
		std::cout << CurrentGame.GetGameName() << "\t\t\t\t" << CurrentGame.GetStudioName() << "\t\t\t\t" << CurrentGame.GetFormatedDate() << std::endl;

	}
	std::cout << std::endl;
	std::cout << std::endl;

}