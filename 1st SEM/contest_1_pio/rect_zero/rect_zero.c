#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
	{
	float x1, y1, x2, y2, xn1, yn1, xn2, yn2, x0, y0;
	scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
	x0 = (x1 + x2)/2;
	y0 = (y1 + y2)/2;
	xn1 = x1 - x0;
	xn2 = x2 - x0;
	yn1 = y1 - y0;
	yn2 = y2 - y0;
	printf("%0.2f %0.2f %0.2f %0.2f", xn1, yn1, xn2, yn2);
	}
