#include <stdio.h>

int main()
{
	int xlt, ylt, xrb, yrb;
	
	scanf("%d%d%d%d", &xlt, &ylt, &xrb, &yrb);
	
	printf("%d %d %d %d\n", xlt, ylt, xrb, yrb);
	printf("%d %d %d %d", xrb, ylt, xrb + ylt - yrb, ylt - xrb + xlt); 
	
	return 0;
}
