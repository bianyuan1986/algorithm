#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BADCHAR_TABLE_SIZE 128

void badCharacter(char *pattern, int len, int *badChar)
{
	int i = 0;
	char c = 0;

	for( i = 0; i < BADCHAR_TABLE_SIZE; i++)
	{
		badChar[i] = -1;
	}

	for( i = len-1; i >= 0; i--)
	{
		c = pattern[i];
		badChar[c] = i;
	}
}

void goodSuffix(char *pattern, int len, int *goodSuf)
{
}

void search()
{
}

int main(int argc, char *argv[])
{
	return 0;
}

