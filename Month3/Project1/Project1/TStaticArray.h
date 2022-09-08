#pragma once
#include <string>
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



};
