#include <stdio.h>

int fpower(int n, int k)
{
    if (!k)
        return 1;
    return n * fpower(n, k - 1);
}

int main()
{
    int n, k;

    scanf("%d%d", &n, &k);

    printf("%d", fpower(n, k));

    return 0;
}
