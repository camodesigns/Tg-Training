#pragma once
#include "CategoryContainer.h"
class FSteam 
{
private:
	FCategoryContainer CategoryContainer;
	FCategory Uncategorized;
	enum class EMenuCommand {MainMenu, AddGames, Categories ,DisplayGames, Exit};
	EMenuCommand ActiveCommand;

public:	
	FSteam();
	void RunApp();
	
private:
	void OpenMainMenu();
	void OpenAddgamesMenu();
	void OpenCategoriesMenu();
	void OpenVisualiceGamesMenu();
	int GetValidIntInput()const ;
	std::string GetValidStringInput()const;
};
