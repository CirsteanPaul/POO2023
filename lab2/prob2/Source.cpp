#include <iostream>
#include "StudentsService.h"

int main() {
	Student a, b, c;
	a.setName("Paul");
	a.setEnglishGrade(3);
	a.setHistoryGrade(6);
	a.setMathGrade(10);

	b.setName("George");
	b.setEnglishGrade(10);
	b.setHistoryGrade(3);
	b.setMathGrade(10);

	c.setName("Paul");

	std::cout << compareByName(a, b) << '\n'; // should return -1 Paul < George
	std::cout << compareByName(a, c) << '\n'; // should return 0 Paul = Paul
	
	std::cout << compareByEnglishGrade(a, b) << '\n'; // should return -1  3 < 10
	std::cout << compareByHistoryGrade(a, b) << '\n'; // should return 1  6 > 3
	std::cout << compareByMathGrade(a, b) << '\n'; // should return 0 10 = 10

	std::cout << compareByAverageGrade(a, b) << '\n'; // should return - 1 6.3 < 7.6
}