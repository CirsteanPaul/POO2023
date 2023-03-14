#pragma once
#include <initializer_list>

class Sort
{
	static const int maxArraySize = 200;
	int array[maxArraySize];
	int size = 0;
	int ConvertCharToNumber(char*);
	bool CompareByAscendent(bool ascendent, int, int);
	int Partition(bool ascendent, int, int);
	void QuickSortAlogorithm(bool ascendent, int low, int high);
public:
	Sort(int numberofElements, int minim = 0, int maxim = 20);
	Sort() : array{2, 5, 6, 7, 1, 3}, size(6) {};
	Sort(const std::initializer_list<int>&);
	Sort(int x[], int size);
	Sort(int size, ...);
	Sort(char* s);
	Sort(const char* s);
	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int GetElementsCount();
	int GetElementFromIndex(int index);
};

