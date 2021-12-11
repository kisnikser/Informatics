#include <stdio.h>

int main()
{
	int y, x, sum = 0;
	int a[3][3];
	
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			scanf("%d", & a[y][x]);
		}
	}
	
	for (x = 0; x < 3; x++)
	{
		sum += a[1][x];
	}
	
	printf("%d", sum);
	
	return 0;
}
