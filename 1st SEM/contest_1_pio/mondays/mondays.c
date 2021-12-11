#include <stdio.h>

int main()
	{
	int N, nday, k;
	scanf("%d %d", &N, &nday);
	k = 1+(N-nday)/7;
	printf("%d", k);
	}
