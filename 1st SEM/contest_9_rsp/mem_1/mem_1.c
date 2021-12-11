#include <stdio.h>
#include <stdlib.h>

char* my_strdup(const char *s)
{
	char* dup = calloc(strlen(s) + 1, sizeof(char));
	strcpy(dup, s);
	return dup;
}

int main()
{

}
