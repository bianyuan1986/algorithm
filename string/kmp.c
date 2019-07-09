#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNext1(char *pattern, int len, int *next)
{
	int i = 0;
	int prev = 0;
	char c = 0;

	next[0] = -1;
	next[1] = 0;
	i = 2;
	while( i < len )
	{
		c = pattern[i];
		prev = next[i-1];
		while(prev >= 0)
		{
			if( pattern[prev] == pattern[i-1] )
			{
				prev += 1;
				break;
			}
			else
			{
				if( prev == 0 )
				{
					break;
				}
				prev = next[prev];
			}
		};
		next[i] = prev;
		i++;
	}
}

void getNext(char *pattern, int len, int *next)
{
	int j = 0;
	int k = -1;

	next[0] = -1;
	while( j < len )
	{
		if( (k == -1) || (pattern[k] == pattern[j]) )
		{
			k++;
			j++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

void getNextOptimal(char *pattern, int len, int *next)
{
	int j = 0;
	int k = -1;

	next[0] = -1;
	while( j < len )
	{
		if( (k == -1) || (pattern[k] == pattern[j]) )
		{
			k++;
			j++;
			if( pattern[j] == pattern[k] )
			{
				next[j] = next[k];
			}
			else
			{
				next[j] = k;
			}
		}
		else
		{
			k = next[k];
		}
	}
}

void dumpNext(int *next, int len)
{
	int i = 0;
	
	for( ; i < len; i++)
	{
		printf("%2d ", next[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int pLen = 0;
	int *next = NULL;

	pLen = strlen(argv[1]);
	next = (int*)malloc(pLen*sizeof(int));
	getNext(argv[1], pLen, next);
	dumpNext(next, pLen);
	getNext1(argv[1], pLen, next);
	dumpNext(next, pLen);
	getNextOptimal(argv[1], pLen, next);
	dumpNext(next, pLen);

	return 0;
}

