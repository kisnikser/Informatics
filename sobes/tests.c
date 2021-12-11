#include <stdio.h>

int cmpfloat(float a, float b)
{
    return (a > b - 0.00000001) - (a < b + 0.00000001);
}

int main()
{
    printf("%lu", 18446744073709551615U * 3U);

    return 0;
}
