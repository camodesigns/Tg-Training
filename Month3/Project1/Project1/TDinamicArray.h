#pragma once
template <typename T>
class TDinamicArray
{
private:
	int ArraySize = 3;
	T* Array = new T[ArraySize];
public:
	TDinamicArray();
	~TDinamicArray();

	T& operator[](int Index)
	{
		return Array[Index];
	}
	const T& operator[](int Index)
	{
		return Array[Index];
	}



	T& Front()
	{
		return Array[0];
	}
	const T& Front()
	{
		return Array[0];
	}


	T& Back()
	{
		int Checker;
		int Counter = 0;
		for (int CurrentIndex = 0; CurrentIndex < ArraySize; CurrentIndex)
		{
			Checker = Array[CurrentIndex];
			if (Checker != 0)
			{
				Counter++:
			}
		}
		return Array[Counter];
	}
	const T& Back() const
	{
		int Checker;
		int Counter = 0;
		for (int CurrentIndex = 0; CurrentIndex < ArraySize; CurrentIndex)
		{
			Checker = Array[CurrentIndex];
			if (Checker != 0)
			{
				Counter++:
			}
		}
		return Array[Counter];
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
		return ArraySize == 0;
	}

	void GetSize() 
	{
		int Checker;
		int Counter = 0;
		for (int CurrentIndex = 0; CurrentIndex < ArraySize; CurrentIndex)
		{
			Checker = Array[CurrentIndex];
			if (Checker != 0)
			{
				Counter++:
			}
		}
		return Counter;
	}
	
	void getCapacity()
	{
		return ArraySize;
	}
	
	
	bool Reserve(int NewArraySize) 
	{
		if (NewArraySize >= ArraySize) 
		{
			return false;
		}
		T* OtherArray = new T[NewArraySize];
		for (int CurrentIndex = 0; CurrentIndex < ArraySize; CurrentIndex++) 
		{
			OtherArray[CurrentIndex] = Array[CurrentIndex];
		
		}
		
		delete Array;
		ArraySize = NewArraySize;

		Array = OtherArray;

		return true;
	}
	
	
	bool ShriktoFit() 
	{
		if (ArraySize == 0) 
		{
			return false;
		}
		T* NewArray = new T[ArraySize];

		for (int CurrentIndex = 0; CurrentIndex < ArraySize; CurrentIndex++) 
		{
			NewArray[CurrentIndex] = Array[CurrentIndex];
		}
		delete Array;
		
		Array = NewArray;
		return true;
	
	}

};

