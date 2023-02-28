#include "Student.h"
#include <cstring>
#pragma warning(disable : 4996)

bool Student::setName(const char* name) {
	strcpy(this->name, name);

	return true;
}

bool Student::setMathGrade(double grade) {
	if (grade < 1 || grade > 10) {
		return false;
	}

	this->mathGrade = grade;

	return true;
}

bool Student::setHistoryGrade(double grade) {
	if (grade < 1 || grade > 10) {
		return false;
	}

	this->historyGrade = grade;

	return true;
}

bool Student::setEnglishGrade(double grade) {
	if (grade < 1 || grade > 10) {
		return false;
	}

	this->englishGrade = grade;

	return true;
}

const double Student::getMathGrade() {
	return this->mathGrade;
}

const double Student::getEnglishGrade() {
	return this->englishGrade;
}

const double Student::getHistoryGrade() {
	return this->historyGrade;
}

const double Student::getAverageGrade() {
	return (this->mathGrade + this->englishGrade + this->historyGrade) / 3;
}

const char* Student::getName() {
	return this->name;
}