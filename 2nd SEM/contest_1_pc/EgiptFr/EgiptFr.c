#include <stdio.h>
#include <stdlib.h>

long long NOD(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return NOD(b, a % b);
}

int main()
{
    long long n, d, del, i = 0, k = 0;
    long long den[100] = {0};

    scanf("%lld %lld", &n, &d);

    while (n != 1)
    {
        den[i] = ( d / n ) + 1;
        n = n * den[i] - d;
        d = d * den[i];
        del = NOD(n, d);
        n /= del;
        d /= del;
        i++;
    }

    den[i] = d;

    for (k = 0; k <= i; k++)
    {
        printf("%lld ", den[k]);
    }

    return 0;
}
