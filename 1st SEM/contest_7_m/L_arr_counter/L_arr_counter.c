#include <stdio.h>

int main()
{
	int N, i;
	
	scanf("%d", &N);
	
	int a[1000], count[10];
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", a + i);
	}
	
	for (i = 0; i < 10; i++)
	{
		count[i] = 0;
	}
	
	for (i = 0; i < N; i++)
	{
		count[a[i]]++;
	}
	
	for (i = 0; i < 10; i++)
	{
		printf("%d %d\n", i, count[i]);
	}
	
	return 0;
}
