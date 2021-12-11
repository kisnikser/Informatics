#include <stdio.h>

int main()
{
	float x, y;
	float eps = 0.01;
	scanf("%f%f", &x, &y);
	(x >= -3 - eps && x <= 2 + eps && y <= 6 + eps && y >= -4 - eps)? printf("YES") : printf("NO");
	return 0;
}
