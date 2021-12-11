#include <stdio.h>

int main()
{
	int K, p1, p2, p3;
	scanf("%d%d%d%d", &K, &p1, &p2, &p3);
	if ((p1 + p2 <= K && p3 <= K) || (p2 + p3 <= K && p1 <= K) || (p1 + p3 <= K && p2 <= K))
		printf("YES");
	else 
		printf("NO");
	return 0;
}
