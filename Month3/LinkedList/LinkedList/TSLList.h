#pragma once
# include <iostream>

template <typename T>
class TSLList
{
private:
	
	struct FNode
	{
		T Element;
		FNode* Next = nullptr ;
	};
	
	FNode* Head = nullptr;
	FNode* Tail = nullptr;
	
	int Size = 0;
public:
	TSLList()
	{
	}
	TSLList(const T& NewElement)
	{
		Head = new FNode();
		Head->Element = NewElement;
		Tail = Head;
		Size = 1;
	}

	TSLList(const TSLList<T>& OtherList)
	{
		FNode* Current = OtherList.Head;
		for (int i = 0; i < OtherList.Size; i++)
		{
			AddTail(Current->Element);
			Current = Current->Next;
		}
	}

	TSLList& operator=(const TSLList<T>& OtherList)
	{
		Clear();
		FNode* Current = OtherList.Head;
		for (int CurrentIndex = 0; CurrentIndex < OtherList.Size; CurrentIndex++)
		{
			AddTail(Current->Element);
			Current = Current->Next;
		}
		return *this;
	}

	~TSLList()
	{
		Clear();
	}



	//Access
	

	T& operator[](const int Index) 
	{
		FNode* Current = Head;
		for (int CurrentIndex = 0; CurrentIndex < Index; CurrentIndex++) 
		{
			Current = Current->Next;
		}
		
		return Current->Next;
	}
	const T& operator[](const int Index) const
	{
		FNode* Current = Head;
		for (int CurrentIndex = 0; CurrentIndex < Index; CurrentIndex++)
		{
			Current = Current->Next;
		}

		return Current->Next;
	}


	T& GetHead() 
	{
		return Head->Element;
	}
	const T& GetHead() const
	{
		return Head->Element;
	}

	T& GetTail() 
	{
		return Tail->Element;
	}
	const T& GetTail() const
	{
		return Tail->Element;
	}
	



	//Size-------------------------------------

	bool IsEmpty() const
	{
		return Size == 0;
	}

	int GetSize() 
	{
		return Size;
	}


	// Modificators

	void AddHead(const T& NewElement) 
	{
		
		FNode* NewNode = new FNode;
		NewNode->Element = NewElement;
		NewNode->Next = Head;
		Head = NewNode;
		if (Size == 0) 
		{
			Tail = NewNode;
		}
		
		Size++;
	}

	void AddTail(const T& NewElement) 
	{
		if (Tail)
		{
			FNode* NewNode = new FNode;
			NewNode->Element = NewElement;
			NewNode->Next = nullptr;

			Tail->Next = NewNode;
			Tail = NewNode;

			Size++;
		}
		else 
		{
			AddHead(NewElement);
		}
	}

	void Insert(const T& NewElement, const int Index )
	{
		if (Index < 0 || Index > Size) 
		{
			return;
		}
		if (Index == 0)
		{
			AddHead(NewElement);
		}
		else if (Index == Size) 
		{
			AddTail(NewElement);
		}
		else 
		{
			FNode* NewNode = new FNode;
			NewNode->Element = NewElement;
			FNode* Current = Head;
			FNode* Previous = nullptr;
			for (int CurrentIndex = 0; CurrentIndex < Index; CurrentIndex++)
			{
				Previous = Current;
				Current = Current->Next;
			}

			NewNode->Next = Current;
			Previous->Next = NewNode;
			Size++;
		}
		
		
	}

	void RemoveHead()
	{
		if(Size == 0)
		{
			return;
		}
		else if (Size == 1)
		{
			Clear();
		}
		FNode Current = Head;
		Head = Head->Next;
		delete Current;
		Size--;
	}

	void Remove(const int Index) 
	{
		if (Index >= Size || Index < 0) 
		{
			return;
		}
		FNode* Current = Head;
		
		for (int CurrentIndex = 0; CurrentIndex < Index - 1; CurrentIndex++)
		{
			Current = Current->Next;
		}
		
		FNode* After = Current->Next;
		Current->Next = After->Next;
		delete After;
		Size--;
	}

	void Clear() 
	{
		for (int CurrentIndex = 0; CurrentIndex < Size; CurrentIndex++) 
		{
			FNode* Current = Head;
			Head = Head->Next;
			delete Current;
		}
		Tail = nullptr;
		Size = 0;
	}


	template<typename Pred>
	void ForEach(const Pred& Predicate)
	{
		FNode* Current = Head;
		for (int CurrentIndex = 0; CurrentIndex < Size; CurrentIndex++)
		{
			Predicate(Current->Element);
			Current = Current->Next;
		}
	}


	template<typename Pred>

	T& FindByPredicate(const Pred& Predicate) 
	{
		FNode* Current = Head;
		for (int CurrentIndex; CurrentIndex < Size; CurrentIndex++) 
		{
			if (Predicate(Current->Element)) 
			{
				return *Current;
			}
			Current = Current->Next;
		}
		return nullptr;
	}


	template<typename Pred>
	TSLList<T> FilterByPredicate(const Pred& Predicate) 
	{
		TSLList<T> NewList;
		FNode* Current = Head;
		for (int CurrentIndex = 0; CurrentIndex < Size; CurrentIndex++) 
		{
			if (Predicate(Current->Element)) 
			{
				NewList.AddTail(Current->Element);
			}
			Current = Current->Next;
		}
		return NewList;
	}
	
	template<typename Pred>
	void RemoveAllByPredicate(const Pred& Predicate)
	{
		FNode* Current = Head;
		for (int CurrentIndex = 0; CurrentIndex < Size; CurrentIndex++) 
		{
			T Element = Current->Element;
			Current = Current->Next;
			if (Predicate(Current->Element))
			{
				Remove(CurrentIndex);
				CurrentIndex--;
			}
		}
	}


	class FIterator
	{
	private:
		FNode* Current = nullptr;
	public:
		FIterator(FNode* Currently) 
		{
			Current = Currently;
		}
		FIterator& operator++()
		{
			Current = Current->Next;
			
			return *this;
		}

		T& operator*()
		{
			return Current->Element;
		}

		const T& operator*() const
		{
			return Current->Element;
		}

		bool operator!=(const FIterator CurrentOther) const
		{
			return Current != CurrentOther.Current;
		}

		const bool operator!=(const FIterator& CurrentOther) const
		{
			return Current != CurrentOther.Current;
		}
	};


	
	FIterator end()
	{
		return FIterator(nullptr);
	}

	FIterator begin() 
	{
		return FIterator(Head);
	}

};