#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
    int x;
    int y;
}Point;

int cmp_Point(const void * p1, const void * p2)
{
    struct Point* point1 = (struct Point*)p1;
    struct Point* point2 = (struct Point*)p2;

    int x1 = point1->x;
    int y1 = point1->y;
    int x2 = point2->x;
    int y2 = point2->y;

    int sr = (x1*x1 + y1*y1) - (x2*x2 + y2*y2);

    if (sr == 0)
    {
        if (x1 == x2)
            return y1 - y2;
        else
            return x1 - x2;
    }
    else
        return sr;
}

int main()
{
    int N;

    scanf("%d", &N);

    Point* points = (Point*)calloc(N, sizeof(Point));

    for (int i = 0; i < N; i++)
        scanf("%d%d\n", &points[i].x, &points[i].y);

    qsort(points, N, sizeof(Point), cmp_Point);

    for (int i = 0; i < N; i++)
        printf("%d %d\n", points[i].x, points[i].y);

    free(points);

    return 0;
}
