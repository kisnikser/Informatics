#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ip[4] = {0};
    int mask[4] = {0};
    int adr[4] = {0};
    int i;

    scanf("%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3);
    scanf("%d.%d.%d.%d", mask, mask + 1, mask + 2, mask + 3);

    for (i = 0; i < 4; i++)
        adr[i] = (ip[i] & mask[i]) + (255 - mask[i]);

    printf("%d.%d.%d.%d", adr[0], adr[1], adr[2], adr[3]);

    return 0;
}
