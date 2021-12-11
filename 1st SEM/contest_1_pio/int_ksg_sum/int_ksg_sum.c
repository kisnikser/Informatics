#include <stdio.h>

int main()
	{
	int g1, s1, k1, g2, s2, k2, g3, s3, k3, sum;
	scanf("%d %d %d", &g1, &s1, &k1);
	scanf("%d %d %d", &g2, &s2, &k2);
	sum = 17*29*(g1+g2)+29*(s1+s2)+k1+k2;
	g3 = sum/(17*29);
	s3 = (sum - 17*29*g3)/29;
	k3 = sum - 17*29*g3 - 29*s3;
	printf("%d %d %d", g3, s3, k3);
	}
