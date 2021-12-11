#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, x, count;
	
	scanf("%d", &n);
	
	count = 0;
	
	for (i=0; i < n; i++)
	{
		scanf("%d", &x);
		if (x % 2 == 0)
			count ++;
	}
	
	printf("%d", count);
	return 0;
}
