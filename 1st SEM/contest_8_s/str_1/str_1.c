#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t my_strlen(const char *s)
{
	size_t i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}

int main()
{
	const char * s = "Hi\0";
	
	printf("%ld", my_strlen(s));
	
	return 0;
}
