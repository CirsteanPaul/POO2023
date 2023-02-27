#include "NumberList.h"
#include <algorithm>
#include <iostream>

void NumberList::Init() {
	this->count = 0;
}

bool NumberList::Add(int x) {
	if (this->count == 9) {
		return false;
	}

	this->numbers[count++] = x;

	return true;
}

void NumberList::Sort() {
	std::sort(this->numbers, this->numbers + count);
}

void NumberList::Print() {
	for (int i = 0; i < this->count; i ++) {
		std::cout << this->numbers[i] << " ";
	}
	std::cout << '\n';
}