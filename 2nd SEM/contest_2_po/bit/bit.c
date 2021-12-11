#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, check1 = 1;

    check1 <<= 2;

    scanf("%x", &N);

    switch(N & check1)
    {
        case 1:
            printf("ha");
            break;
        case 0:
            printf("nh");
            break;
    }

    return 0;
}
