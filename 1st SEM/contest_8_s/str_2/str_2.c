#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcpy(char *dest, const char *src)
{
	memcpy(dest, src, (strlen(src) + 1) * sizeof(char));
	return dest;
}

int main()
{
	const char *src = "Hi\0";
	
	char* dest;
	
	printf("%ld", );
	
	return 0;
}
