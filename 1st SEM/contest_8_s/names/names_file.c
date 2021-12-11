#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        printf("Too few arguments!!!");
        exit(1);
    }

    printf("argv[0]: %s", argv[0]);
    printf("argv[1]: %s", argv[1]);
    printf("argv[2]: %s", argv[2]);

    FILE *fin, *fout;

    printf("%d\n", argc);

    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    if (errno)
        {
            perror("ERROR");
            exit(1);
        }

    int i, N, mcount = 0, fcount = 0;
    char I[100];
    char O[100];
    char F[100];
    char* pend;

    fscanf(fin, "%d", &N);

    for (i = 0; i < N; i++)
    {
        fscanf(fin, "%s %s %s", I, O, F);

        pend = O + strlen(I) - 3;

        if (strcmp(pend, "ич") == 0)
            {
                mcount++;
                fprintf(fout, "%s %s %s м\n", F, I, O);
            }
        else
            {
                fcount++;
                fprintf(fout, "%s %s %s ж\n", F, I, O);
            }
    }

    fprintf(fout, "%d %d\n", mcount, fcount);

    fclose(fin);
    fclose(fout);
    return 0;
}
