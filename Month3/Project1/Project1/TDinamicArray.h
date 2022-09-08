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



};

