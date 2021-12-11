#include <stdio.h>

int main()
{
	int N, i;
	
	scanf("%d", &N);
	
	int a[1000];
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", a + i);
	}
	
	for (i = 0; i < N; i++)
	{
		if (a[i] % 2 == 0)
			printf("%d ", a[i]);
	}
	
	printf("\n");
	
	for (i = 0; i < N; i++)
	{
		if (a[i] % 2 != 0)
			printf("%d ", a[i]);
	}
	
	return 0;
}
