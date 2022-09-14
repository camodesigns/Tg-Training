#pragma once
# include <iostream>
template <typename T>
class TSSList
{
private:
	int Size = 0;
	
	struct FNode
	{
		T Element;
		FNode* Next;
	};
	
	FNode* Head = nullptr;
	FNode* Tail = nullptr;
public:
	TSSList() 
	{

	
	}
	~TSSList()
	{
		Clear();
	}

	TSSList(const TSSList& OtherList) 
	{
			FNode* Current =  OtherList.Head;

			AddHead(Current->Element);
			for (int CurrentIndex = 1; CurrentIndex < OtherList.Size; CurrentIndex++)
			{
				AddTail(Current->Element);
				Current = Current->Next;
			}
	}

	//Access
	

	T& operator[](const int Index) 
	{
		FNode* Current = Head;
		for (int CurrentIndex; CurrentIndex < Index; CurrentIndex++) 
		{
			Current = Current->Next;
		}
		
		return Current->Next;
	}
	const T& operator[](const int Index) const
	{
		FNode* Current = Head;
		for (int CurrentIndex; CurrentIndex < Index; CurrentIndex++)
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

	bool IsEmpty()
	{
		if (Size == 0)
		{
			return true;
		}
		return false;
	}

	T GetSize() 
	{
		return Size;
	}


	// Modificators

	void AddHead(T& NewElement) 
	{
		FNode* NewNode = new FNode;
		NewNode->Next = Head;
		Head = NewNode;
		Size++;
	}

	void AddTail(T& NewElement) 
	{
		FNode* NewNode = new FNode;
		NewNode->Element = NewElement;
		Tail->Next = NewNode;
		Tail = NewNode;
		Size++;
	}

	void Insert(const int Index, T& NewElement ) 
	{
		FNode* NewNode = new FNode;
		NewNode->Element = NewElement;

		FNode* Current = Head;
		for (int CurrentIndex; CurrentIndex < Index ; CurrentIndex++)
		{
			Current = Current->Next;
		}

		NewNode->Next = Current->Next;
		Current->Next = NewNode;
		Size++;
	}

	void Remove(const int Index) 
	{
		FNode* Current = Head;
		
		for (int CurrentIndex; CurrentIndex < Index - 1; CurrentIndex++)
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
		Size = 0;
	}

};