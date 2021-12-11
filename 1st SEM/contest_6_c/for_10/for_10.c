#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, c;
	
	scanf("%d", &N);
	
	while (N % 10 == 0)
		N /= 10;
	
	while (N > 0)
	{
		c = N % 10;
		printf("%d", c);
		N /= 10;
	}
	
	return 0;
}
