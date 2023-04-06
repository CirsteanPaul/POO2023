#pragma once
class Number
{
	int base = 10;
	char number[200];

	static int GetValueFromChar(char);
	static long long FromBaseToDecimal(char*, int);
	static char GetCharFromValue(int);
	static void ReverseString(char*);
	static char* FromDecimalToBase(int, long long);

public:
	Number(char* s, int base = 10);
	Number(const char*, int base = 10);
	Number(int, int base = 10);
	Number(const Number&);
	Number(Number&&) noexcept;

	char operator[] (int);
	Number operator=(int);
	Number operator=(char*);
	Number operator=(const char*);
	Number operator=(Number);

	Number operator+=(int);
	Number operator+=(char*);
	Number operator+=(const char*);
	Number operator+=(Number);

	Number operator-=(int);
	Number operator-=(char*);
	Number operator-=(const char*);
	Number operator-=(Number);

	Number operator+(int);
	Number operator+(char*);
	Number operator+(const char*);
	friend Number operator+(Number, Number);

	Number operator-(int);
	Number operator-(char*);
	Number operator-(const char*);
	friend Number operator-(Number, Number);
	Number& operator--();
	Number operator--(int);

	friend bool operator<(const Number&, const Number&);
	friend bool operator<=(const Number&, const Number&);
	friend bool operator>(const Number&, const Number&);
	friend bool operator>=(const Number&, const Number&);
	friend bool operator==(const Number&, const Number&);
	friend bool operator!=(const Number&, const Number&);


	void SwitchBase(int);
	void Print();
	int GetDigitsCount();
	int GetBase();

	~Number() = default;
};

