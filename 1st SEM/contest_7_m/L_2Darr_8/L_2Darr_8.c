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
	
	for (i = 2; i >-1; i--)
	{
		sum += a[2-i][i];
	}
	
	printf("%d", sum);
	
	return 0;
}
