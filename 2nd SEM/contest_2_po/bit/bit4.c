#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, sol, i;
    char* sex[2] = {"fe", "ma"};
    char* smart[2] = {"du", "cl"};
    char* hat[2] = {"nh", "ha"};
    char* clothes[2] = {"sk", "tr"};
    char* hair[4] = {"bn", "rd", "bw", "bk"};
    char* eyes[4] = {"bu", "ge", "gy", "da"};
    char** character[6] = {sex, smart, hat, clothes, hair, eyes};

    scanf("%x", &N);

    for (i = 0; i < 6; i++)
    {
        sol = (((2 * (i / 4) + 1) << (i / 5 + i)) & N) >> (i / 5 + i);
        printf("%s ", character[i][sol]);
    }

    return 0;
}
