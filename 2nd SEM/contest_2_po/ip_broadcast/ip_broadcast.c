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

/*
Адрес компьютера: 192.168.254.4
                  11000000.10101000.11111110.00000100
Сетевая маска:    255.255.252.0
                  11111111.11111111.11111100.00000000

*/
