#include "CategoryContainer.h"
FCategoryContainer::FCategoryContainer()
{
	CategoriesCount = 0;
}
int FCategoryContainer::GetCategoryCount()const 
{
	return CategoriesCount;
}
void FCategoryContainer::AddCategory(FCategory NewCategory)
{
	Categories[CategoriesCount] = NewCategory;
	CategoriesCount += 1;
}
bool FCategoryContainer::IsValidIndex(int Index)
{
	if (!std::cin.good() || Index > 4 || Index < 0)return false;
	else return true;
	
}
void FCategoryContainer::EliminateCategory(int EliminationIndex)
{
	if (FCategoryContainer::IsValidIndex(EliminationIndex)) 
	{
		for (int IndexPosition = 0;IndexPosition < MaxCategoriesCount;IndexPosition++) 
		{
			if (IndexPosition == EliminationIndex)
			{
				Categories[IndexPosition] = Categories[IndexPosition + 1];
				Categories[IndexPosition + 1] = Categories[IndexPosition + 2];
				CategoriesCount -= 1;
			}
		}
	}
}
FCategory FCategoryContainer::GetCategory(int Index)const 
{
	return Categories[Index];
}
void FCategoryContainer::AddGameToCategory(int Index,FVideoGame Game) 
{
	Categories[Index].AddGame(Game);
}
