#include <stdio.h>

struct Point
{
    float x;
    float y;
};

int in_region(struct Point p)
{
	if ((p.y >= p.x*p.x - 5) && (p.y <= -p.x*p.x + 3) && (p.x >= -1))
		return 1;
	else
		return 0;
}

int main()
{
	struct Point p;
	
	scanf("%d %d", &p.x, &p.y);
	
	printf("%d", in_region(p));
	
	return 0;
}
