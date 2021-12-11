#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Replace(char* str, const char* old, const char* new)
{
    int i; // Счетчик
    char* find; // Указатель на найденную подстроку
    char* copy = (char*)calloc(strlen(str) + 1, sizeof(char)); // Динамическая память для копии исходной строки
    strcpy(copy, str); // Копируем строку в copy
    char* part = copy; // Указатель на начало копии
    char* res; // Указатель для результата замены
    int len_new = strlen(new);
    int len_old = strlen(old);
    int len_str = strlen(str) * len_new; // Назначаем достаточную для замены длину строки
    res = (char*)calloc(len_str, sizeof(char)); // Динамическая память для результата замены
    bzero(res, len_str * sizeof(char)); // Заполняем результат замены символами '\0'

    for (i = 0; (find = strstr(part, old)) != 0; i++) // Заменяем слова old на new, пока будет найдено old
    {
        find[0] = '\0'; // Первый символ для замены как конечный символ part
        strcat(res, part); // Присоединяем часть строки до первого символа для замены
        strcat(res, new); // Присоединяем новое слово
        part = find + len_old; // Переносим указатель на следующий после старого слова символ
    }

    strcat(res, part); // Присоединяем оставшуются часть строки в результат

    if (i == 0) // Если ни одного слова для замены не было найдено
    {
        free(res);
        free(copy);
        free(find);
        return NULL;
    }

    free(copy); // Освобождаем
    free(find); //       динамическую память

    return res;
}

int main()
{
    char buf[1001]; // Буфер для считывания строк
    char* p = 0; // Указатель на строку с замененными словами

    while(fgets(buf, 1000, stdin) != NULL) // Пока не конец строки
    {
        p = Replace(buf, "bomb", "watermelon"); // Заменяем bomb на watermelon
        if(p == NULL) // Если нет  слов  для замены
            printf("%s", buf);
        else          // Если есть слова для замены
            printf("%s", p);
    }
    
    free(p); // Освобождаем динамическую память
    return 0;
}
