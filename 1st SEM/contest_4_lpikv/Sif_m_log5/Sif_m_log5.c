#include <stdio.h>

int main()
{
	int z;
	scanf("%d", &z);
	if (z < 10) 
		printf("0");
	if (z >= 10 && z < 13) 
		printf("3");
	if (z >= 13 && z < 16) 
		printf("5");
	if (z >= 16) 
		printf("10");
	return 0;
}
