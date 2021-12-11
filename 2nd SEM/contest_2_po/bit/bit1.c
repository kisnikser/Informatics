#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, check1 = 1;
    char* sex[2] = {"fe", "ma"};

    scanf("%x", &N);

    printf("%s", sex[N & check1]);

    return 0;
}
