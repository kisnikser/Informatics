#include <stdio.h>

int main()
{
	int a[10];
	int i, k, n;
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d", a + i);
	}
	
	for (i = 0; i < 10; i++)
	{
		if (a[i] >= 0)
			printf("%d ", a[i]);
	}
	
	return 0;
}
