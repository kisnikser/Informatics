#include <stdio.h>

float temFC(int faren)
{
	float c = (faren - 32)/1.8;
	return c;
}

int main()
{
	int faren;
	scanf("%d", &faren);
	printf("%.0f", temFC(faren));
}
