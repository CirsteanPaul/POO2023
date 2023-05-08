#pragma once
#include <iostream>
#include <tuple>
#include "Iterator.h"

template<typename KeyType, typename ValueType>
class Map {
private:
	static const int MaxSize = 300;
	int size = 0;

	struct KeyValuePair {
		KeyType key;
		ValueType value;
	};

	KeyValuePair **data;

	int findIndex(const KeyType& key) const;
	void createValuePair(const KeyType& key) {
		data[size] = new KeyValuePair();
		data[size]->key = key;
		data[size]->value = ValueType();
		size++;
	}

public:
	Map() {
		data = new KeyValuePair*[MaxSize];
	}
	~Map() {
		this->Clear();
		delete[] data;
	}

	ValueType& operator[](const KeyType& key) {
		if (size == MaxSize) {
			throw;
		}

		int index = findIndex(key);

		if (index != -1) {
			return data[index]->value;
		}

		createValuePair(key);
		return data[size - 1]->value;
	}
	void Set(const KeyType& key, const ValueType& value) {
		if (size == MaxSize) {
			throw;
		}

		int index = findIndex(key);
		
		if (index != -1) {
			data[index]->value = value;
			return;
		}

		createValuePair(key);
		data[size - 1]->value = value;
	}
	int Count() const {
		return size;
	}
	bool Includes(const Map<KeyType, ValueType>& other);
	void Clear();
	bool Delete(const KeyType& key) {
		int index = findIndex(key);

		if (index == -1) {
			return false;
		}

		for (int i = index; i < size - 1; i++) {
			data[i]->key = data[i + 1]->key;
			data[i]->value = data[i + 1]->value;
		}

		delete data[size - 1];
		size--;
		return true;
	}
	
	Iterator begin() {
		return Iterator(*this, 0);
	}
	Iterator end() {
		return Iterator(*this, size);
	}

};

template<typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::findIndex(const KeyType& key) const {
	for (int i = 0; i < size; i++) {
		if (data[i]->key == key) {
			return i;
		}
	}

	return -1;
}

template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::Clear() {
	for (int i = 0; i < size; i++) {
		delete data[i];
	}

	size = 0;
}

template<typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::Includes(const Map<KeyType, ValueType>& other) {
	for (int i = 0; i < other.size; i ++) {
		int index = this->findIndex(other.data[i]->key);
		if (index == -1) {
			return false;
		}
	}

	return true;
}