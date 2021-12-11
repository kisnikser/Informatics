#include <stdio.h>

int main()
	{
	int N, n;
	scanf("%d", &N);
	n = 100*N/106;
	printf("%d %d", n, (N-n)*100-6*n);
	}
