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

	int GetSize() const
	{
		return List.GetSize;
	}
	bool IsEmpty() const
	{
		return List.IsEmpty();
	}

	void Push(const T& NewElement)
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