#include <stdio.h>

int main()
{
	int n;
    long long int f1 = 2, f2 = 3;

	scanf("%d", &n);

    while (n > 2)
    {
        f2 = f1 + f2;
        f1 = f2 - f1;
        n--;
    }

    if (n == 1)
        printf("%lld", f1);
    else
        printf("%lld", f2);

    return 0;
}
