#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* GetString()
{
	char buf[1000];
	char* p = 0;
	int size = 1000;
	p = (char*)calloc(size + 1, sizeof(char));
	bzero(p, sizeof(char) * (size + 1));
	
	while(fgets(buf, 1000, stdin) != NULL)
	{
		int len = strlen(buf);
		buf[len - 1] = '\0';
		if (len < size - strlen(p))
		{
			strcat(p, buf);
			continue;
		}
		size += 1000;
		p = realloc(p, size);
		strcat(p, buf);
	}
	return p;
}

int main()
{
	int N, x, y, S = 0, Smax = 0;
	
	scanf("%d", &N);
	
	char* square = GetString();

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
