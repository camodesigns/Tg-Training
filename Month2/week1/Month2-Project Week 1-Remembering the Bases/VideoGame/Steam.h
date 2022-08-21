#pragma once
#include "CategoryContainer.h"
class FSteam 
{
private:
	FCategoryContainer CategoryContainer;
	FCategory Uncategorized;
	enum class EMenuCommand {MainMenu, AddGames, Categories ,DisplayGames, Exit};
	EMenuCommand ActiveCommand;
	/*enum class Action { CreateCategory = 1, DeleteCategory };
	Action ActionChoice;*/
public:	
	FSteam();
	FSteam(FSteam& oldSteam);
	void RunApp();
	//void Actions();
	
private:
	void OpenMainMenu();
	void OpenAddgamesMenu();
	void OpenCategoriesMenu();
	void OpenVisualiceGamesMenu();
	
};
