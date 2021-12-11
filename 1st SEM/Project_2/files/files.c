#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wchar.h>

int main(int argc, char** argv)
{
    /* printf("argc: %d\n", argc);

    for (int i = 0; i < argc; i++)
        printf("argv[%d]: %s\n", i, argv[i]); */

    if (argc < 3)
    {
        printf("Too few arguments!");
        exit(1);
    }

    FILE *fin, *fout;

    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    if (errno)
    {
        perror("ERROR");
        exit(1);
    }

    char buf[20];

    while (fscanf(fin, L"%s", buf) != EOF)
    {
        fprintf(fout, L "%lc/-", buf[0]);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
