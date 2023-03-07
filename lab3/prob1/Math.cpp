#include "Math.h"
#pragma warning(disable : 4996)
#include <cstdarg>
#include <cstring>

int Math::Add(int a, int b) {
	return a + b;
}

int Math::Add(int a, int b, int c) {
	return a + b + c;
}

int Math::Add(double a, double b) {
	return a + b;
}

int Math::Add(double a, double b, double c) {
	return a + b + c;
}

int Math::Mul(int a, int b) {
	return a * b;
}

int Math::Mul(int a, int b, int c) {
	return a * b * c;
}

int Math::Mul(double a, double b) {
	return a * b;
}

int Math::Mul(double a, double b, double c) {
	return a * b * c;
}

int Math::Add(int count, ...) {
	va_list args;
	va_start(args, count);

	int sum = 0;

	while (count != 0) {
		int item = va_arg(args, int);
		sum += item;
		count--;
	}

	va_end(args);

	return sum;
}

char* Math::Add(const char* s1, const char* s2) {
	if(!s1 || !s2) {
		return nullptr;
	}
	
	const int size1 = strlen(s1), size2 = strlen(s2);
	int index1 = size1 - 1, index2 = size2 -1;
	bool carry = false;
	int sum = 0, contor = ((size1 > size2) ? size1 : size2) + 1;
	char* ans = strdup("");
	*(ans + contor + 1) = '\0';

	while (index1 >= 0 && index2 >= 0) {
		int digit1 = s1[index1] - '0', digit2 = s2[index2] - '0';
		bool isDigit1 = isDigit(digit1);
		bool isDigit2 = isDigit(digit2);

		if (!isDigit1 || !isDigit2) {
			throw "Input is invalid. One of the strings is not a number";
		}

		int sumOfDigits = digit1 + digit2 + carry;
		carry = false;

		if (sumOfDigits > 9) {
			carry = true;
			sumOfDigits %= 10;
		}

		*(ans + contor) = sumOfDigits + '0';
		contor--;

		index1--;
		index2--;
	}

	while (index1 >= 0) {
		int digit = s1[index1] - '0';
		bool isNumber = isDigit(digit);

		if (!isNumber) {
			throw "Input is invalid. One of the strings is not a number";
		}

		*(ans + contor) = digit + '0';
		contor--;

		index1--;
	}

	while (index2 >= 0) {
		int digit = s2[index2] - '0';
		bool isNumber = isDigit(digit);

		if (!isNumber) {
			throw "Input is invalid. One of the strings is not a number";
		}

		*(ans + contor) = digit + '0';
		contor--;

		index2--;
	}

	if (carry) {
		*(ans + contor) = '1';
		ans++;
	}
	else {
		ans += 2;
	}

	return ans;
}

bool Math::isDigit(int c) {
	return 0 <= c && c <= 9;
}