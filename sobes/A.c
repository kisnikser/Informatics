#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

int main()
{
    Point p, a, b;
    double r = 0;

    scanf("%d %d %d %d %d %d", &p.x, &p.y, &a.x, &a.y, &b.x, &b.y);

    if (((p.x - a.x) * (b.x - a.x) + (p.y - a.y) * (b.y - a.y)) < 0)
        r = sqrt((p.x - a.x) * (p.x - a.x) + (p.y - a.y) * (p.y - a.y));
    else if (((p.x - b.x) * (a.x - b.x) + (p.y - b.y) * (a.y - b.y)) < 0)
        r = sqrt((p.x - b.x) * (p.x - b.x) + (p.y - b.y) * (p.y - b.y));
    else
        r = fabs((a.y - b.y) * p.x + (b.x - a.x) * p.y + (a.x * b.y - b.x * a.y)) / sqrt((a.y - b.y) * (a.y - b.y) + (b.x - a.x) * (b.x - a.x));

    printf("%lf", r);

    return 0;
}
