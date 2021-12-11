#include <stdio.h>

int main()
{
	int h, m, t1, t2;
	scanf("%d%d%d%d", &h, &m, &t1, &t2);
	int hA = 6;
	int mA = 0;
	int hB = 5;
	int mB = 45;
	int toA = (hA * 60 + mA < h * 60 + m) ? (((h * 60 + m - hA * 60 - mA) / t1) * t1 - h * 60 - m + hA * 60 + mA) : (hA * 60 + mA - h * 60 - m);
	int toB = (hB * 60 + mB < h * 60 + m) ? (((h * 60 + m - hB * 60 - mB) / t2) * t2 - h * 60 - m + hB * 60 + mB) : (hB * 60 + mB - h * 60 - m);
	toA = (toA < 0) ? (toA + t1) : toA;
	toB = (toB < 0) ? (toB + t2) : toB;
	printf("%d\n", toA);
	printf("%d\n", toB);
	(toA <= toB)? printf("A") : printf("B");
	return 0;
}
