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

double Student::getMathGrade() {
	return this->mathGrade;
}

double Student::getEnglishGrade() {
	return this->englishGrade;
}

double Student::getHistoryGrade() {
	return this->historyGrade;
}

double Student::getAverageGrade() {
	return (this->mathGrade + this->englishGrade + this->historyGrade) / 3;
}

char* Student::getName() {
	return this->name;
}