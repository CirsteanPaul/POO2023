#include "Number.h"
#include <cstring>
#include <iostream>
#pragma warning(disable : 4996)

#pragma region Constructors

Number::Number(char* number, int base) {
	this->base = base;
	strcpy(this->number, number);
}

Number::Number(int number, int base) {
	this->base = base;
	char* convertedNumber = FromDecimalToBase(base, number);

	strcpy(this->number, convertedNumber);
	delete[] convertedNumber;
}

Number::Number(const char* number, int base) {
	this->base = base;
	strcpy(this->number, number);
}

Number::Number(const Number& source) {
	this->base = source.base;
	strcpy(this->number, source.number);
	std::cout << "Copy contructor\n";
}

Number::Number(Number&& source) noexcept {
	this->base = source.base;
	strcpy(this->number, source.number);
	std::cout << "Move contructor\n";
}

#pragma endregion

#pragma region Public methods

void Number::SwitchBase(int newBase) {
	int decimalNumber = FromBaseToDecimal(this->number, this->base);
	char* x = FromDecimalToBase(newBase, decimalNumber);
	strcpy(this->number, x);
	this->base = newBase;

	delete[] x;
}

void Number::Print() {
	std::cout << this->number << '\n';
}

int Number::GetDigitsCount() {
	int size = strlen(this->number);

	return size;
}

int Number::GetBase() {
	return this->base;
}
#pragma endregion

#pragma region Equal Operator

Number Number::operator=(int number) {
	char *convertedNumber = FromDecimalToBase(this->base, number);
	strcpy(this->number, convertedNumber);

	delete[] convertedNumber;

	return this->number;
}

Number Number::operator=(char* number) {
	const int sizeOfNumber = strlen(number);
	long long integerNumber = 0;

	for (int i = 0; i < sizeOfNumber; i++) {
		integerNumber = integerNumber * 10 + (number[i] - '0');
	}

	char* convertedNumber = FromDecimalToBase(this->base, integerNumber);
	strcpy(this->number, convertedNumber);

	delete[] convertedNumber;

	return this->number;
}

Number Number::operator=(const char* number) {
	int sizeOfNumber = strlen(number);
	long long integerNumber = 0;

	for (int i = 0; i < sizeOfNumber; i++) {
		integerNumber = integerNumber * 10 + (number[i] - '0');
	}

	char* convertedNumber = FromDecimalToBase(this->base, integerNumber);
	strcpy(this->number, convertedNumber);
	delete[] convertedNumber;

	return this->number;
}

Number Number::operator=(Number y) {
	this->base = y.base;
	strcpy(this->number, y.number);

	return this->number;
}

#pragma endregion

#pragma region Other Operators (+ -)

Number Number::operator+(int number) {
	long long classNumberDecimal = FromBaseToDecimal(this->number, this->base);
	classNumberDecimal += number;

	char* convertedNumber = FromDecimalToBase(this->base, classNumberDecimal);

	strcpy(this->number, convertedNumber);
	delete[] convertedNumber;

	return this->number;
}

Number Number::operator+(char* number) {
	long long classNumberDecimal = FromBaseToDecimal(this->number, this->base);
	long long numberToBeAdded = FromBaseToDecimal(number, this->base);
	classNumberDecimal += numberToBeAdded;

	char* convertedNumber = FromDecimalToBase(this->base, classNumberDecimal);

	strcpy(this->number, convertedNumber);
	delete[] convertedNumber;

	return this->number;
}

Number Number::operator+(const char* number) {
	long long classNumberDecimal = FromBaseToDecimal(this->number, this->base);
	char* auxNumber = new char[200];

	strcpy(auxNumber, number);

	long long numberToBeAdded = FromBaseToDecimal(auxNumber, this->base);
	classNumberDecimal += numberToBeAdded;

	char* convertedNumber = FromDecimalToBase(this->base, classNumberDecimal);

	strcpy(this->number, convertedNumber);
	delete[] convertedNumber;

	return this->number;
}

Number Number::operator-(int number) {
	long long classNumberDecimal = FromBaseToDecimal(this->number, this->base);

	if (number > classNumberDecimal) {
		return 0;
	}

	classNumberDecimal -= number;

	char* convertedNumber = FromDecimalToBase(this->base, classNumberDecimal);

	strcpy(this->number, convertedNumber);
	delete[] convertedNumber;

	return this->number;
}

Number Number::operator-(char* number) {
	long long classNumberDecimal = FromBaseToDecimal(this->number, this->base);
	long long numberToBeAdded = FromBaseToDecimal(number, this->base);

	if (numberToBeAdded > classNumberDecimal) {
		return 0;
	}

	classNumberDecimal -= numberToBeAdded;

	char* convertedNumber = FromDecimalToBase(this->base, classNumberDecimal);

	strcpy(this->number, convertedNumber);
	delete[] convertedNumber;

	return this->number;
}

