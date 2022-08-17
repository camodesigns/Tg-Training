#include "Steam.h"

void FSteam::DebugApp() 
{


}

FSteam::FSteam() 
{
	ActiveCommand = MenuCommand::MainMenu;
}

void FSteam::RunApp() 
{
	while (ActiveCommand != MenuCommand::Exit) 
	{
		switch (ActiveCommand)
		{
		case FSteam::MenuCommand::MainMenu:
			OpenMainMenu();
			break;
		case FSteam::MenuCommand::AddGames:
			OpenAddgamesMenu();
			break;
		case FSteam::MenuCommand::Categories:
			OpenCategoriesMenu();
			//Actions();
			break;
		case FSteam::MenuCommand::Exit:
			break;
		case FSteam::MenuCommand::VisualiceGames:
			OpenVisualiceGamesMenu();
			break;
		default:
			break;
		}
	}
}
/*void FSteam::Actions()
{
	switch (ActionChoice)
	{
	case FSteam::Action::CreateCategory:
		CreateCategory();
		break;
	case FSteam::Action::DeleteCategory:
		DeleteCategory();
		break;
	default:
		break;
	}

}*/
void FSteam::OpenMainMenu()
{
	system("CLS");
	std::cout << "Welcome to Steam. What do You want to do?" << std::endl;
	std::cout << "1.Add Games" << std::endl;
	std::cout << "2.Browse Category" << std::endl;
	std::cout << "3.Visualice Games" << std::endl;
	std::cout << "Exit" << std::endl;
	int OptionChoice;
	std::cin >> OptionChoice;
	if (!std::cin.good() || OptionChoice < 1 || OptionChoice > 4) 
	{
		std::cout << "Invalid Input, enter Your new choice" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> OptionChoice;
	}
	ActiveCommand = (MenuCommand)OptionChoice;
	system("CLS");
}

