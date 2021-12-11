#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char Rshl(unsigned char number, char ident)
{
    return ((number << (ident % 8)) | (number >> (8 - (ident % 8))));
}

unsigned char Rshr(unsigned char number, char ident)
{
    return ((number >> (ident % 8)) | (number << (8 - (ident % 8))));
}

int main()
{
    unsigned char a, n, left, right;

    scanf("%hhu", &a);
    scanf("%hhu", &n);

    left = Rshl(a, n);
    right = Rshr(a, n);

    printf("%hhu\n", left);
    printf("%hhu", right);

    return 0;
}
