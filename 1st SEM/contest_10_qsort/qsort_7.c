#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_odd_incr(const void* pa, const void * pb)
{
    int a = *(int*)pa;
    int b = *(int*)pb;

    if ((a % 2 != 0) || (b % 2 != 0))
        return 0;
    else
        return a - b;
}

int main()
{
    int N, k = 0, m = 0;

    scanf("%d", &N);

    int* array = (int*)calloc(N, sizeof(int));
    int* odd_array = (int*)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", array + i);
        if (array[i] % 2 == 0)
        {
            odd_array[k] = array[i];
            k++;
        }
    }

    qsort(odd_array, k, sizeof(int), int_odd_incr);

    for (int i = 0; i < N; i++)
    {
        if (array[i] % 2 == 0)
        {
            array[i] = odd_array[m];
            m++;
        }
        printf("%d ", array[i]);
    }

    free(odd_array);
    free(array);
    return 0;
}
