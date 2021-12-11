#include <stdio.h>

unsigned int codeToNumber(char l1, char l2, char l3, char l4)
{
	unsigned int number;
	l1 = l1 + 1 - 'A';
	l2 = l2 + 1 - 'A';
	l3 = l3 + 1 - 'A';
	l4 = l4 + 1 - 'A';
	number = l1*1000000 + l2*10000 + l3*100 + l4;
	return number;
}

int main()
{
	char l1, l2, l3, l4;
	unsigned long long number; 
 	scanf("%c%c%c%c", &l1, &l2, &l3, &l4);
 	printf("%08u\n", codeToNumber(l1, l2, l3, l4));
}
