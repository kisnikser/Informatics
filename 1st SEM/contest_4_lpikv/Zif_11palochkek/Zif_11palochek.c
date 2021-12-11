#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	if (N % 4 == 1)
		printf("-1");
	if (N % 4 == 2)
		printf("1"); 
	if (N % 4 == 3)
		printf("2");
	if (N % 4 == 0)
		printf("3");
}
