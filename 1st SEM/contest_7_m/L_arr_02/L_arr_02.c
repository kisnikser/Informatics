#include <stdio.h>

int main()
{
	int N, i, n, flag = 0;
	
	scanf("%d", &N);
	
	int a[1000];
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", a + i);
	}
	
	scanf("%d", &n);
	
	i = 0;
	
	while (a[i] != n)
	{
		i++;
	}
	
	printf("%d", i);
	
	return 0;
}
