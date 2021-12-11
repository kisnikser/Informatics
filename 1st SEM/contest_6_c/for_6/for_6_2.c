#include <stdio.h>
#include <string.h>

int main()
{
	int i, n, count = 0;
	char word[10000];
	
	scanf("%d%s", &n, word);
	
	for (i = 0; i < strlen(word); i++)
	{
		if (word[i] == n + 48)
			count++;
	}
		
	printf("%d", count);
	
	return 0;
}
