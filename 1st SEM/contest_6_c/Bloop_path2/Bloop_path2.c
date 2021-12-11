#include <stdio.h>

int main()
{
	int L, k;
	scanf("%d%d", &L, &k);
	int step = L;
	int path = 0;
	int i = 0;
	while (i < 100)
	{
		path += step;
		step += k;
		i += 1;
	}
	printf("%d", path);
	return 0;
}