Number Number::operator-(const char* number) {
	long long classNumberDecimal = FromBaseToDecimal(this->number, this->base);
	char* auxNumber = new char[200];

	strcpy(auxNumber, number);

	long long numberToBeAdded = FromBaseToDecimal(auxNumber, this->base);

	if (numberToBeAdded > classNumberDecimal) {
		return 0;
	}

	classNumberDecimal -= numberToBeAdded;

	char* convertedNumber = FromDecimalToBase(this->base, classNumberDecimal);

	strcpy(this->number, convertedNumber);
	delete[] convertedNumber;

	return this->number;
}

Number& Number::operator--() {
	strcpy(this->number, this->number + 1);

	return *(this);
}

Number Number::operator--(int) {
	int sizeOfNumber = strlen(number);

	strncpy(this->number, this->number, sizeOfNumber - 1);
	this->number[sizeOfNumber - 1] = '\0';

	return *(this);
}

Number operator+(Number firstNumber, Number secondNumber) {
	int maxBase =
		firstNumber.base > secondNumber.base ? firstNumber.base : secondNumber.base;
	long long firstNumberDecimal =
		Number::FromBaseToDecimal(firstNumber.number, firstNumber.base);

	long long secondNumberDecimal =
		Number::FromBaseToDecimal((char*)secondNumber.number, secondNumber.base);

	long long sum = firstNumberDecimal + secondNumberDecimal;

	char* convertedNumber = Number::FromDecimalToBase(maxBase, sum);

	struct AnswerReturn {
		char* number;
		AnswerReturn(char* c) {
			number = new char[200];
			strcpy(number, c);
		}
		~AnswerReturn() { 
			delete[] number; 
		}
	}ans(convertedNumber);

	delete[] convertedNumber;

	return std::move(Number(ans.number, maxBase));
}

Number operator-(Number firstNumber, Number secondNumber) {
	int maxBase =
		firstNumber.base > secondNumber.base ? firstNumber.base : secondNumber.base;
	long long firstNumberDecimal =
		Number::FromBaseToDecimal(firstNumber.number, firstNumber.base);

	long long secondNumberDecimal =
		Number::FromBaseToDecimal((char*)secondNumber.number, secondNumber.base);

	long long diff = firstNumberDecimal > secondNumberDecimal ?
		firstNumberDecimal - secondNumberDecimal : secondNumberDecimal - firstNumberDecimal;
	char* convertedNumber = Number::FromDecimalToBase(maxBase, diff);

	struct AnswerReturn {
		char* number;
		AnswerReturn(char* c) {
			number = new char[200];
			strcpy(number, c);
		}
		~AnswerReturn() { delete[] number; }
	}ans(convertedNumber);

	delete[] convertedNumber;

	return std::move(Number(ans.number, maxBase));
}

#pragma endregion

#pragma region Comparassion operators

char Number::operator[] (int index) {
	if (index >= this->GetDigitsCount()) {
		return '?';
	}

	return this->number[index];
}

bool operator < (const Number& firstNumber, const Number& secondNumber) {
	long long firstNumberDecimal =
		Number::FromBaseToDecimal((char*)firstNumber.number, firstNumber.base);

	long long secondNumberDecimal =
		Number::FromBaseToDecimal((char*)secondNumber.number, secondNumber.base);

	return firstNumberDecimal < secondNumberDecimal;
}

bool operator > (const Number& firstNumber, const Number& secondNumber) {
	long long firstNumberDecimal =
		Number::FromBaseToDecimal((char*)firstNumber.number, firstNumber.base);

	long long secondNumberDecimal =
		Number::FromBaseToDecimal((char*)secondNumber.number, secondNumber.base);

	return secondNumberDecimal < firstNumberDecimal;
}

bool operator >= (const Number& firstNumber, const Number& secondNumber) {
	long long firstNumberDecimal =
		Number::FromBaseToDecimal((char*)firstNumber.number, firstNumber.base);

	long long secondNumberDecimal =
		Number::FromBaseToDecimal((char*)secondNumber.number, secondNumber.base);

	return !(firstNumberDecimal < secondNumberDecimal);
}

bool operator <= (const Number& firstNumber, const Number& secondNumber) {
	long long firstNumberDecimal =
		Number::FromBaseToDecimal((char*)firstNumber.number, firstNumber.base);

	long long secondNumberDecimal =
		Number::FromBaseToDecimal((char*)secondNumber.number, secondNumber.base);

	return !(firstNumberDecimal < secondNumberDecimal);
}

bool operator==(const Number& firstNumber, const Number& secondNumber) {
	long long firstNumberDecimal =
		Number::FromBaseToDecimal((char*)firstNumber.number, firstNumber.base);

	long long secondNumberDecimal =
		Number::FromBaseToDecimal((char*)secondNumber.number, secondNumber.base);

	return firstNumberDecimal == secondNumberDecimal;
}

