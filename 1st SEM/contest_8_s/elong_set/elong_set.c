#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct _Decimal
{
    char a[N];   // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;       // наибольшая степень десяти
};

typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0};    // представление 0 в виде структуры

Decimal set (const char str[])
{
    Decimal a;
    int j, i = 0;

	while (str[i] != '\0') // i = strlen(str)
		i++;

    a.n = i-1;

    for (j = 0; j <= a.n; j++)
    {
        a.a[j] = str[i-j-1] - 48;
    }

    return a;
}

void print (Decimal a)
{
    int i;

    for (i = a.n; i >= 0; i--)
    {
        printf("%c", a.a[i]);
    }
}

int main()
{
    Decimal res;
    res = set("12345678901234567890");  // res = 12345678901234567890

    print(res);                         // print 12345678901234567890
    printf("\n");

    return 0;
}
