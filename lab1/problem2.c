#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)


// Write a program in C-Language that open the file "in.txt", and prints the sum of the numbers that are found on each line of the file in.txt. 
// To open the file use fopen API. Write your own function that converts a string to a number (similar cu atoi API). To print something to the screen, use the printf API.
int main()
{
	FILE* fp;
	int sum = 0;
	char s[100];

	fp = fopen("in.txt", "r");

	while (fgets(s, 100, fp) != NULL) {
		int number = atoi(s);
		sum += number;
	}

	fclose(fp);

	printf("%d", sum);
}
