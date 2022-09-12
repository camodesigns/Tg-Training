#pragma once
#include "Square.h"
#include <stdlib.h>     
#include <time.h> 


template <typename T>
class TDinamicArray
{
private:
	int Capacity = 3;
	int Size = 0;
	T* Array = new T[Capacity];
public:
	TDinamicArray() 
	{
	
	}
	TDinamicArray(const int EntryCapacity)
	{
		Array = new T[EntryCapacity];
	
	}
	~TDinamicArray() 
	{
		delete[] Array;
	}

	TDinamicArray(const TDinamicArray<T>& Array1)
	{
		Append(Array1);
	}
	

	T& operator[](int Index)
	{
		return Array[Index];
	}
	const T& operator[](int Index)const
	{
		return Array[Index];
	}



	T& Front()
	{
		return Array[0];
	}
	const T& Front()const 
	{
		return Array[0];
	}


	T& Back()
	{	
		return Array[Size];
	}
	const T& Back() const
	{
		return Array[Size];
	}


	T& GetData()
	{
		return Array;
	}
	const T& GetData() const
	{
		return Array;
	}

	bool Empty()
	{
		return Capacity == 0;
	}

	int GetSize()
	{
		return Size;
	}

	int GetCapacity()
	{
		return Capacity;
	}


	void Reserve(int RequieredCapacity)
	{
		if (RequieredCapacity > Capacity)
		{
			T* NewArray = new T[RequieredCapacity];
			for (int CurrentIndex = 0; CurrentIndex < Capacity; CurrentIndex++)
			{
				NewArray[CurrentIndex] = Array[CurrentIndex];
			}
			delete Array;

			Capacity = RequieredCapacity;
			Array = NewArray;
		}

		
	}


	void ShriktoFit()
	{

		T* NewArray = new T[Size];

		for (int CurrentIndex = 0; CurrentIndex <= Size; CurrentIndex++)
		{
			NewArray[CurrentIndex] = Array[CurrentIndex];
		}
		delete Array;

		Capacity = Size;
		Array = NewArray;
	}

	void Clear()
	{
		if (Size > 0)
		{
			Size = 0;
		}
	}


	void PushBack(const T& NewShape)
	{
		if (Capacity == 0)
		{
			Reserve(1);
			Size++;
			Array[Size] = NewShape;
		}
		if (Size == Capacity)
		{
			int NewCapacity = Capacity * 2;
			T* NewArray = new T[NewCapacity];
			for (int CurrentIndex = 0; CurrentIndex <= Capacity; CurrentIndex++)
			{
				NewArray[CurrentIndex] = Array[CurrentIndex];
			}
			Capacity = NewCapacity;
			delete Array;
			Array = NewArray;
			Size += 1;
			Array[Size] = NewShape;
		}
	}


	void PopBack()
	{
		Size -= 1;
	}

	void Insert(int Index, const T& Shape)
	{
		std::cout << "In which position do you want to add your Shape?" << std::endl;
		std::cin >> Index;
		if (Capacity == Index)
		{
			int NewCapacity = Capacity * 2;
			T* NewArray = new T[NewArray];
			for (int CurrentIndex = 0; CurrentIndex <= Capacity; CurrentIndex++)
			{
				NewArray[CurrentIndex] = Array[CurrentIndex];
			}
			delete Array;

			Capacity = NewCapacity;
			Array = NewArray;
			if (Size == Index)
			{
				Array[Size + 1] = Array[Size];
				Array[Index] = Shape;
			}
			Size += 1;

		}
		if (Capacity == Size)
		{
			int NewCapacity = Capacity * 2;
			T* NewArray = new T[NewArray];
			for (int CurrentIndex = 0; CurrentIndex <= Capacity; CurrentIndex++)
			{
				NewArray[CurrentIndex] = Array[CurrentIndex];
			}
			delete Array;

			Capacity = NewCapacity;
			Array = NewArray;
			for (int CurrentIndex = Size; CurrentIndex >= Index; CurrentIndex--)
			{
				Array[CurrentIndex + 1] = Array[CurrentIndex];
			}
			Size++;
			Array[Index] = Shape;
		}

	}

	void Erase(int Index)
	{
		std::cout << "In which position do you want to delete the Shape?" << std::endl;
		std::cin >> Index;
		if (Index < Size && Size > 1)
		{
			for (int CurrentIndex = Index; CurrentIndex < Size - 1; CurrentIndex++)
			{
				Array[CurrentIndex] = Array[CurrentIndex + 1];

			}
		}
		if (Size == Capacity && Size == 1)
		{
			Size = 0;
		}
		if (Index == Size)
		{
			Size -= 1;
		}
	}


	void Resize(int NewCapacity)
	{
		std::cout << "What size do you want your arrangement to be now?" << std::endl;
		std::cin >> NewCapacity;
		T* NewArray = new T[NewCapacity];

		for (int CurrentIndex = 0; CurrentIndex <= NewCapacity;CurrentIndex++)
		{
			NewArray[CurrentIndex] = Array[CurrentIndex];
		}
		delete Array;
		Capacity = NewCapacity;
		Array = NewArray;
	}

	void Append(const TDinamicArray<T>& Array1) 
	{
		Reserve(Array1.Size);
		for (int I = 0; I < Array1.Size; I++) 
		{
			PushBack(Array1[I]);
		}
	}

	void FillRandSquare(T& Filler)
	{
		srand(time(0));
		float NewSideLenght;
		NewSideLenght = rand();
		T* Array = new FSquare(NewSideLenght);
	}
	bool ItIsFull() 
	{
		if (Size = Capacity) 
		{
			return true;
		}
		return false;
	}
	void SwapArraysSameSize(TDinamicArray<T>& Array1, TDinamicArray<T>& Array2)
	{
		if (Array1.Size = Array2.Size)
		{
			T* TempArray = new T[Array1.Capacity];
			for (int CurrentIndex = 0; CurrentIndex < Array1.Size; CurrentIndex++)
			{
				TempArray[CurrentIndex] = Array1[CurrentIndex];
				Array1[CurrentIndex] = Array2[CurrentIndex];
				Array2[CurrentIndex] = TempArray[CurrentIndex];
			}
			delete[] TempArray;
		}
		
	}

	
};

