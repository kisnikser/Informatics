#include <stdio.h>

int main()
{
	int N, x, y, bcount = 0;
	
	char square[100][100];
	
	scanf("%d", &N);
	
	for (y = 0; y <= N; y++)
	{
		for (x = 0; x < N; x++)
		{
			scanf("%c", &square[y][x]);
			
			if (square[y][x] == 42)
				bcount++;
		}
	}

	printf("%d", bcount);

	return 0;
}
