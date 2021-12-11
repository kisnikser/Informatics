#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, sol, check3 = 3;
    char* hair[4] = {"bn", "rd", "bw", "bk"};

    scanf("%x", &N);

    check3 <<= 4;
    sol = N & check3;
    sol >>= 4;

    printf("%s", hair[sol]);

    return 0;
}
