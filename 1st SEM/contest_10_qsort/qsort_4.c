#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALMOSTZERO 0.0001

int float_comparing(const void* pa, const void * pb)
{
    float a = *(float*)pa;
    float b = *(float*)pb;

    return (a > b) - (a < b);
}

int main()
{
    int N;

    scanf("%d", &N);

    float* array = (float*)calloc(N, sizeof(float));

    for (int i = 0; i < N; i++)
        scanf("%f", array + i);

    qsort(array, N, sizeof(float), float_comparing);

    for (int i = 0; i < N; i++)
        printf("%0.2f ", array[i]);

    free(array);
    return 0;
}
