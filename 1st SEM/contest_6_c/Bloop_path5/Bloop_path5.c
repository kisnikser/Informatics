#include <stdio.h>

int main()
{
	int len, step;
	scanf("%d%d", &len, &step);
	int path = 0;
	int i = 0;
	int delta_path = len - path;
	while (delta_path >= step)
	{
		path += step;
		delta_path = len - path;
		i++;
	}
	printf("%d\n", delta_path);
	printf("%d", i	);
	return 0;
}
