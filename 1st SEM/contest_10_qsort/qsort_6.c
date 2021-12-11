#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_unit_incr(const void* pa, const void * pb)
{
    int a = *(int*)pa;
    int b = *(int*)pb;

    if ((a % 10) == (b % 10))
        if ((a % 100) == (b % 100))
            if ((a % 1000) == (b % 1000))
                if ((a % 10000) == (b % 10000))
                    return 0;
                else
                    return (a % 10000) - (b % 10000);
            else
                return (a % 1000) - (b % 1000);
        else
            return (a % 100) - (b % 100);
    else
        return (a % 10) - (b % 10);
}

int main()
{
    int N;

    scanf("%d", &N);

    int* array = (int*)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
        scanf("%d", array + i);

    qsort(array, N, sizeof(int), int_unit_incr);

    for (int i = 0; i < N; i++)
        printf("%d ", array[i]);

    free(array);
    return 0;
}
