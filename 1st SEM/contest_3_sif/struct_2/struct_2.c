#include <stdio.h>

struct Rect0 
{
	int x;
	int y;
	int width;
	int height;
};

struct Point
{
	int x;
	int y;
};

struct Rect1
{
	struct Point lt;
	struct Point rb;
};

int areaRect0(struct Rect0 rect)
{
	return rect.width * rect.height;
};

int areaRect1(struct Rect1 rect)
{
	return (rect.rb.x - rect.lt.x)*(rect.lt.y - rect.rb.y);
};

int main()
{
	int x, y, w, h, x1, y1, x2, y2;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	struct Rect0 rect_0;
	rect_0.x = x;
	rect_0.y = y;
	rect_0.width = w;
	rect_0.height = h;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	struct Point m;
	struct Point k;
	m.x = x1;
	m.y = y1;
	k.x = x2;
	k.y = y2;
	struct Rect1 rect_1;
	rect_1.lt = m;
	rect_1.rb = k;
	printf("%d\n", areaRect0(rect_0));
	printf("%d", areaRect1(rect_1));	
};
