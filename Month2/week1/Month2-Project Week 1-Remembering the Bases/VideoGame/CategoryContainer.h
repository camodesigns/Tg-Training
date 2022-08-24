#pragma once
#include "Category.h"
class FCategoryContainer
{
	private:
		const static int MaxCategoriesCount = 5;
		FCategory Categories[MaxCategoriesCount];
		int CategoriesCount = 0;
		bool IsValidIndex(const int Index) const;
	public:
		FCategoryContainer();
		FCategoryContainer(const FCategoryContainer& OtherCategoryContainer);
		~FCategoryContainer();

		const int GetMaxCategoriesCount()const;
		int GetCategoryCount() const;
		FCategory GetCategory(const int Index) const;

		void AddGameToCategory(const int Index,const FVideoGame& VideoGame);
		void AddCategory(FCategory& NewCategory);
		
		bool DeleteCategory(const int EliminationIndex);
		
	
};