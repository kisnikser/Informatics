#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m;
    int s;
} Sc;

int cmp_sc(const void * pa, const void * pb)
{
    const Sc a = *(const Sc*)pa;
    const Sc b = *(const Sc*)pb;

    if (a.m != b.m)
        return a.m - b.m;
    else
        return a.s - b.s;
}

int main()
{
    int cur = 0, count = 0, n;
    Sc array[100000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &array[i].m, &array[i].s);

    qsort(array, n, sizeof(Sc), cmp_sc);

    /*printf("\n");

    for (int i = 0; i < n; i++)
        printf("%d %d\n", array[i].m, array[i].s);*/

    for (int i = 0; i < n; i++)
    {
        if (array[i].s >= cur)
        {
            cur += array[i].m;
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
