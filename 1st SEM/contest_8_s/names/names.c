#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

int main()
{
    setlocale(LC_CTYPE, "ru_RU.UTF-8");

    int i, N, mcount = 0, fcount = 0;
    wchar_t* I = (wchar_t*)calloc(100, sizeof(wchar_t));
    wchar_t* O = (wchar_t*)calloc(100, sizeof(wchar_t));
    wchar_t* F = (wchar_t*)calloc(100, sizeof(wchar_t));

    scanf("%d\n", &N);

    for (i = 0; i < N; i++)
    {
        wscanf(L"%ls %ls %ls\n", I, O, F);

        if (wcsstr(O, L"ич"))
            {
                mcount++;
                wprintf(L"%ls %ls %ls м\n", F, I, O);
            }
        else
            {
                fcount++;
                wprintf(L"%ls %ls %ls ж\n", F, I, O);
            }
    }

    printf("%d %d\n", mcount, fcount);

    free(I);
    free(O);
    free(F);
    return 0;
}
