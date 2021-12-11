#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long N, time, i;
	
	scanf("%lld", &N);
	
	time = 0;
	i = 2;
	
	while (N > 0)
	{
		time ++;
		N -= i/2;
		i ++;
	}
	
	printf("%lld", time);
	return 0;
}
