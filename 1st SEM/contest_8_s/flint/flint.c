#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int coord;
	int x = 0;
	int y = 0;
	char* map = calloc(10, sizeof(char));
	const char* N = "North\0";
	const char* S = "South\0";
	const char* E = "East\0";
	const char* W = "West\0";
	const char* T = "Treasure!\0";
	
	while (strstr(map, T) == 0)
	{
		scanf("%s", map);
		if (strstr(map, T) == 0)
			scanf("%d", &coord);
		if (strstr(map, N))
			y += coord;
		if (strstr(map, S))
			y -= coord;
		if (strstr(map, E))
			x += coord;
		if (strstr(map, W))
			x -= coord;
	}
	
	printf("%d %d", x, y);
	
	free(map);
	
	return 0;
}
