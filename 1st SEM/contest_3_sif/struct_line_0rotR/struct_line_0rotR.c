#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

struct Line {
    struct Point a; // начало отрезка
    struct Point b; // конец отрезка
    float len;      // длина отрезка
};

float distance(struct Point a, struct Point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void scanLine(struct Line* t)
{
	scanf("%d %d %d %d", &t->a.x, &t->a.y, &t->b.x, &t->b.y);
	t->len = distance(t->a, t->b);
}

void printLine(struct Line t)
{
	printf("%d %d %d %d %f", t.a.x, t.a.y, t.b.x, t.b.y, t.len);
}

void rotRLine(struct Line* t)
{
	int tmp;
	tmp = t->a.x;
	t->a.x = t->a.y;
	t->a.y = -tmp;
	tmp = t->b.x;
	t->b.x = t->b.y;
	t->b.y = -tmp;
}

int main() {
    struct Line t;
    
    scanLine(&t);
    // тут должен быть вызов функции rotRLine
    rotRLine(&t);
    
    printLine(t);
    
    return 0;
}
