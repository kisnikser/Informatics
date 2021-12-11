#include <stdio.h>

struct Point 
{
    int x;
    int y;
};

int toY(struct Point a)
{
	return a.y;
}

int main()
{
	struct Point a;
	scanf("%d %d", &a.x, &a.y);
	printf("%d", toY(a));
}
