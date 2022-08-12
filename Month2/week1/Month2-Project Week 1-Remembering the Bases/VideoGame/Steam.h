#pragma once
#include "CategoryContainer.h"
class FSteam 
{
private:
	FCategoryContainer CategoryContainer;
	enum class MenuCommand {MainMenu, AddGames, Categories ,VisualiceGames, Exit};
	MenuCommand ActiveCommand;
public:	
	FSteam();
	void DebugApp();
	void RunApp();
	FCategory Uncategorized;
	void DisplayCategories();
private:
	void OpenMainMenu();
	void OpenAddgamesMenu();
	void OpenCategoriesMenu();
	void OpenVisualiceGamesMenu();
};