bool operator!=(const Number& firstNumber, const Number& secondNumber) {
	long long firstNumberDecimal =
		Number::FromBaseToDecimal((char*)firstNumber.number, firstNumber.base);

	long long secondNumberDecimal =
		Number::FromBaseToDecimal((char*)secondNumber.number, secondNumber.base);

	return firstNumberDecimal != secondNumberDecimal;
}

#pragma endregion

#pragma region Equal Assign operators

Number Number::operator+=(int number) {
	long long initialNumberDecimal = FromBaseToDecimal(this->number, this->base);
	initialNumberDecimal += number;
	char* ans = FromDecimalToBase(this->base, initialNumberDecimal);

	strcpy(this->number, ans);

	delete[] ans;

	return *(this);
}

Number Number::operator+=(char* number) {
	long long initialNumberDecimal = FromBaseToDecimal(this->number, this->base);
	long long addedNumberDecimal = FromBaseToDecimal(number, this->base);

	initialNumberDecimal += addedNumberDecimal;
	char* ans = FromDecimalToBase(this->base, initialNumberDecimal);

	strcpy(this->number, ans);

	delete[] ans;

	return *(this);
}

Number Number::operator+=(const char* number) {
	long long initialNumberDecimal = FromBaseToDecimal(this->number, this->base);
	long long addedNumberDecimal = FromBaseToDecimal((char*)number, this->base);

	initialNumberDecimal += addedNumberDecimal;
	char* ans = FromDecimalToBase(this->base, initialNumberDecimal);

	strcpy(this->number, ans);

	delete[] ans;

	return *(this);
}

Number Number::operator+=(Number num) {
	long long initialNumberDecimal = FromBaseToDecimal(this->number, this->base);
	long long addedNumberDecimal = FromBaseToDecimal(num.number, this->base);

	initialNumberDecimal += addedNumberDecimal;
	char* ans = FromDecimalToBase(this->base, initialNumberDecimal);

	strcpy(this->number, ans);

	delete[] ans;

	return *(this);
}


Number Number::operator-=(int number) {
	long long initialNumberDecimal = FromBaseToDecimal(this->number, this->base);

	if (initialNumberDecimal < number) {
		strcpy(this->number, "0");
		return *(this);
	}

	initialNumberDecimal -= number;
	char* ans = FromDecimalToBase(this->base, initialNumberDecimal);

	strcpy(this->number, ans);

	delete[] ans;

	return *(this);
}

Number Number::operator-=(char* number) {
	long long initialNumberDecimal = FromBaseToDecimal(this->number, this->base);
	long long subNumberDecimal = FromBaseToDecimal(number, this->base);

	if (initialNumberDecimal < subNumberDecimal) {
		strcpy(this->number, "0");
		return *(this);
	}

	initialNumberDecimal -= subNumberDecimal;
	char* ans = FromDecimalToBase(this->base, initialNumberDecimal);

	strcpy(this->number, ans);

	delete[] ans;

	return *(this);
}

Number Number::operator-=(const char* number) {
	long long initialNumberDecimal = FromBaseToDecimal(this->number, this->base);
	long long subNumberDecimal = FromBaseToDecimal((char*)number, this->base);

	if (initialNumberDecimal < subNumberDecimal) {
		strcpy(this->number, "0");
		return *(this);
	}

	initialNumberDecimal -= subNumberDecimal;
	char* ans = FromDecimalToBase(this->base, initialNumberDecimal);

	strcpy(this->number, ans);

	delete[] ans;

	return *(this);
}

Number Number::operator-=(Number num) {
	long long initialNumberDecimal = FromBaseToDecimal(this->number, this->base);
	long long subNumberDecimal = FromBaseToDecimal(num.number, this->base);

	if (initialNumberDecimal < subNumberDecimal) {
		strcpy(this->number, "0");
		return *(this);
	}

	initialNumberDecimal -= subNumberDecimal;
	char* ans = FromDecimalToBase(this->base, initialNumberDecimal);

	strcpy(this->number, ans);

	delete[] ans;

	return *(this);
}

#pragma endregion

#pragma region Utility methods

int Number::GetValueFromChar(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

long long Number::FromBaseToDecimal(char* str, int base)
{
	int len = strlen(str);
	int power = 1;
	long long num = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		num += GetValueFromChar(str[i]) * power;
		power = power * base;
	}

	return num;
}

char Number::GetCharFromValue(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

void Number::ReverseString(char* str)
{
	int len = strlen(str);
	int i;
	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

char* Number::FromDecimalToBase(int base, long long inputNum)
{
	int index = 0;
	char* ans = new char[200];

	while (inputNum > 0 && index < 200)
	{
		ans[index++] = GetCharFromValue(inputNum % base);
		inputNum /= base;
	}
	ans[index] = '\0';

	ReverseString(ans);

	return ans;
}

#pragma endregion
