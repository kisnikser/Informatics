#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[10000] = {0};
    char number[100] = {0};
    char c;
    int i = 0, j = 0, block = 1, maxlen = 3;

    while (scanf("%c", &c) != EOF)
    {
        if (isdigit(c))
        {
            s[i++] = c;
            number[j++] = c;
        }
        else
        {
            maxlen = (j > maxlen) ? j : maxlen;

            if (c == '.')
            {
                s[i++] = c;
                block++;
            }
            else
            {
                if ((block == 4) && (maxlen == 3))
                    printf("%s\n", s);

                block = 1;
                maxlen = 3;
                i = 0;
                memset(s, 0, 10000);
            }

            j = 0;
            memset(number, 0, 100);
        }
    }


    return 0;
}
