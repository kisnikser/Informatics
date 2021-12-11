#include <stdio.h>

int main()
	{
	int h1, m1, mm;
	scanf("%d", &mm);
	h1 = mm/60;
	m1 = mm%60;
	printf("%d %d", h1, m1);
	}
