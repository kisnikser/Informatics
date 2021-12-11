#include <stdio.h>

int main()
{
	float x, y;
	float eps = 0.01;
	scanf("%f%f", &x, &y);
	(y >= -2 - eps && y <= x + 3 + eps && y <= -x + 3 + eps)? printf("YES") : printf("NO");
	return 0;
}
