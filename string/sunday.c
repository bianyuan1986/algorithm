#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT_TABLE_SIZE 128

void preprocess(char *pattern, int len, int *shift)
{
	int i = 0;
	char c = 0;

	for( ; i < SHIFT_TABLE_SIZE; i++)
	{
		shift[i] = len + 1;
	}

	for( i = 0; i < len; i++)
	{
		c = pattern[i];
		shift[c] = len - i;
	}
}

void search(char *target, char *pattern, int pLen, int *shift)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	char c = 0;
	int max = 0;

	max = strlen(target);
	while( i + pLen <= max )
	{
		tmp = i;
		j = 0;
		while( (j < pLen) && (target[tmp] == pattern[j]) )
		{
			tmp++;
			j++;
		}
		if( j < pLen )
		{
			c = target[i+pLen];
			if( c == '\0' )
			{
				break;
			}
			i += shift[c];
			continue;
		}
		else
		{
			printf("Find at pos:%d\n", tmp-j);
			i = tmp-j+1;
			continue;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	int shift[SHIFT_TABLE_SIZE] = {0};

	preprocess(argv[2], strlen(argv[2]), shift);
	search(argv[1], argv[2], strlen(argv[2]), shift);

	return 0;
}

