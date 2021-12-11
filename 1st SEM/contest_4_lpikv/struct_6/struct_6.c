#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Rect {
    struct Point lt; // левая верхняя вершина
    struct Point rb; // правая нижняя вершина
};

void normalize(struct Rect * p)
{
	if (p->lt.x > p->rb.x)
		{
			int tmp = p->lt.x;
			p->lt.x = p->rb.x;
			p->rb.x = tmp;
		}
	if (p->rb.y > p->lt.y)
		{
			int tmp = p->lt.y;
			p->lt.y = p->rb.y;
			p->rb.y = tmp;
		}
}

int main()
{
	struct Rect a;
	scanf("%d", &(a.lt.x));
	scanf("%d", &(a.lt.y));
	scanf("%d", &(a.rb.x));
	scanf("%d", &(a.rb.y));

    normalize(&a);
    printf("%d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);
	
	return 0;
}
