#include <stdio.h>

int max(int a, int b)
{
	int max = (a >= b) ? a : b;
	return max;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", max(a, b));
}
