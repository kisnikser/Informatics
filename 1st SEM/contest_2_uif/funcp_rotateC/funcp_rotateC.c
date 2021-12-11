#include <stdio.h>

void rotateC(int* x1, int* y1, int* x2, int* y2)
{
	int x0 = (*x1 + *x2)/2;
	int y0 = (*y1 + *y2)/2;
	int h = *y1 - *y2;
	int w = *x2 - *x1;
	*x1 = x0 - h/2;
	*y1 = y0 + w/2;
	*x2 = x0 + h/2;
	*y2 = y0 - w/2; 
}

int main()
{
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	rotateC(&x1, &y1, &x2, &y2);
	printf("%d %d %d %d", x1, y1, x2, y2);
}
