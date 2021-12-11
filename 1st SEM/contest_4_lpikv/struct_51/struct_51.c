#include <stdio.h>

struct Point 
{
    int x;
    int y;
};

struct Rect 
{
    struct Point lt; // левая верхняя вершина
    struct Point rb; // правая нижняя вершина
};

struct Rect * max(struct Rect * pa, struct Rect * pb)
{
	struct Rect* max;
	if ((pa->rb.x - pa->lt.x)*(pa->lt.y - pa->rb.y) > (pb->rb.x - pb->lt.x)*(pb->lt.y - pb->rb.y))
		max = pa;
	else max = pb;
	return max;
}

int  main()
{
	struct Rect pa, pb, pmax;
	scanf("%d %d %d %d", &pa.lt.x, &pa.lt.y, &pa.rb.x, &pa.rb.y);
	scanf("%d %d %d %d", &pb.lt.x, &pb.lt.y, &pb.rb.x, &pb.rb.y);
	pmax = *max(&pa, &pb);
	printf("%d %d %d %d", pmax.lt.x, pmax.lt.y, pmax.rb.x, pmax.rb.y);
}
