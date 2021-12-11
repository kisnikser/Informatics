#include <stdio.h>

int main()
	{
	unsigned char dozenNumber, n1, n0;
	scanf("%hhu", &dozenNumber);
	n1 = dozenNumber/12;
	n0 = dozenNumber%12;
	n1 = (n1/10)*(n1 + 'A' - 10) + !(n1/10)*(n1 + '0');
	n0 = (n0/10)*(n0 + 'A' - 10) + !(n0/10)*(n0 + '0'); 
	printf("%c%c", n1, n0);
	}
