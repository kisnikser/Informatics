#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_comparing(const void* pa, const void * pb)
{
    return *(int*)pa - *(int*)pb;
}

int main()
{
    int N;

    scanf("%d", &N);

    int* array = (int*)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
        scanf("%d", array + i);

    qsort(array, N, sizeof(int), int_comparing);

    for (int i = 0; i < N; i++)
        printf("%d ", array[i]);

    free(array);
    return 0;
}
