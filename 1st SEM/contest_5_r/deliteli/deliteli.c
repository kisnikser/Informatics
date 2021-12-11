#include <stdio.h>
#include <stdlib.h>

void simpleFactors(long long a, int last, int n)
{
	if (a == 1)
	{
		if (n == 1)
			printf("%d", last);
		if (n > 1)
			printf("%d^%d", last, n);	
	}
	else
	{
		if (a % last == 0)
			simpleFactors(a / last, last, n + 1);
		else
			{
			simpleFactors(a, last + 1, 0);
			if (n == 1)
				printf(" %d", last);
			if (n > 1)
				printf(" %d^%d", last, n);
			}
	}
}

int main()
{
	int a;
	scanf("%d", &a);
	simpleFactors(a, 2, 0);
	return 0;
}
