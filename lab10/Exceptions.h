#pragma once
#include<exception>

class IndexOutOfBound : public std::exception {
public:
    const char* what() const throw() {
        return "Index out of bound";
    }
};

class SizeOverFlow : public std::exception {
public:
    const char* what() const throw() {
        return "Overflow array";
    }
};