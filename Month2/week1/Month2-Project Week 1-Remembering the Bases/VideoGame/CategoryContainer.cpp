#include "CategoryContainer.h"
FCategoryContainer::FCategoryContainer()
{
}

int FCategoryContainer::GetCategoryCount() const
{
	return CategoriesCount;
}

void FCategoryContainer::AddCategory(FCategory NewCategory)
{
	Categories[CategoriesCount] = NewCategory;
	CategoriesCount += 1;
}

bool FCategoryContainer::IsValidIndex(const int Index) const
{
	if (!std::cin.good() || Index > 4 || Index < 0) {
		return false;
	}
	else
	{
		return true;
	}
}

void FCategoryContainer::EliminateCategory(const int EliminationIndex)
{
	if (IsValidIndex(EliminationIndex))
	{
		for (int IndexPosition = 0; IndexPosition < MaxCategoriesCount; IndexPosition++)
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

FCategory FCategoryContainer::GetCategory(int Index) const
{
	return Categories[Index];
}

void FCategoryContainer::AddGameToCategory(const int Index, FVideoGame VideoGame)
{
	Categories[Index].AddGame(VideoGame);
}
