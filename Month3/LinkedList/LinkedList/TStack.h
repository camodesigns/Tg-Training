#pragma once
#include "TSLList.h"
template <typename T>

class TStack 
{
private:
	TSLList<T> List;
public:
	TStack()
	{
	
	}

	int GetSize()
	{
		return List.GetSize;
	}
	bool IsEmpty()
	{
		return List.IsEmpty();
	}

	void Push( T& NewElement)
	{
		List.AddHead(NewElement);
	}


	T& Top()
	{
		return List.GetHead();
	}

	const T& Top() const
	{
		return List.GetHead();
	}

	void Pop()
	{
		List.RemoveHead
	}

};