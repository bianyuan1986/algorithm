#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pos[128] = {0};
int mask = 0;
int pLen = 0;

void preprocess(char *pattern, int len)
{
	int i = 0;
	char c = 0;

	mask = 1 << (len-1);
	pLen = len;
	for( ; i < len; i++)
	{
		c = pattern[i];
		pos[c] |= (1<<i);
	}
}

void search(char *target)
{
	int i = 0;
	int D = 0;

	while( target[i] != '\0' )
	{
		D = ( D<<1 | 1 ) & pos[target[i]];
		if( D & mask )
		{
			printf("Find pos:%d\n", i-pLen+1);
		}
		i++;
	}
}

void dumpPos()
{
	int i = 0;
	int j = 0;
	int tmp = 0;

	for( ; i < 128; i++)
	{
		if( pos[i] == 0 )
		{
			continue;
		}
		tmp = pos[i];
		printf("%c:", i);
		for(j = 0; j < 32; j++)
		{
			printf("%d ", tmp%2);
			tmp = tmp/2;
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	preprocess(argv[2], strlen(argv[2]));
	dumpPos();
	search(argv[1]);

	return 0;
}

