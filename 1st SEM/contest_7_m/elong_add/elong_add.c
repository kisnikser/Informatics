#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct _Decimal
{
    char a[100];
    unsigned int n;
};

typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0};

Decimal add (Decimal a, Decimal b)
{
    int i;
    Decimal sum = {{0}, 0};

    if (a.n >= b.n)
    {
        sum.n = a.n + 1;

        for (i = 0; i <= b.n; i++)
        {
            sum.a[i] += a.a[i] - 48 + b.a[i] - 48;
            sum.a[i+1] += (char)((int)(sum.a[i] / 10));
            sum.a[i] = (char)((int)(sum.a[i] % 10));
        }

        for (i = (b.n + 1); i <= a.n; i++)
        {
            sum.a[i] += a.a[i] - 48;
        }
    }
    else
    {
        sum.n = b.n + 1;

        for (i = 0; i <= a.n; i++)
        {
            sum.a[i] += a.a[i] - 48 + b.a[i] - 48;
            sum.a[i+1] += (char)((int)(sum.a[i] / 10));
            sum.a[i] = (char)((int)(sum.a[i] % 10));
        }

        for (i = (a.n + 1); i <= b.n; i++)
        {
            sum.a[i] += b.a[i] - 48;
        }
    }

    if (sum.a[sum.n] == 0)
        sum.n--;

    return sum;
}

void print (Decimal a)
{
    unsigned int i;

    for (i = a.n; i >= 0; i--)
    {
        printf("%c", a.a[i]);
    }
}

int main()
{
    Decimal a = {{7, 4, 1}, 2};  // set number 147
    Decimal b = {{3, 1}, 1};     // set number 13
    // Decimal res;

    printf("123");

    print(a);
    print(b);

    // res = add(a, b);             // res = a+b = 147+13 = 160
    // print (res);                 // print 160

    return 0;
}
