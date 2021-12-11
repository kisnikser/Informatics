#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_char(const void * p1, const void * p2)
{
	return *(char*)p1 - *(char*)p2;
}
int main()
{
	char* s = calloc(1000, sizeof(char));;
	fgets(s, 1000, stdin);
    char* point = strstr(s, ".");
    point[1] = '\0';
    qsort(s, point - s, sizeof(char), cmp_char);
	fputs(s, stdout);
    free(s);
    return 0;
}
