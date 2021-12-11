#include <stdio.h>

int main()
{
	int x, y, flag = 0;
	
	int square[9][9];
	
	int count[10] = {0};
	
	for (y = 0; y < 9; y++)
	{
		for (x = 0; x < 9; x++)
		{
			scanf("%d", & square[y][x]);
		}
	}
	
	for (y = 0; y < 9; y++) // Проверяем по строкам
	{
		for (x = 1; x < 10; x++)
		{
			count[x] = 0;
		}
		
		for (x = 0; x < 9; x++)
		{
			count[square[y][x]]++;
		}
		
		for (x = 1; x < 10; x++)
		{
			if (count[x] > 1)
				flag = 1;
		}
	}
	
	for (x = 0; x < 9; x++) // Проверяем по столбцам
	{
		for (y = 1; y < 10; y++)
		{
			count[y] = 0;
		}
		
		for (y = 0; y < 9; y++)
		{
			count[square[y][x]]++;
		}
		
		for (y = 1; y < 10; y++)
		{
			if (count[y] > 1)
				flag = 1;
		}
	}
	
	// Проверяем по квадратам 3х3
	
	// *00
	// 000
	// 000
	
	for (x = 1; x < 10; x++)
	{
		count[x] = 0;
	}
	
	for (y = 0; y < 3; y++)
	{	
		for (x = 0; x < 3; x++)
		{
			count[square[y][x]]++;
		}
	}
	
	for (x = 1; x < 10; x++)
	{
		if (count[y] > 1)
			flag = 1;
	}
			
	// 0*0
	// 000
	// 000
	
	for (x = 1; x < 10; x++)
	{
		count[x] = 0;
	}
	
	for (y = 0; y < 3; y++)
	{	
		for (x = 3; x < 6; x++)
		{
			count[square[y][x]]++;
		}
	}
	
	for (x = 1; x < 10; x++)
	{
		if (count[y] > 1)
			flag = 1;
	}
			
	// 00*
	// 000
	// 000
	
	for (x = 1; x < 10; x++)
	{
		count[x] = 0;
	}
	
	for (y = 0; y < 3; y++)
	{	
		for (x = 6; x < 9; x++)
		{
			count[square[y][x]]++;
		}
	}
	
	for (x = 1; x < 10; x++)
	{
		if (count[y] > 1)
			flag = 1;
	}
			
	// 000
	// *00
	// 000
	
	for (x = 1; x < 10; x++)
	{
		count[x] = 0;
	}
	
	for (y = 3; y < 6; y++)
	{	
		for (x = 0; x < 3; x++)
		{
			count[square[y][x]]++;
		}
	}
	
	for (x = 1; x < 10; x++)
	{
		if (count[y] > 1)
			flag = 1;
	}
			
	// 000
	// 0*0
	// 000
	
	for (x = 1; x < 10; x++)
	{
		count[x] = 0;
	}
	
	for (y = 3; y < 6; y++)
	{	
		for (x = 3; x < 6; x++)
		{
			count[square[y][x]]++;
		}
	}
	
	for (x = 1; x < 10; x++)
	{
		if (count[y] > 1)
			flag = 1;
	}
			
	// 000
	// 00*
	// 000
	
	for (x = 1; x < 10; x++)
	{
		count[x] = 0;
	}
	
	for (y = 3; y < 6; y++)
	{	
		for (x = 6; x < 9; x++)
		{
			count[square[y][x]]++;
		}
	}
	
	for (x = 1; x < 10; x++)
	{
		if (count[y] > 1)
			flag = 1;
	}
			
	// 000
	// 000
	// *00
	
	for (x = 1; x < 10; x++)
	{
		count[x] = 0;
	}
	
	for (y = 6; y < 9; y++)
	{	
		for (x = 0; x < 3; x++)
		{
			count[square[y][x]]++;
		}
	}
	
	for (x = 1; x < 10; x++)
	{
		if (count[y] > 1)
			flag = 1;
	}
			
	// 000
	// 000
	// 0*0
	
	for (x = 1; x < 10; x++)
	{
		count[x] = 0;
	}
	
	for (y = 6; y < 9; y++)
	{	
		for (x = 3; x < 6; x++)
		{
			count[square[y][x]]++;
		}
	}
	
	for (x = 1; x < 10; x++)
	{
		if (count[y] > 1)
			flag = 1;
	}
			
	// 000
	// 000
	// 00*
	
	for (x = 1; x < 10; x++)
	{
		count[x] = 0;
	}
	
	for (y = 6; y < 9; y++)
	{	
		for (x = 6; x < 9; x++)
		{
			count[square[y][x]]++;
		}
	}
	
	for (x = 1; x < 10; x++)
	{
		if (count[y] > 1)
			flag = 1;
	}
	
	if (flag == 0)
		printf("YES");
	else
		printf("NO");

	return 0;
}
