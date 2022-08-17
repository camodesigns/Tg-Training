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
	FCategory(std::string NewCategoryTitle);
	
	FVideoGame GetGames(int GameIndex);
	std::string GetCategoryTitle() const;

	void SetCategoryTitle(const std::string NewCategoryTitle);

	void DisplayGamesCount()const;
	void DisplayGames();

	bool AddGame(FVideoGame VideoGame);
};