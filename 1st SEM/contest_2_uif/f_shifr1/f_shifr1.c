#include <stdio.h>

void deCode(unsigned int kodeNumber, char *l1, char *l2, char *l3, char *l4)
{
	*l1 = kodeNumber / 1000000; 
	*l2 = ( kodeNumber / 10000 ) % 100;
	*l3 = ( kodeNumber / 100 ) % 100;
	*l4 = kodeNumber % 100;
	*l1 += 'A' - 1;
	*l2 += 'A' - 1;
	*l3 += 'A' - 1;
	*l4 += 'A' - 1;
}

int main()
{
	unsigned int kodeNumber;
	char l1, l2, l3, l4;
	scanf("%u", &kodeNumber);
	l1 = kodeNumber / 1000000; 
	l2 = ( kodeNumber / 10000 ) % 100;
	l3 = ( kodeNumber / 100 ) % 100;
	l4 = kodeNumber % 100;
	deCode(kodeNumber, &l1, &l2, &l3, &l4);
	kodeNumber = l1 * 1000 + l2 * 100 + l3 * 10 + l4;	
	printf("%u", kodeNumber);
}
