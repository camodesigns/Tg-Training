#pragma once
# include <iostream>
template <typename T>
class TSSList
{
private:
	int Size = 0;

public:
	TSSList() 
	{
	
	}
	struct FNode
	{
		T Element;
		FNode* Next;
	};
	FNode* Head = nullptr;
	FNode* Tail;
	
	T& operator[](const int Index) 
	{
		FNode* Current = Head;
		for (int CurrentIndex; CurrentIndex < Index; CurrentIndex++) 
		{
			Current = Current->Next;
		}
		
		return Current->Next;
	}
	const T& operator[](const int Index)const
	{
		FNode* Current = Head;
		for (int CurrentIndex; CurrentIndex < Index; CurrentIndex++)
		{
			Current = Current->Next;
		}

		return Current->Next;
	}

	T Head() 
	{
		
	}

	T GetSize() 
	{
		return Size;
	}


};