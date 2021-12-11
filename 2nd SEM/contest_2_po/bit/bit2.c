#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, sol, check1 = 1;
    char* hat[2] = {"nh", "ha"};

    scanf("%x", &N);

    check1 <<= 2;
    sol = N & check1;
    sol >>= 2;

    printf("%s", hat[sol]);

    return 0;
}
