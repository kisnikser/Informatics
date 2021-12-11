#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, x, y, S = 0, Smax = 0;
	
	scanf("%d", &N);
	
	char* square = calloc(N * (N + 1), sizeof(char));
	
	for (y = 0; y < N; y++)
	{
		for (x = 0; x <= N; x++)
		{
			scanf("%s", square + y * N + x);
		}
	}
	
	for (y = 0; y < N; y++)
	{
		for (x = 0; x < N; x++)
		{
			if (square[y * N + x] == 42)
			{
				S++;
				if (S > Smax)
					Smax = S;
			}
			else
				S = 0;
		}
	}
	
	printf("%d", Smax);
	
	free(square);
	
	return 0;
}
