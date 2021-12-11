#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char * stringtolower(char * s)
{
	for (int i = 0; i < strlen(s); i++)
		s[i] = tolower(s[i]);
	return s;
}

int main()
{
	int count = 0;
	const char* bomb = "bomb\0";
	char* text = calloc(10000000, sizeof(char));
	
	while (scanf("%s", text) != EOF)
	{
		stringtolower(text);
		if (strstr(text, bomb))
			count++;
	}
	
	if (count)
		printf("YES");
	else
		printf("NO");
	
	free(text);
	
	return 0;
}
