#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;

    scanf("%X%X", &a, &b);

    printf("%x", a ^ b);

    return 0;
}
