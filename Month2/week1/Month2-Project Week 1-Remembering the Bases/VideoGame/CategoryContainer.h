#pragma once
#include "Category.h"
class FCategoryContainer
{
	private:
		const static int MaxCategoriesCount = 5;
		FCategory Categories[MaxCategoriesCount];
		int CategoriesCount;
		bool IsValidIndex(int Index);
	public:
		FCategoryContainer();

		int GetCategoryCount()const;
		FCategory GetCategory(int Index)const;

		void AddGameToCategory(int index,FVideoGame);
		void AddCategory(FCategory NewCategory);
		
		void EliminateCategory(int EliminationIndex);
		
	
};