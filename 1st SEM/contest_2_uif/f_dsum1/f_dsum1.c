#include <stdio.h>

void printOddEvent(unsigned int number)
{
	unsigned int s1 = 0;
	unsigned int s2 = 0;
	number /= 2;
	s2 += number%10;
	number /= 10;
	s1 += number%10;
	number /= 10;
	s2 += number%10;
	number /= 10;
	s1 += number%10;
	number /= 10;
	s2 += number%10;
	number /= 10;
	s1 += number%10;
	number /= 10;
	s2 += number%10;
	number /= 10;
	s1 += number%10;
	printf("%u %u", s2, s1);
}

int main()
{
	unsigned int number;
	scanf("%u", &number);
	printOddEvent(number);
}
