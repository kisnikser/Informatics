#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float length(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2)*(x1 - x2)+(y1 - y2)*(y1 - y2));
}

float s3(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float a = length(x1, y1, x2, y2);
	float b = length(x2, y2, x3, y3);
	float c = length(x1, y1, x3, y3);
	float p = (a + b + c)/2;
	return sqrt(p*(p - a)*(p - b)*(p - c));	 
}

int main()
{
	int x1, y1, x2, y2, x3, y3;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	printf("%f", s3(x1, y1, x2, y2, x3, y3));
}
