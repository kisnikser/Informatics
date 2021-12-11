#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int_rcomparing(const void* pa, const void * pb)
{
    return *(long long*)pb - *(long long*)pa;
}

int main()
{
    long long N;

    scanf("%lld", &N);

    long long* array = (long long*)calloc(N, sizeof(long long));

    for (long long i = 0; i < N; i++)
        scanf("%lld", array + i);

    qsort(array, N, sizeof(long long), int_rcomparing);

    for (long long i = 0; i < N; i++)
        printf("%lld ", array[i]);

    free(array);
    return 0;
}
