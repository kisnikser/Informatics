#include <stdio.h>

int main()
{
	unsigned char code, n1, n2, n3, n4;
	scanf("%2hhu%2hhu%2hhu%2hhu", &n1, &n2, &n3, &n4);
	n1 = n1 - 1 + 'A';
	n2 = n2 - 1 + 'A';
	n3 = n3 - 1 + 'A';
	n4 = n4 - 1 + 'A';
	printf("%c%c%c%c", n1, n2, n3, n4);
}