void FSteam::OpenAddgamesMenu()
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	system("CLS");
	std::cout << "Adding a VideoGame ¡Fantastic! Please Follow the process " << std::endl;
	int Choice = 1;
	do 
	{
		system("CLS");
		std::cout << "Please enter the name of the Game" << std::endl;
		std::string EntryGameName;
		std::getline(std::cin, EntryGameName);
		while (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input, please enter Your Game name again:" << std::endl;
			std::getline(std::cin, EntryGameName);
		}
		std::cout << "Please enter the name of the Studio " << std::endl;
		std::string EntryStudioName;
		std::getline(std::cin, EntryStudioName);
		while (!std::cin.good() || EntryGameName=="")
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input, please enter Your Game name again:" << std::endl;
			std::getline(std::cin, EntryStudioName);
		}
		std::cout << "Please enter the day/Month/Year respectively " << std::endl;
		std::cout << "Day: " << std::endl;
		int EntryDay;
		std::cin >> EntryDay;
		if(EntryDay > 30 || EntryDay <= 0 || !std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid entry, please enter the day again: " << std::endl;
			std::cin >> EntryDay;
		}
		std::cout << "Month: " << std::endl;
		int EntryMonth;
		std::cin >> EntryMonth;
		if (EntryMonth > 12 || EntryMonth <= 0 || !std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid entry, please enter the Month again: " << std::endl;
			std::cin >> EntryMonth;
		}
		std::cout << "Year: " << std::endl;
		int EntryYear;
		std::cin >> EntryYear;
		if (EntryYear >= 2023 || EntryYear <= 1961 || !std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid entry, please enter the Year again: " << std::endl;
			std::cin >> EntryYear;
		}
		FVideoGame NewGame(EntryGameName, EntryStudioName, EntryDay, EntryMonth, EntryYear);
		std::cout << "You want create a Category?:" << std::endl;
		std::cout << "1.Yes" << std::endl;
		std::cout << "2.Not" << std::endl;
		int ChoiceSelection;
		std::cin >> ChoiceSelection;
		while (ChoiceSelection <= 0 || ChoiceSelection >= 3 || !std::cin.good()) 
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input, please enter Your choice again" << std::endl;
			std::cin >> ChoiceSelection;
		}
		if (ChoiceSelection == 1)
		{
			std::cout << "Please enter Your Category Title:" << std::endl;
			std::string NewCategoryTitle;
			std::getline(std::cin, NewCategoryTitle);
			while ( !std::cin.good() || std::cin.peek() == '\n') 
			{
				std::cin.clear();
				std::cin.ignore(1000,'\n');
				std::cout << "Invalid input, please enter Your Category title or name again:" << std::endl;
				std::getline(std::cin, NewCategoryTitle);
			}
			std::cin.ignore(1000, '\n');
			FCategory NewCategory(NewCategoryTitle);
			NewCategory.AddGame(NewGame);
			CategoryContainer.AddCategory(NewCategory);
			std::cout << "Game added done" << std::endl;
			std::cout << "What do you want to do now?" << std::endl;
			std::cout << "1. Add other Game" << std::endl;
			std::cout << "2.Back to the Main menu" << std::endl;
			std::cin >> Choice;
		}
		else if (ChoiceSelection == 2)
		{
			std::cout << "You want Add the Game to a category?" << std::endl;
			std::cout << "1.Yes" << std::endl;
			std::cout << "2.Not" << std::endl;
			int ChoiseOption;
			std::cin >> ChoiseOption;
			while (!std::cin.good() || ChoiseOption > 2 || ChoiseOption < 1) 
			{
				std::cout << "Invalid input, Enter your a new choice:" << std::endl;
				std::cin >> ChoiseOption;
			}
			if(ChoiseOption == 1){
			std::cout << "You can see all the Categories in here, Please select one to add the game" << std::endl;
			for (int CategoryIndex = 0; CategoryIndex < 5; CategoryIndex++) 
			{
				std::cout << CategoryIndex << " " << CategoryContainer.GetCategory(CategoryIndex).GetCategoryTitle() << std::endl;
			}
			
			int CategoryChoice;
			std::cin >> CategoryChoice;
			while (!std::cin.good() || CategoryChoice < 0 || CategoryChoice >= 5) 
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Invalid input, Please repeat Your choice" << std::endl;
				std::cin >> CategoryChoice;
			}
			if(CategoryContainer.GetCategory(CategoryChoice).GetCategoryTitle() == "" || CategoryContainer.GetCategory(CategoryChoice).GetCategoryTitle() == " ")
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Sorry the category Does not exist or is not  valid, please make a other choice" << std::endl;
				std::cin >> CategoryChoice;
			}
			CategoryContainer.AddGameToCategory(CategoryChoice,NewGame);
			std::cout << "GameAdded" << std::endl;
			std::cout << "1. Add other Game" << std::endl;
			std::cout << "2. Back to the Main menu" << std::endl;
			std::cin >> Choice;
			}
			else if (ChoiseOption == 2) 
			{
				Uncategorized.AddGame(NewGame);
				std::cout << "GameAdded" << std::endl;
				std::cout << "Please select a option:" << std::endl;
				std::cout << "1. Add other Game" << std::endl;
				std::cout << "2. Back to the Main menu" << std::endl;
				std::cin >> Choice;
			}
		}
	} while (Choice == 1);
	if (std::cin.peek() == '\n')
	
	if (Choice == 2) 
	{
		ActiveCommand = MenuCommand::MainMenu;		
	}
}

