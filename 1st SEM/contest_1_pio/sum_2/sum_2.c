#include <stdio.h>

int main()
{
	int N, K, age, sr;
	sr = N > K;
	scanf("%d %d", &N, &K);
	age = 18 + sr*(1 + (N-K-1)/33);
	printf("%d", age);
	return 0;
}
