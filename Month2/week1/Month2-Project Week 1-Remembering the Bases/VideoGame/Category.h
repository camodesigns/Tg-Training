#pragma once
#include "VideoGames.h"

class FCategory
{
private:
	std::string Title = "";
	const static int MaxGamesCount = 10;
	int GamesCount = 0;
	FVideoGame Games[MaxGamesCount];


public:

	FCategory();
	FCategory(std::string NewTitle);

	FVideoGame GetGame(const int GameIndex) const;
	std::string GetCategoryTitle() const;

	void SetCategoryTitle(const std::string NewTitle);

	void DisplayGamesCount() const;
	void DisplayGames() const;

	bool AddGame(const FVideoGame VideoGame);
};