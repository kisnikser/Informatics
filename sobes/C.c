#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Vector;

int main()
{
    Vector a, b;
    double angle = 0;

    scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);

    angle = acos((a.x * b.x + a.y * b.y) / (sqrt(a.x * a.x + a.y * a.y) * sqrt(b.x * b.x + b.y * b.y)));

    printf("%lf", angle);

    return 0;
}
