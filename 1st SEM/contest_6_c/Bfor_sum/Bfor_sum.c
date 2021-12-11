#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, x, sum;
	
	scanf("%d", &n);
	
	sum = 0;
	
	for (i=0; i < n; i++)
	{
		scanf("%d", &x);
		sum += x;
	}
	
	printf("%d", sum);
	return 0;
}
