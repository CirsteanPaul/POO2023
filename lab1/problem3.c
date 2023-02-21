#include <stdio.h>
#include <stdlib.h>  
#include <cstring>
#include <algorithm>
#pragma warning(disable : 4996)

// Read a sentence from the input using scanf API. 
// Then sort split it into words and write to the screen (using the printf API) the words sorted (from the longest one to the shortest one).If two words have the same length - they will be sorted out alphabetically. 
// We consider that each word is separated from another one using space (one or multiple).

int compareStrings(const char* a, const char* b) {
	if (strlen(a) < strlen(b)) {
		return 1;
	}
	if (strlen(a) > strlen(b)) {
		return -1;
	}
	int result = strcmp(a, b);
	if (result > 0)
		return -1;
	return 1;
}

int main()
{
	char str[256];
	scanf("%99[^\n]", str);

	char words[20][40];
	int line = 0, col = 0;

	for (int i = 0; i < strlen(str); i++) {
		char chr = str[i];
		if (chr == ' ') {
			words[line][col++] = '\0';
			line++;
			col = 0;
		}
		else {
			words[line][col++] = chr;
		}
	}
	words[line++][col++] = '\0';
	for (int i = 0; i < line; i++) {
		for (int j = i + 1;j < line; j++)
		{
			int result = compareStrings(words[i], words[j]);
			if (result > 0) {
				char aux[40];
				strcpy(aux, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], aux);
			}
		}
	}

	for (int i = 0; i < line; i ++) {
		if (words[i][0] != '\0') {
			printf("%s\n", words[i]);
		}
	}
}
