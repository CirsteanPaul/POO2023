#pragma once
class Student
{
	char name[30];
	double mathGrade;
	double englishGrade;
	double historyGrade;

public:
	bool setName(const char* name);
	bool setMathGrade(double grade);
	bool setEnglishGrade(double grade);
	bool setHistoryGrade(double grade);

	const char* getName();
	const double getMathGrade();
	const double getEnglishGrade();
	const double getHistoryGrade();
	const double getAverageGrade();
};

