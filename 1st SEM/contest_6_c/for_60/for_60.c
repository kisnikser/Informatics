#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, d, count = 0;
	
	scanf("%d%d", &d, &n);
	
	while (n > 0)
	{
		if (d == n % 10)
			count ++;
		n /= 10;
	}
	
	printf("%d", count);
	
	return 0;
}
