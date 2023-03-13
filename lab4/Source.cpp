#include <iostream>
#include "Sort.h"
#include <vector>
#pragma warning(disable : 4996)

int main()
{
	char input[30];
	strcpy(input, "30,20,10,3,4");

	Sort sort = Sort(10, 2, 10);
	sort.BubbleSort();
	sort.Print(); // print decending random array

	sort = Sort();
	sort.InsertSort(true);
	sort.Print(); // 1 2 3 5 6 7

	sort = Sort(6, 10, 20, 40, 100, 30, 20);
	sort.QuickSort(); 
	sort.Print(); // 100 40 20 30 20 10

	sort = Sort("10,20,40,1,3,6");
	sort.BubbleSort(true);
	sort.Print(); // 1 3 6 10 20 40

	sort = { 1, 3, 2, 7, 5, 33 };
	sort.InsertSort();
	sort.Print(); // 33 7 5 3 2 1

	sort = Sort(input);
	sort.QuickSort(true);
	std::cout << sort.GetElementsCount() << '\n'; // 5
	std::cout << sort.GetElementFromIndex(3) << '\n'; // 20
	sort.Print(); //3 4 10 20 30
}