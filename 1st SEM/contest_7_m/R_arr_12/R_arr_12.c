#include <stdio.h>

int main()
{
	int X, i;
	
	int coin[9] = {0};
	
	coin[0] = 5000;
	coin[1] = 1000;
	coin[2] = 500;
	coin[3] = 100;
	coin[4] = 50;
	coin[5] = 10;
	coin[6] = 5;
	coin[7] = 2;
	coin[8] = 1;	
	
	int count[9] = {0};
	
	scanf("%d", &X);
	
	for (i = 0; i < 9; i++)
	{
		while (X >= coin[i])
		{
			count[i]++;
			X -= coin[i];
		}
	}
	
	for (i = 0; i < 9; i++)
		printf("%d %d\n", coin[i], count[i]);
	
	return 0;
}
