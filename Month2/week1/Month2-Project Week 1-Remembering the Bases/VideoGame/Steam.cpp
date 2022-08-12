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
			break;
		case FSteam::MenuCommand::Exit:
			break;
		case FSteam::MenuCommand::VisualiceGames:
			OpenVisualiceGamesMenu();
		default:
			break;
		}
	}
}
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
		while (!std::cin.good() )
		{
			std::cin.good();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input, please enter Your Game name again:" << std::endl;
			std::getline(std::cin, EntryGameName);
		}
		std::cin.ignore(1000, '\n');
		std::cout << "Please enter the name of the Studio " << std::endl;
		std::string EntryStudioName;
		std::getline(std::cin, EntryStudioName);
		while (!std::cin.good() || EntryGameName=="")
		{
			std::cin.good();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input, please enter Your Game name again:" << std::endl;
			std::getline(std::cin, EntryStudioName);
		}
		std::cin.ignore(1000, '\n');
		std::cout << "Please enter the day/Month/Year respectively " << std::endl;
		std::cout << "Day: " << std::endl;
		int EntryDay;
		std::cin >> EntryDay;
		if(EntryDay > 30 || EntryDay <= 0)
		{
			std::cin.good();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid entry, please enter the day again: " << std::endl;
			std::cin >> EntryDay;
		}
		std::cout << "Month: " << std::endl;
		int EntryMonth;
		std::cin >> EntryMonth;
		if (EntryMonth > 12 || EntryMonth <= 0)
		{
			std::cin.good();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid entry, please enter the Month again: " << std::endl;
			std::cin >> EntryMonth;
		}
		std::cout << "Year: " << std::endl;
		int EntryYear;
		std::cin >> EntryYear;
		if (EntryYear > 2022 || EntryMonth < 1962)
		{
			std::cin.good();
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
		if(std::cin.peek()=='\n')
		{
			ActiveCommand = MenuCommand::MainMenu;
			break;
		}
		while (ChoiceSelection < 1 || ChoiceSelection > 2 || std::cin.good()) 
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input, please enter Your choice again" << std::endl;
			std::cin >> ChoiceSelection;
		}
		if (ChoiceSelection = 1)
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
			FCategory NewCategory;
			NewCategory.SetCategoryTitle(NewCategoryTitle);
			NewCategory.AddGame(NewGame);
			CategoryContainer.AddCategory(NewCategory);
			std::cout << "Game added done" << std::endl;
			std::cout << "What do you want to do now?" << std::endl;
			std::cout << "1. Add other Game" << std::endl;
			std::cout << "2.Back to the Main menu" << std::endl;
			std::cin >> Choice;
		}
		else if (ChoiceSelection = 2)
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
			if(ChoiseOption==1){
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
			else if (ChoiseOption = 2) 
			{
				Uncategorized.AddGame(NewGame);
				std::cout << "GameAdded" << std::endl;
				std::cout << "Please select a option:" << std::endl;
				std::cout << "1. Add other Game" << std::endl;
				std::cout << "2. Back to the Main menu" << std::endl;
				std::cin >> Choice;
			}
		}
	} while (Choice = 1);
	if (Choice = 2) 
	{
		ActiveCommand = MenuCommand::MainMenu;		
	}
}

void FSteam::OpenCategoriesMenu() 
{
	system("CLS");
	enum ChoiceOptions{CreateCategory=1,EliminateCategory};
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
		int ActionChoice;
		std::cin >> ActionChoice;
		std::string NewTitle;
		switch (ActionChoice)
		{
		case CreateCategory:
			std::cout << "Please enter the name of Your new category:" << std::endl;
			std::getline(std::cin, NewTitle);
			while(!std::cin.good() || NewTitle == "" || NewTitle == " ")
			{
				std::cin.clear();
				std::cin.ignore(1000,'\n');
				std::cout << "Invalid input or title for a category, Please enter an new name for the category:" << std::endl;
				std::getline(std::cin, NewTitle);
			}
			if (CategoryContainer.GetCategoryCount() >= 5)
			{
				std::cout << "Sorry, You can not add more categories" << std::endl;
				std::cout << "You can Goback to the Category Menu menu pressing Enter or press 2 for go back to the main menu" << std::endl;
				std::cin >> Choice;
				if (!std::cin.good() || Choice > 2 || Choice < 1 )
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Invalid input, enter a new choice Please:" << std::endl;
					std::cin >> Choice;
				}
				if(std::cin.peek() == '\n')
				{
					ActiveCommand = MenuCommand::Categories;
				}
			}
			break;
		case EliminateCategory:
			if(CategoryContainer.GetCategoryCount() == 0)
			{
				std::cout << "You dont have categories for edit " << std::endl;
				std::cout << "Press 2 for back to de Main menu" << std::endl;
				std::cout << "Press enter for back to teh previous menu" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cin >> Choice;
				if (std::cin.peek() == '\n')
				{
					ActiveCommand = MenuCommand::Categories;
				}
			}
			else 
			{
				for (int CategoriesIndex = 0; CategoriesIndex < 5; CategoriesIndex++)
				{
					std::cout << CategoriesIndex << " " << CategoryContainer.GetCategory(CategoriesIndex).GetCategoryTitle() << std::endl;
				}
				std::cout << "Please select the category that you want for eliminate:" << std::endl;
				int SelectedToDelete;
				std::cin >> SelectedToDelete;
				while(!std::cin.good())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Invalid input, please enter  Your new selection:" << std::endl;
					std::cin >> SelectedToDelete;
				}
				CategoryContainer.EliminateCategory(SelectedToDelete);
				std::cout << "Category Eliminated" << std::endl;
				std::cout << "Press enter to go back to teh previous menu" << std::endl;
				std::cout << "Press 2 to back to the main menu" << std::endl;
				std::cin >> Choice;
				if (std::cin.peek() == '\n') ActionChoice = 2;
			}

			break;
		default:
			break;
		}
		
	} while (Choice = 1);
	if (Choice = 2)MenuCommand::MainMenu;
}


