#pragma once
#include "Array.h"

template<typename t>
class Array;
template<typename T>
class ArrayIterator {
public:
    ArrayIterator(Array<T>& list, int current) : list(list), current(current) {};
    ArrayIterator& operator ++();
    ArrayIterator& operator --();
    bool operator=(ArrayIterator<T>&);
    bool operator!=(ArrayIterator<T>&);
    T operator*() const {
        return *GetElement();
    }

    T* GetElement() const;
private:
    Array<T>& list;
    int current;
};

template<typename T>
ArrayIterator<T>& ArrayIterator<T>::operator++() {
    if (current >= this->list.GetSize()) {
        throw new IndexOutOfBound();
    }

    current++;
    return *this;
}

template<typename T>
ArrayIterator<T>& ArrayIterator<T>::operator--() {
    if (current - 1 < 0) {
        throw new IndexOutOfBound();
    }

    current--;
    return *this;
}

template<typename T>
bool ArrayIterator<T>::operator=(ArrayIterator<T>& other) {
    if (other == nullptr) {
        return false;
    }

    this->list = other.list;
    this->current = other.current;
    return true;
}

template<typename T>
bool ArrayIterator<T>::operator!=(ArrayIterator<T>& other) {
    return this->current != other.current;
}

template<typename T>
T* ArrayIterator<T>::GetElement() const {
    return &(this->list[current]);
}