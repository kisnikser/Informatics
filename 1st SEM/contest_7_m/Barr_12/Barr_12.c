#include <stdio.h>

int main()
{
	int a[10];
	int i, k, n, sum=0;
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d", a + i);
	}
	
	scanf("%d%d", &k, &n);
	
	for (i = k; i < n; i++)
	{
		sum += a[i];
	}
	
	printf("%d", sum);
	
	return 0;
}
