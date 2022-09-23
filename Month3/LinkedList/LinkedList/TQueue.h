#pragma once
#include "TSLList.h"

template<typename T>

class TQueue
{
private:
	TSLList<T> List;
public:
	TQueue()
	{
	
	}
	~TQueue()
	{
		List.Clear();
	}

	bool IsEmpty()
	{
		return List.IsEmpty();
	}

	T& Front()
	{
		List.GetHead();
	}

	const T& Front() const
	{
		List.GetHead();
	}

	void Enqueue()
	{
		List.AddTail();
	}

	void Dequeue()
	{
		List.RemoveHead();
	}

};

