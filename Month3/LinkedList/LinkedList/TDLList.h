#include <iostream>

template<typename T>

class TDLList
{
private:
	struct FNode
	{
		T Element;
		FNode* Next = nullptr;
		FNode* Prev = nullptr;
	};
	FNode* Tail = nullptr;
	FNode* Head = nullptr;
	int Size = 0;

public:
	TDLList()
	{

	}
	TDLList(T& NewElement)
	{
		Head = new FNode();
		Head->Element = NewElement;
		Tail = Head;
		Size = 1;
	}

	TDLList(const TDLList<T>& OtherList)
	{
		FNode* Current = OtherList.Head;
		for (int i = 0; i < OtherList.Size; i++)
		{
			AddTail(Current->Element);
			Current = Current->Next;
		}
	}

	TDLList& operator=(const TDLList<T>& OtherList)
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

	~TDLList()
	{
		Clear();
	}


	T& operator[](const int Index)
	{
		FNode* Current = Head;
		if (Index < 0 || Index>Size)
		{
			return;
		}
		if (Index < (Size / 2))
		{

			for (int CurrentIndex = 0; CurrentIndex = Index; ++CurrentIndex)
			{
				Current = Current->Next;
			}
			return Current->Next;
		}
		else if (Index > (Size / 2))
		{
			for (int CurrentIndex = Size - 1; CurrentIndex = Index; --CurrentIndex)
			{
				Current = Current->Prev;
			}
			return Current->Prev;
		}

	}
	const T& operator[](const int Index) const
	{
		FNode* Current = Head;
		if (Index < 0 || Index>Size)
		{
			return;
		}
		if (Index < (Size / 2))
		{

			for (int CurrentIndex = 0; CurrentIndex = Index; ++CurrentIndex)
			{
				Current = Current->Next;
			}
			return Current->Next;
		}
		else if (Index > (Size / 2))
		{
			for (int CurrentIndex = Size - 1; CurrentIndex = Index; --CurrentIndex)
			{
				Current = Current->Prev;
			}
			return Current->Prev;
		}
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

	bool IsEmpty()
	{
		return Size == 0;
	}

	const int GetSize() const
	{
		return Size;
	}

	void AddHead(const T& NewElement)
	{
		if (Size == 0)
		{
			FNode* NewNode = new FNode;
			NewNode->Element = NewElement;

			Head = NewNode;
			Tail = NewNode;

			++Size;
		}
		else
		{
			FNode* NewNode = new FNode;
			NewNode->Element = NewElement;

			Head->Prev = NewNode;
			NewNode->Next = Head;
			Head = NewNode;
			++Size;
		}
	}

	void AddTail(const T& NewElement)
	{
		if (Tail) {

			/*FNode* NewNode = new FNode;
			NewNode->Element = NewElement;
			NewNode->Next = nullptr;
			Tail->Next = NewNode;
			NewNode->Prev = Tail;
			Tail = NewNode;
			Size++;*/

			Tail->Next = new FNode;
			Tail->Next->Element = NewElement;
			Tail->Next->Prev = Tail;
			Tail = Tail->Next;
			Size++;
		}
		else
		{
			AddHead(NewElement);
		}
	}




	void Insert(const T& NewElement, const int Index)
	{
		if (Index < 0 || Index > Size)
		{
			return;
		}

		else if (Index == 0)
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

			for (int Currentindex = 0; Currentindex < Index; ++Currentindex)
			{
				Current = Current->Next;
			}
			NewNode->Next = Current;
			NewNode->Prev = Current->Prev;
			Current->Prev->Next = NewNode;
			Current->Prev = NewNode;
			Size++;
		}



	}



	void RemoveTail()
	{
		FNode* Current = Tail;
		Tail = Tail->Prev;
		delete Current;
		--Size;
	}

	void Remove(const int Index)
	{
		if (Index >= Size || Index < 0 || Size == 0)
		{
			return;
		}

		else if (Size == 1)
		{
			Clear();
		}
		else if (Index == (Size - 1))
		{
			RemoveTail();

		}
		else
		{
			FNode* Current = Head;

			for (int CurrentIndex = 0; CurrentIndex < Index - 1; CurrentIndex++)
			{
				Current = Current->Next;
			}

			FNode* After = Current->Next;
			Current->Next = After->Next;
			After->Next = nullptr;
			After->Prev = nullptr;
			delete After;
			Current->Next->Prev = Current;
			Size--;
		}

	}



	void Clear()
	{
		for (int CurrentIndex = 0; CurrentIndex < Size; ++CurrentIndex)
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
	TDLList<T> FilterByPredicate(const Pred& Predicate)
	{
		TDLList<T> NewList;
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

		bool operator!=(FIterator CurrentOther)
		{
			return Current != CurrentOther.Current;
		}

		const bool operator!=(FIterator& CurrentOther) const
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
