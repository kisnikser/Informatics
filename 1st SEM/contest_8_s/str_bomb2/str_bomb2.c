#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int count = 0;
	const char* bomb = "bomb\0";
	char* text = calloc(10000000, sizeof(char));
	
	while (scanf("%s", text) != EOF)
		if (strstr(text, bomb))
			count++;
	
	if (count)
		printf("YES");
	else
		printf("NO");
	
	free(text);
	
	return 0;
}
