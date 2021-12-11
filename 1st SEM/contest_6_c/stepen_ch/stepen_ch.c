#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int N, Nconst, k, i = 2, del = 1, flag = 0;
	
	scanf("%d%d", &N, &k);
	
	Nconst = N;
	
	while (i < N)
	{
		if (N % (int)(pow(i, k)) == 0)
		{
			N /= (int)(pow(i, k));
			printf("%d %d\n", i, N);
			del *= i;
		}
		else
			i++;
		
		if (N == 1)
		{
			printf("%d", del);
		}
	}
	
	if (Nconst != (int)(pow(del, k)))
		printf("%d", -1);
		
	return 0;
}
