#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, k = 2;
	
	scanf("%d", &N);
	
	while (N > 1)
	{
		if (N % k == 0)
		{
			N /= k;
			printf("%d ", k);
		}
		else
			k++;
	}
		
	return 0;
}
