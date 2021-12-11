#include <stdio.h>

int main()
{
	int N, x, y, sum, magic, flag = 0;
	
	int square[3][3];
	
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			scanf("%d", & square[y][x]);
		}
	}

	magic = square[0][0] + square[0][1] + square[0][2];

	for (y = 0; y < 3; y++)
	{
		sum = 0;
		
		for (x = 0; x < 3; x++)
		{
			sum += square[y][x];
		}
		
		if (sum != magic)
			flag = 1;
	}
	
	for (x = 0; x < 3; x++)
	{
		sum = 0;
		
		for (y = 0; y < 3; y++)
		{
			sum += square[y][x];
		}
		
		if (sum != magic)
			flag = 1;
	}
	
	sum = 0;
	
	for (x = 0; x < 3; x++)
	{
		sum += square[x][x];
	}
	
	if (sum != magic)
		flag = 1;
	
	sum = 0;
	
	for (x = 2; x >= 0; x--)
	{
		sum += square[2-x][x];
	}
	
	if (sum != magic)
		flag = 1;

	if (flag != 1)
		printf("MAGIC");

	return 0;
}
