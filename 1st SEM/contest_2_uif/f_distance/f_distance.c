#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float getDistance(int x1, int y1, int x2, int y2)
{
	float dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return dist;
}

int main()
{
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	printf("%0.2f", getDistance(x1, y1, x2, y2));
}
