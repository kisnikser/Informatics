#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	float eps = 0.1;
	float a, b, v, t;
	scanf("%f%f%f%f", &a, &b, &v, &t);
	(fabs(a - v * t) <= eps || fabs(b - v * t) <= eps || (v * t > a && v * t < b))? printf("YES") : printf("NO");
	
	return 0;
}
