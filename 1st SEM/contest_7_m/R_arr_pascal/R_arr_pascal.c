#include <stdio.h>

int factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int C(int n, int k)
{
	return factorial(n)/(factorial(k) * factorial(n - k));
}

int main()
{
	int x, y;	
	int Pascal[15][31] = {0};
	
	Pascal[0][15] = 1;
	
	for (y = 1; y < 15; y++)
	{
		for (x = 1; x < 30; x++)
		{
			Pascal[y][x] = Pascal[y-1][x-1] + Pascal[y-1][x+1];
		}
	}
	
	int N;
	
	scanf("%d", &N);
	
	for (x = 0; x < 31; x++)
	{
		if (Pascal[N][x] != 0)
			printf("%d ", Pascal[N][x]);
	}
	
	/*
	for (y = 0; y < 15; y++)
	{
		for (x = 1; x < 30; x++)
		{
			printf("%d ", Pascal[y][x]);
		}
		
		printf("\n");
	}
	*/
	return 0;
}
