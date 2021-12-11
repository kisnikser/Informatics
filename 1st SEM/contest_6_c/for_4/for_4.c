#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, factorial = 1;
	
	scanf("%d", &n);
	
	for (i=2; i < n + 1; i++)
	{
		factorial *= i;
	}
	
	printf("%d", factorial);
	return 0;
}
