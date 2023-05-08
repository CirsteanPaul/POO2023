
#pragma once
#include "Exceptions.h"
#include "ArrayIterator.h"
#include "Compare.h"
#include <tuple>
#include <algorithm>

template<typename T>
class ArrayIterator;

template<typename T>
class Array {
private:
	int Capacity;
	int Size;
	T** list;
	bool isIndexValid(int index) {
		return !(index < 0 || index >= Size);
	}
	void AddCapacityIfNeeded() {
		if (Size != Capacity) {
			return;
		}
		Capacity = (Capacity == 0) ? 1 : Capacity * 2;
		T** newList = new T * [Capacity];
		for (int i = 0; i < Size; i++) {
			newList[i] = list[i];
		}
		delete[] list;
		list = newList;
	}

public:
	Array() : Size(0), Capacity(0) {}
	Array(int capacity) : list(new T*[Capacity]), Capacity(capacity), Size(0) {}
	Array(const Array<T>& otherArray); // constructor de copiere
	~Array() {
		for (int i = 0; i < Size; i++) {
			delete list[i];
		}
		if(list != nullptr)
		delete[] list;
	}
	ArrayIterator<T> begin() { return ArrayIterator(*this, 0); }
	ArrayIterator<T> end() { return ArrayIterator(*this, Size); }

	void Sort();
	void Sort(int(*compare)(const T&, const T&));
	void Sort(Compare *comparator);

	int BinarySearch(const T&);
	int BinarySearch(const T&, int(*compare)(const T&, const T&));
	int BinarySearch(const T& elem, Compare* comparator);

	int Find(const T&) const;
	int Find(const T&, int(*compare)(const T&, const T&)) const;
	int Find(const T& elem, Compare* comparator) const;

	const Array<T>& Insert(int index, const T& newElem) throw(IndexOutOfBound);
	const Array<T>& operator+=(const T& newElem);
	const Array<T>& Insert(int index, const Array<T>& otherArray) throw(IndexOutOfBound);
	const Array<T>& Delete(int index) throw(IndexOutOfBound);
	T& operator[] (int index) const  throw(IndexOutOfBound);
	const int GetSize() const { return Size; }
	const int GetCapacity() const { return Capacity; }
};


template<typename T>
T& Array<T>::operator[] (int index) const throw(IndexOutOfBound) {
	if (index < 0 || index >= Size) {
		throw IndexOutOfBound();
	}

	return *list[index];
}

template<typename T>
Array<T>::Array(const Array<T>& otherArray) {
	this->Size = otherArray.Size;
	this->Capacity = otherArray.Capacity;
	this->list = new T * [Capacity];
	for (int i = 0; i < Size; i++) {
		this->list = new T(*otherArray.list);
	}
}

template<typename T>
const Array<T>& Array<T>::Insert(int index, const T& newElem) throw(IndexOutOfBound) {
	bool isValid = isIndexValid(index);
	if (!isValid) {
		throw IndexOutOfBound();
	}
	AddCapacityIfNeeded();

	for (int i = Size; i > index; i--) {
		list[i] = list[i - 1];
	}
	this->list[index] = new T(newElem);
	Size++;
	return *this;
}

template<typename T>
const Array<T>& Array<T>::operator+=(const T& newElem) {
	AddCapacityIfNeeded();
	list[Size++] = new T(newElem);
	return *(this);
}

template<typename T>
const Array<T>& Array<T>::Insert(int index, const Array<T>& otherArray) throw(IndexOutOfBound) {
	bool isValid = isIndexValid(index);
	if (!isValid) {
		throw IndexOutOfBound();
	}
	for (int i = 0; i < otherArray.GetSize(); i ++) {
		this->Insert(index++, *otherArray.list[i]);
	}

	return *(this);
}

template<typename T>
const Array<T>& Array<T>::Delete(int index) throw(IndexOutOfBound) {
	bool isValid = isIndexValid(index);
	if (!isValid) {
		throw IndexOutOfBound();
	}
	delete list[index];
	for (int i = index + 1; i < Size; i++) {
		list[i - 1] = list[i];
	}
	Size--;

	return *this;
}

template<typename T>
void Array<T>::Sort() {
	for (int i = 0; i < Size; i++) {
		for (int j = i + 1; j < Size; j++) {
			if (*list[i] > *list[j]) {
				T* aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
		}	
	}
}

template<typename T>
void Array<T>::Sort(int(*compare)(const T&, const T&)) {
	for (int i = 0; i < Size; i++) {
		for (int j = i + 1; j < Size; j++) {
			if (compare(*list[i], *list[j])) {
				T* aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
		}
	}
}

template<typename T>
void Array<T>::Sort(Compare* comparator) {
	for (int i = 0; i < Size; i++) {
		for (int j = i + 1; j < Size; j++) {
			if (comparator->CompareElements(list[i], list[j])) {
				T* aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
		}
	}
}

template<typename T>
int Array<T>::Find(const T& value) const {
	for (int i = 0; i < Size; i++) {
		if (value == *list[i]) {
			return i;
		}
	}

	return -1;
}

template<typename T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&)) const {
	for (int i = 0; i < Size; i++) {
		if (compare(elem, *list[i])) {
			return i;
		}
	}

	return -1;
}

template<typename T>
int Array<T>::Find(const T& elem, Compare* comparator) const {
	for (int i = 0; i < Size; i++) {
		if (comparator->CompareElements(&(T&)elem, list[i])) {
			return i;
		}
	}

	return -1;
}

template<typename T>
int Array<T>::BinarySearch(const T& elem) {
	// for binary search to work we need to sort the array
	this->Sort();
	int inc = 0, sf = Size - 1;
	while (inc < sf) {
		int mid = (inc + sf) / 2;
		if (*this->list[mid] == elem) {
			return mid;
		}
		if (*this->list[mid] < elem) {
			inc = mid;
		}
		else {
			sf = mid;
		}
	}

	return -1;
}

template<typename T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
	// for binary search to work we need to sort the array
	this->Sort();
	int inc = 0, sf = Size - 1;
	while (inc < sf) {
		int mid = (inc + sf) / 2;
		if (compare(*this->list[mid], elem)) {
			return mid;
		}
		if (*this->list[mid] < elem) {
			inc = mid;
		}
		else {
			sf = mid;
		}
	}

	return -1;
}

template<typename T>
int Array<T>::BinarySearch(const T& elem, Compare* comparator) {
	// for binary search to work we need to sort the array
	this->Sort();
	int inc = 0, sf = Size - 1;
	while (inc < sf) {
		int mid = (inc + sf) / 2;
		if (comparator->CompareElements(this->list[mid], &(T&)elem)) {
			return mid;
		}
		if (*this->list[mid] < elem) {
			inc = mid;
		}
		else {
			sf = mid;
		}
	}

	return -1;
}