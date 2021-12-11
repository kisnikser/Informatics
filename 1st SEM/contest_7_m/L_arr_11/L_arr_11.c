#include <stdio.h>

int main()
{
	int N, i, scalpr = 0;
	
	scanf("%d", &N);
	
	int a[1000], b[1000];
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", a + i);
	}
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", b + i);
	}
	
	for (i = 0; i < N; i++)
	{
		scalpr += a[i]*b[i];
	}
	
	printf("%d", scalpr);
	
	return 0;
}
