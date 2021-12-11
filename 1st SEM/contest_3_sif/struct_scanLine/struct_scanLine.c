#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point 
{
    int x;
    int y;
};

struct Line 
{
    struct Point a; // начало отрезка
    struct Point b; // конец отрезка
    float len;      // длина отрезка
};

float distance(struct Point a, struct Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); 
}

void scanLine(struct Line* t)
{
	struct Point a;
	struct Point b;
	scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
	t->a = a;
	t->b = b;
	t->len = distance(a, b);
}

void printLine(struct Line t)
{
	printf("%d %d %d %d %f", t.a.x, t.a.y, t.b.x, t.b.y, t.len);
}

int main() 
{
    struct Line t;
    
    scanLine(&t);
    printLine(t);
    
    return 0;
}
