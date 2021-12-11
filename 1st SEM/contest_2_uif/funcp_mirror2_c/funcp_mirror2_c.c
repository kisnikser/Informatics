#include <stdio.h>

void mirror(int* x1, int* y1, int* x2, int* y2)
{
	*y1 = -*y1;
	*y2 = -*y2;
}

int main()
{
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	mirror(&x1, &y1, &x2, &y2);
	printf("%d %d %d %d", x1, y1, x2, y2);
}
