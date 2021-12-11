#include <stdio.h>

int main()
{
	unsigned char n1, n2, n3, n4;
	scanf("%c%c%c%c", &n1, &n2, &n3, &n4);
	n1 = n1 + 1 - 'A';
	n2 = n2 + 1 - 'A';
	n3 = n3 + 1 - 'A';
	n4 = n4 + 1 - 'A';
	printf("%02hhu%02hhu%02hhu%02hhu", n1, n2, n3, n4);
}

