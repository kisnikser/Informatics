#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N = 0, i, j;
    char str[200];
    char* sex[2] = {"fe", "ma"};
    char* smart[2] = {"du", "cl"};
    char* hat[2] = {"nh", "ha"};
    char* clothes[2] = {"sk", "tr"};
    char* hair[4] = {"bn", "rd", "bw", "bk"};
    char* eyes[4] = {"bu", "ge", "gy", "da"};
    char** character[6] = {sex, smart, hat, clothes, hair, eyes};

    fgets(str, 1000, stdin);

    for (i = 0; i < 4; i++)
        for (j = 0; j < 2; j++)
            if (strstr(str, character[i][j]) != NULL)
                N |= (j << i);

    for (i = 4; i < 6; i++)
        for (j = 0; j < 4; j++)
            if (strstr(str, character[i][j]) != NULL)
                N |= (j << (i + i / 5));

    printf("%x", N);

    return 0;
}
