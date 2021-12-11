#include <stdio.h>

unsigned int positive(int x)
{
	x = (x >= 0) ? x : -x;
	return x;
}

int main()
{
	int x;
	scanf("%d", &x);
	printf("%d", positive(x));
}
