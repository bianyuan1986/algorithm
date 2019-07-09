#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void brute_force(char *target, char *pattern)
{
	int i = 0;
	int j = 0;
	int pLen = 0;
	int tLen = 0;
	int max = 0;
	int tmp = 0;

	pLen = strlen(pattern);
	tLen = strlen(target);
	if( pLen > tLen )
	{
		return;
	}
	max = tLen - pLen + 1;

	while(i <= max)
	{
		tmp = i;
		while( (j < pLen) && (target[tmp] == pattern[j]) )
		{
			tmp++;
			j++;
		}

		if( j >= pLen )
		{
			printf("Find at pos:%d\n", tmp-pLen);
			break;
		}
		else
		{
			i++;
			j = 0;
		}
	}
}

int main(int argc, char *argv[])
{
	brute_force(argv[1], argv[2]);

	return 0;
}

