#pragma once
#include "VideoGames.h"

class FCategory
{ 
private:
	std::string CategoryTitle;
	const static int MaxGamesCount = 10;
	int GamesCount = 0;
	FVideoGame Games[MaxGamesCount];


public:

	FCategory();
	std::string GetCategoryTitle() const;
	std::string SetCategoryTitle(const std::string NewCategoryTitle);
	bool AddGame(FVideoGame VideoGame);
	FVideoGame GetGames(int GameIndex);
	void DisplayGamesCount()const;
	void DisplayGames();
};