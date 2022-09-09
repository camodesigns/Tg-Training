#pragma once
template <typename T>
class TDinamicArray
{
private:
	int Capacity = 3;
	int Size = 0;
	T* Array = new T[Capacity];
public:
	TDinamicArray();
	~TDinamicArray();


	int ValidateIntInput()
	{
		int Input;
		std::cin.ignore(100, '\n');
		while (std::cin.peek() == '\n')
		{
			std::cin.ignore(100, '\n');
			std::cout << "Invalid input, try again" << std::endl;
		}

		std::cin >> Input;
		while (!std::cin.good() || Input <= 0)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid input,try again" << std::endl;
			std::cin >> Input;
		}
		return Input;
	}


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
		}

		delete Array;

		Capacity = RequieredCapacity;
		Array = NewArray;
	}


	void ShriktoFit()
	{

		T* NewArray = new T[Size];

		for (int CurrentIndex = 0; CurrentIndex <= Size; CurrentIndex++)
		{
			NewArray[CurrentIndex] = Array[CurrentIndex];
		}
		delete Array;

		Capacity = Size
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

	void Insert(const int Index, const& Shape)
	{
		std::cout << "In which position do you want to add your Shape?" << std::endl;
		Index = ValidateIntInput();
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
			for (int Currenindex == Size; CurrentIndex >= Index; Currenindex--)
			{
				Array[Currenindex + 1] = Array[Currenindex];
			}
			Size++;
			Array[Index] = Shape;
		}

	}

	void Erase(const int Index)
	{
		std::cout << "In which position do you want to delete the Shape?" << std::endl;
		Index = ValidateIntInput();
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


	void Resize(const int NewCapacity)
	{
		std::cout << "What size do you want your arrangement to be now?" << std::endl;
		NewCapacity = ValidateIntInput();
		T* NewArray = new T[NewCapacity];

		for (int CurrentIndex = 0; CurrentIndex <= NewCapacity)
		{
			NewArray[CurrentIndex] = Array[CurrentIndex];
		}
		delete Array;

		Capacity = NewCapacity;
		Array = NewArray;
	}

	void Append(const TDinamicArray<T>Array1) 
	{
		Reserve(Array1.Size);
		for (int I = 0; I < Array1.Size; i++) 
		{
			PushBack(Array1[i]);
		}
	}
};

