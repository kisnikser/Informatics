#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N, i = 0;
    int tr[101] = {0};

    scanf("%d", &N);

    while (N > 0)
    {
        tr[i] = N % 3;
        N /= 3;
        i++;
    }

    int len = i;

    for (i = 0; i < len; i++)
    {
        switch (tr[i])
        {
            case 2: tr[i] = -1;
                    tr[i + 1]++;
                    break;
            case 3: tr[i] = 0;
                    tr[i + 1]++;
                    break;
        }
    }

    printf("1\n");

    for (i = 0; i <= len; i++)
    {
        if (tr[i] == 1)
            printf("%d ", (int)(pow(3, i)));
    }

    printf("\n");

    for (i = 0; i <= len; i++)
    {
        if (tr[i] == -1)
            printf("%d ", (int)(pow(3, i)));
    }

    return 0;
}
