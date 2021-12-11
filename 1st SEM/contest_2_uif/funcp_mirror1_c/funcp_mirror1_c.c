#include <stdio.h>

void mirror(int* x1, int* y1)
{
	*x1 = -*x1;
}

int main()
{
	int x1, y1;
	scanf("%d%d", &x1, &y1);
	mirror(&x1, &y1);
	printf("%d %d", x1, y1);
}
