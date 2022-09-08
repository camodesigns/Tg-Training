#pragma once
template <typename T, int N>
class TStaticArray
{
private:
	int SizeArray = N;
	T* Array = new T[N];
public:
	T& operator[](const int Index)
	{
	    return Array[Index];
	}

	const T& operator[](const int Index) const
	{
		return Array[Index];
	}

	T& Front() 
	{
		return Array[0];
	}
	const T& Front() const 
	{
		return Array[0];
	}

	T& Back()
	{
		return Array[SizeArray - 1];
	}
	const T& Back() const 
	{
		return Array[SizeArray - 1];
	}

	T& GetData() 
	{
		return Array;
	}
	const T& GetData() const 
	{
		return Array;
	}

	bool IsEmpty()
	{
		return SizeArray == 0 ;
	}

	void Fill(T Filler)
	{
		for (int FillIndex = 0; FillIndex < SizeArray; FillIndex++)
		{
			Array[FillIndex] = Filler;

		}
	}

	void Swap(TStaticArray& OtherStaticArray)
	{
		TStaticArray<T, N> OtherTempArray;
		for (int CurrentIndex = 0; CurrentIndex < SizeArray; CurrentIndex++)
		{
			OtherTempArray[CurrentIndex] = OtherStaticArray[CurrentIndex];
			OtherStaticArray[CurrentIndex] = Array[CurrentIndex];
			Array = OtherStaticArray[CurrentIndex];
		}
	}
	

};
