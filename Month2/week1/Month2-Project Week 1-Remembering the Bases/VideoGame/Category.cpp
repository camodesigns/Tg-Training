#include "Category.h"
FCategory::FCategory()
{
}
FCategory::FCategory(const FCategory& OldCategory)
{
	GamesCount = 0;
	Title = OldCategory.Title;
	GamesCount = OldCategory.GamesCount;
}
FCategory::FCategory(const std::string& newTitle)
{
	Title = newTitle;
	GamesCount = 0;
}
FCategory::~FCategory() {

}
const std::string& FCategory::GetCategoryTitle() const
{
	return Title;
}
void FCategory::SetCategoryTitle(std::string NewTitle)
{
	Title = NewTitle;
}
bool FCategory::AddGame(const FVideoGame& VideoGame)
{
	if (VideoGame.IsValid())
	{
		Games[GamesCount] = VideoGame;
		GamesCount += 1;
		return true;
	}
	else return false;

}
void FCategory::DisplayGamesCount() const
{
	std::cout << GamesCount << std::endl;
}
FVideoGame FCategory::GetGame(const int GameIndex) const
{
	return Games[GameIndex];
}

void   FCategory::DisplayGames() const
{
	std::cout << "Games" << std::endl;
	std::cout << "Game Title\t\t\t\tStudio Title\t\t\t\tCreation date" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;
	for (int CurrentGameIndex = 0; CurrentGameIndex < MaxGamesCount; CurrentGameIndex++)
	{
		FVideoGame CurrentGame = Games[CurrentGameIndex];
		std::cout << CurrentGame.GetGameName() << "\t\t\t\t" << CurrentGame.GetStudioName() << "\t\t\t\t" << CurrentGame.GetFormattedReleaseDate() << std::endl;

	}
	std::cout << std::endl;
	std::cout << std::endl;

}