#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* text = calloc(1000, sizeof(char));
    char* word = calloc(1001, sizeof(char));
    int maxlen = 0;

    while (scanf("%s", text) != EOF)
    {
        if (strlen(text) > maxlen)
        {
            maxlen = strlen(text);
            strcpy(word, text);
        }
    }

    printf("%s %d", word, maxlen);

    free(text);
    free(word);

    return 0;
}
