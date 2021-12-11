#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long n, count = 0;
	int d;
	
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
