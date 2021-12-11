#include <stdio.h>

int main()
	{
	int h1, m1, mm, hres, mres;
	scanf("%d %d %d", &h1, &m1, &mm);
	hres = (60*h1 + m1 + mm)/60;
	mres = (60*h1 + m1 + mm)%60;
	printf("%d %d", hres, mres);
	}
