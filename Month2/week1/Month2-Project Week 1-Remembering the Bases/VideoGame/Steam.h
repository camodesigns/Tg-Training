#pragma once
#include "CategoryContainer.h"
class FSteam 
{
private:
	FCategoryContainer CategoryContainer;
	enum class MenuCommand {MainMenu, AddGames, Categories ,VisualiceGames, Exit};
	MenuCommand ActiveCommand;
	/*enum class Action { CreateCategory = 1, DeleteCategory };
	Action ActionChoice;*/
public:	
	FSteam();
	void DebugApp();
	void RunApp();
	//void Actions();
	FCategory Uncategorized;
private:
	void OpenMainMenu();
	void OpenAddgamesMenu();
	void OpenCategoriesMenu();
	void OpenVisualiceGamesMenu();
	
};
