#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // Для установки национальных параметров
#include <wchar.h>  // Описание функций для работы с "толстыми" (двухбайтовыми) символами
#include <errno.h>

int main(int argc, char** argv)
{
    FILE *fin, *fout;

    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    if (errno)
        perror("ERROR");

    setlocale(LC_CTYPE, "ru_RU.UTF-8");

    wchar_t s[] = L"Это русский язык.";
    wchar_t s2[100];
    wchar_t s3[100];

    wprintf(L"%ls %lc\n", s, s[4]);
    wscanf(L"%ls", s2);
    wprintf(L"%ls %lc\n", s2, s2[0]);

    while (fgetws(s3, 100, fin) != NULL)
        fputws(s3, fout);

    fclose(fin);
    fclose(fout);
    return 0;
}
