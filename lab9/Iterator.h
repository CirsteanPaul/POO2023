#pragma once
#include "Map.h"

template<typename KeyType, typename ValueType>
class Iterator {
public:
	Iterator(Map& map, int index) : map(map), index(index) {}

	bool operator !=(const Iterator& other) const {
		return index != other.index;
	}
	void operator++() { index++; }
	std::tuple<KeyType, ValueType, int> operator*() const {
		return std::make_tuple(map.data[index]->key, map.data[index]->value, index);
	}
private:
	Map& map;
	int index;
};