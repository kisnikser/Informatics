#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, tmp, count = 0, K = 0;
	
	scanf("%d", &N);
	
	tmp = N;
	
	while (tmp > 0)
	{
		K = K * 10 + tmp % 10;
		tmp /= 10;
	}
	
	if (K == N)
		printf("YES");
	else	
		printf("NO");

	return 0;
}
