#include <stdio.h>

int main()
{
    unsigned long long int X;

    scanf("%llu", &X);

    if (X % 3 == 0)
        printf("%llu", X / 3U);
    else if (X % 3 == 2)
        printf("%llu", (18446744073709551615U / 3U + (X + 1U) / 3U));
    else if (X % 3 == 1)
        printf("%llu", (18446744073709551615U / 3U * 2U + (X + 2U) / 3U));

    //printf("%llu", 3 * X);

    return 0;
}
