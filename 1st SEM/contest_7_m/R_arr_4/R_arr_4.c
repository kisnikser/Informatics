#include <stdio.h>

int IsSimple(int n)
{
	int i, del = 1;
	
	for (i = 1; i < n; i++)
	{
		if (n % i == 0)
			del *= i;
	}
	
	if (del == 1)
		return 1;
	else
		return 0;
}

int main()
{
	int a[1000], N, i;
	
	scanf("%d", &N);
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", a + i);
	}
	
	for (i = 0; i < N; i++)
	{
		if (IsSimple(a[i]))
			printf("%d ", a[i]);
	}
	
	return 0;
}
