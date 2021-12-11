#include <stdio.h>
#include <stdlib.h>

int NOD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return NOD(b, a % b);
}

int fpower(int n, int k)
{
    if (!k)
        return 1;
    return n * fpower(n, k - 1);
}

typedef union types
{
    float f;
    unsigned int i;
} types;

int main()
{
    types N;
    int i, imax = 0, power, num = 1, denum;

    scanf("%f", &N.f);

    int inta = (int)N.f;

    if (((N.f - inta) < 0.00000001) && ((inta - N.f) < 0.00000001))
    {
        printf("%d(0/1)", inta);
        return 0;
    }

    N.f -= inta;

    denum = fpower (2, 127 - ((N.i & 255 << 23) >> 23));

    for (i = 9; i < 32; i++)
    {
        num = 2 * num + ((N.i & (1 << (31 - i))) >> 31 - i);
        denum <<= 1;
    }

    printf("%d(%d/%d)", inta, num/NOD(num, denum), denum/NOD(num, denum));

    return 0;
}
