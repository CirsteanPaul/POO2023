#include "Sort.h"
#include <cstdarg>
#include <ctime>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)

Sort::Sort(int size, int min, int max) {
	srand(time(NULL));
	int index = 0;
	const int maximumSize = maxArraySize < size ? maxArraySize : size;
	const int maxx = std::max(max, min);
	const int minn = std::min(max, min);
	int difference = maxx - minn;
	if (difference == 0) difference = minn;
	this->size = size;

	for (int i = 0; i < maximumSize;i++) {
		int randomNumber = rand() % (difference) + minn;
		if (difference == minn) {
			randomNumber = minn;
		}
		this->array[index++] = randomNumber;
	}
}

Sort::Sort(int x[], int size) {
	int maximumSize = (maxArraySize < size ? maxArraySize : size);

	this->size = size;
	for (int i = 0; i < maximumSize; i++) {
		this->array[i] = x[i];
	}
}

Sort::Sort(char* s) {
	const char* delimiters = ",";
	char* p = strtok(s, delimiters);

	while (p) {
		int number = ConvertCharToNumber(p);
		this->array[this->size++] = number;
		p = strtok(NULL, delimiters);
	}

	delete p;
}
Sort::Sort(const std::initializer_list<int>& values) {
	int i = 0;

	for (auto it = values.begin(); it != values.end() && i < maxArraySize; ++it, ++i) {
		array[i] = *it;
	}

	size = i;
}


Sort::Sort(const char const * s) {
	const char* delimiters = ",";
	int sizeofString = strlen(s);
	char* s1 = new char[sizeofString];
	strcpy(s1, s);
	char* p = strtok(s1, delimiters);

	while (p) {
		int number = ConvertCharToNumber(p);
		this->array[this->size++] = number;
		p = strtok(NULL, delimiters);
	}

	delete p;
	delete[] s1;
}

Sort::Sort(int count, ...) {
	va_list args;
	va_start(args, count);

	while (count != 0) {
		int item = va_arg(args, int);
		this->array[this->size++] = item;
		count--;
	}

	va_end(args);
}

void Sort::BubbleSort(bool ascendent) {
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = i + 1; j < this->size; j++) {
			if (CompareByAscendent(ascendent, this->array[i], this->array[j])) {
				std::swap(this->array[i], this->array[j]);
			}
		}
	}
}

void Sort::InsertSort(bool ascendent) {
	for (int i = 1; i < this->size; i++)
	{
		const int aux = this->array[i];
		int previousIndex = i - 1;

		while (previousIndex >= 0 && CompareByAscendent(ascendent, this->array[previousIndex], aux))
		{
			this->array[previousIndex + 1] = this->array[previousIndex];
			previousIndex--;
		}

		this->array[previousIndex + 1] = aux;
	}
}

void Sort::QuickSort(bool ascendent) {
	QuickSortAlogorithm(ascendent, 0, this->size - 1);
}

int Sort::GetElementsCount() {
	return this->size;
}

void Sort::Print() {
	for (int i = 0; i < this->size; i++) {
		std::cout << this->array[i] << ' ';
	}

	std::cout << '\n';
}

int Sort::GetElementFromIndex(const int index) {
	if (index >= size || index < 0) {
		return 0;
	}
	return this->array[index];
}

int Sort::ConvertCharToNumber(char* s) {
	const int size = strlen(s);
	int number = 0;

	for (int i = 0; i < size; i++) {
		number = number * 10 + (s[i] - '0');
	}

	return number;
}

bool Sort::CompareByAscendent(bool ascendent, int x, int y) {
	if (ascendent) {
		return x > y;
	}

	return x < y;
}

void Sort::QuickSortAlogorithm(bool ascendent, int low, int high)
{
	if (low < high) {

		const int pi = Partition(ascendent, low, high);

		QuickSortAlogorithm(ascendent, low, pi - 1);
		QuickSortAlogorithm(ascendent, pi + 1, high);
	}
}

int Sort::Partition(bool ascendent, int low, int high)
{
	const int pivot = this->array[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		
		if (CompareByAscendent(ascendent, pivot,  this->array[j])) {
			i++;
			std::swap(this->array[i], this->array[j]);
		}
	}
	std::swap(this->array[i + 1], this->array[high]);
	return (i + 1);
}
