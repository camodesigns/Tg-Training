#include "CategoryContainer.h"
FCategoryContainer::FCategoryContainer()
{
}
FCategoryContainer::FCategoryContainer(const FCategoryContainer& OtherCategoryContainer)
{
	CategoriesCount = 0;
	CategoriesCount = OtherCategoryContainer.CategoriesCount;
}
FCategoryContainer::~FCategoryContainer() 
{

}
int FCategoryContainer::GetCategoryCount() const
{
	return CategoriesCount;
}

const int FCategoryContainer:: GetMaxCategoriesCount()const
{
	return MaxCategoriesCount;
}

void FCategoryContainer::AddCategory(FCategory& NewCategory)
{
	Categories[CategoriesCount] = NewCategory;
	CategoriesCount += 1;
}

bool FCategoryContainer::IsValidIndex(const int Index) const
{
	if (!std::cin.good() || Index > 4 || Index < 0) 
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool FCategoryContainer::DeleteCategory(const int EliminationIndex)
{
	if (EliminationIndex < CategoriesCount)
	{
		for (int CurrentIndex = 0; CurrentIndex < CategoriesCount - 1; CurrentIndex++)
		{
			Categories[CurrentIndex] = Categories[CurrentIndex + 1];
		}
		CategoriesCount--;
		return true;
	}	
	return false;
}

FCategory FCategoryContainer::GetCategory(const int Index) const
{
	return Categories[Index];
}

void FCategoryContainer::AddGameToCategory(const int Index,const FVideoGame& VideoGame)
{
	Categories[Index].AddGame(VideoGame);
}
