#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char num;
    unsigned char message = 0;
    unsigned char empty = 8;

    while (scanf("%hhu", &num) != EOF)
    {
        if (empty >= 3)
        {
            message |= num << (empty - 3);
            empty -= 3;
            if (!empty)
            {
                printf("%hhu ", message);
                message = 0;
                empty = 8;
            }
        }
        else if (empty == 2)
        {
            message |= (num & 6) >> 1;
            printf("%hhu ", message);
            message = 0;
            message |= num << 7;
            empty = 7;
        }
        else if (empty == 1)
        {
            message |= (num & 4) >> 2;
            printf("%hhu ", message);
            message = 0;
            message |= num << 6;
            empty = 6;
        }
    }

    if (empty != 8)
        printf("%hhu", message);

    return 0;
}
