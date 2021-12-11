#include <stdio.h>

int main()
	{
	int bell, nBell, k;
	scanf("%d %d", &bell, &nBell);
	k = (bell+nBell)*(nBell-bell+1)/2;
	printf("%d", k);
	}
