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
		printf("%d ", a[i]);
	}
	
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
