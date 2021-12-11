#include <stdio.h>

int main()
{
	int y, x, i, sum = 0;
	int a[3][3];
	
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			scanf("%d", & a[y][x]);
		}
	}
	
	for (i = 0; i < 3; i++)
	{
		sum += a[i][i];
	}
	
	printf("%d", sum);
	
	return 0;
}