void FSteam::OpenCategoriesMenu() 
{
	system("CLS");
	
	int Choice = 1;
	do 
	{
		system("CLS");
		std::cout << "Here are Your Categories" << std::endl;
		for (int CategoryIndex = 0; CategoryIndex < 5; CategoryIndex++)
		{
			std::cout << CategoryIndex << " " << CategoryContainer.GetCategory(CategoryIndex).GetCategoryTitle() << std::endl;
		}
		std::cout << "What do You want to do?" << std::endl;
		std::cout << "1. Create Category" << std::endl;
		std::cout << "2. Eliminate Category" << std::endl;
		std::cout << "3.Back to the Main menu" << std::endl;
		int ChoiceAction;
		std::cin >> ChoiceAction;
		while (!std::cin.good() || Choice <= 0 || Choice > 3) 
		{
			std::cin.clear();
			std::cin.ignore(1000,'\n');
			std::cout << "Invalid input, please enter a new Choice:" << std::endl;
			std::cin >> ChoiceAction;
		}
		if (ChoiceAction == 1)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			system("CLS");
			std::cout << "Please enter the name of Your new category:" << std::endl;
			std::string Title;
			std::getline(std::cin, Title);
			while (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Invalid input or title for a category, Please enter an new name for the category:" << std::endl;
				std::getline(std::cin, Title);
			}
			if (CategoryContainer.GetCategoryCount() >= 5)
			{
				std::cout << "Sorry, You can not add more categories" << std::endl;
				std::cout << "You can Goback to the Category Menu menu Presssing Enter or Presss 2 for go back to the main menu" << std::endl;
				std::cin >> Choice;
				if (!std::cin.good() || Choice >= 3 || Choice <= 1)
				{
					std::cin.clear();
					std::cout << "Invalid input, Plese enter Your new Choice:" << std::endl;
					std::cin >> Choice;
				}
				else if (std::cin.peek() == '\n' || Choice == '\n')
				{
					ActiveCommand = MenuCommand::Categories;
				}
				if (Choice == 2)
				{
					ActiveCommand = MenuCommand::MainMenu;
				}
			}
			FCategory NewCategory(Title);
			CategoryContainer.AddCategory(NewCategory);
			std::cout << "Category Created" << std::endl;
			std::cout << "What do You want to do?" << std::endl;
			std::cout << "1.Create other category" << std::endl;
			std::cout << "2.Back to the main Menu" << std::endl;
			std::cin >> Choice;
			if (!std::cin.good() || Choice >= 3 || Choice <= 0) 
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Invalid input, enter a new Choice";
				std::cin >> Choice;
			}
		}
		else if (ChoiceAction == 2)
		{
			int Choice;
			if (CategoryContainer.GetCategoryCount() == 0)
			{
				std::cout << "You dont have categories for edit " << std::endl;
				std::cout << "Presss 2 for back to de Main menu" << std::endl;
				std::cout << "Presss enter for back to the previous menu" << std::endl;
				std::cin >> Choice;
				if (std::cin.peek() == '\n' || Choice == '\n')
				{
					ActiveCommand = MenuCommand::Categories;
				}
			}
			else
			{
				for (int CategoriesIndex = 0; CategoriesIndex < 5; CategoriesIndex += 1)
				{
					std::cout << CategoriesIndex << " " << CategoryContainer.GetCategory(CategoriesIndex).GetCategoryTitle() << std::endl;
				}
				std::cout << "Please select the category that you want for eliminate:" << std::endl;
				int SelectedToDelete;
				std::cin >> SelectedToDelete;
				while (!std::cin.good())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Invalid input, please enter  Your new selection:" << std::endl;
					std::cin >> SelectedToDelete;
				}
				CategoryContainer.EliminateCategory(SelectedToDelete);
				std::cout << "Category Eliminated" << std::endl;
				std::cout << "Presss enter to go back to teh previous menu" << std::endl;
				std::cout << "Presss 2 to back to the main menu" << std::endl;
				std::cin >> Choice;
				if (!std::cin.good())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Invalid input, enter Your New Choice Please:" << std::endl;
					std::cin >> Choice;
				}
				if (std::cin.peek() == '\n' || Choice == '\n')
				{
					ActiveCommand = MenuCommand::Categories;
				}

			}
		}
		else if (ChoiceAction == 3)Choice = 2;
	} while (Choice == 1);
	if (Choice == 2)ActiveCommand = MenuCommand::MainMenu;
	
}



void FSteam::OpenVisualiceGamesMenu()
{
		for (int CategoryIndex = 0; CategoryIndex < 5; CategoryIndex+=1)
		{
			if (CategoryContainer.GetCategoryCount() != 0)
			{
				std::cout << CategoryIndex << " " << CategoryContainer.GetCategory(CategoryIndex).GetCategoryTitle() << std::endl;
				CategoryContainer.GetCategory(CategoryIndex).DisplayGames();
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "You don´t  have VideoGames, I can´t show you anything" << std::endl;
				break;
			}	
		}
		
		std::cout << "Press any number or press enter to go back to the previous Menu" << std::endl;
		int Choice;
		if (std::cin.peek() == '\n')
		{
			ActiveCommand = MenuCommand::MainMenu;
		}
		std::cin >> Choice;
		if(!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input, enter a new entry" << std::endl;
			std::cin >> Choice;
		}
			
}
