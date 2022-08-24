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
	FCategory(const FCategory& OtherCategory);
	FCategory(const std::string& NewTitle);
	~FCategory();
	bool GetGameAt(const int Index, FVideoGame& OutGame) const;
	const std::string& GetCategoryTitle() const;

	void SetTitle(const std::string NewTitle);

	void DisplayGamesCount() const;
	void DisplayGames() const;

	bool AddGame(const FVideoGame& VideoGame);
};