#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, i, mod, div, kupec = 0, flag = 0;
	
	scanf("%d", &N);
	
	int* a = (int*)calloc(N, sizeof(int));
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", a + i);
	}
	
	while (flag == 0)
	{
		flag = 1;
	    
		for (i = 0; i < N - 1; i++)
		{
			mod = (a[i] + a[i+1]) % 2;
			div = (a[i] + a[i+1]) / 2;
			kupec += mod;
			a[i] = div;
			a[i+1] = div;
		}
		
		int mod = (a[0] + a[N-1]) % 2;
		int div = (a[0] + a[N-1]) / 2;
		kupec += mod;
		a[0] = div;
		a[N-1] = div;
		
		for (i = 0; i < N - 1; i++)
		{
			if (a[i] != a[i+1])
				flag = 0;
		}
	}
	
	printf("%d %d", kupec, a[1]);
	
	free(a);
	
	return 0;
}
