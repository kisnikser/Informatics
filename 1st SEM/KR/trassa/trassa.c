#include <stdio.h>

int main()
{
	long long N, L, i, k;
	
	scanf("%lld", &N);
	
	L = 0;
	i = 3;
	k = -1;
	
	while (N > 0)
	{
		N -= i;
		i += 2;
		k++;
	}
	
	while (k > 0)
	{
		L += k;
		k--;
	}
	
	printf("%lld", L);
	return 0;
}
