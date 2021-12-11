#include <stdio.h>

int rom(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n == 3)
		return 1;
	if (n == 4)
		return 1;
	if (n >= 5)
		return 2;
}

int main()
{
	int N;
	scanf("%d", &N);
	printf("%d", rom(N));
}
