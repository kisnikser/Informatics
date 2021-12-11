#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[10000] = {0};
    char num[100] = {0};
    char number[100] = {0};
    char c;
    int i = 0;

    while (scanf("%c", &c) != EOF)
    {
        if (isdigit(c))
        {
            num[i++] = c;
            continue;
        }
        if (i)
        {
            sprintf(number, "NUMBER:%d ", atoi(num));
            strcat(str, number);
            i = 0;
            memset(num, 0, 100);
            memset(number, 0, 100);
        }
        if (isspace(c))
            continue;
        else if (c == '(')
            strcat(str, "LBRAC ");
        else if (c == ')')
            strcat(str, "RBRAC ");
        else if (c == '+')
            strcat(str, "PLUS ");
        else if (c == '-')
            strcat(str, "MINUS ");
        else if (c == '*')
            strcat(str, "MUL ");
        else if (c == '/')
            strcat(str, "DIV ");
        else
        {
            printf("ERROR");
            return 0;
        }
    }

    printf("%s", str);

    return 0;
}
