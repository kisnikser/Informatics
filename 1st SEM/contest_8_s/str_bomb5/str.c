#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace(char* word, char const *repl, char const *str)
{
    int nword = strlen(word);
    int nstr = strlen(str);
    int nrepl = strlen(repl);
    char* find = 0; // указатель на найденную подстроку
    char* copy = (char*)calloc(nword	 + 1, sizeof(char)); // копия исходной строки word
    strcpy(copy, word);
    char* part = copy; //part - часть сроки между repl
    char* res = 0; // результат
    //размер динамической памяти для новой строки
    int len = strlen(word) * strlen(str);
    // выделение памяти для новой строки
    res = (char*)calloc(len, sizeof(char));
    //поиск подстрок
    int i = 0;
    for(i = 0; (find = strstr(part, repl)) != 0; i++)
    {
        find[0] = '\0';  //обозначаем первый символ как конечный от part
        strcat(res, part); //присоединяем part k res
        strcat(res, str); //присоединяем str k res
        part = find + nrepl; // вычисляем новое начало part
        //printf("res: %s\n", res);
        //printf("part: %s\n", part);
    }
    strcat(res, part); //приклеиваем последнюю part
    if(i == 0)// если ничего не нашли
    {
        free(res);
        free(copy);
        //res = word;
        return NULL;
    }
    free(copy);
    free(find);
    return res;
}


int main()
{
    char buf[1000];
    char* p = 0;
    while(fgets(buf, 1001, stdin) != NULL)
    {
        p = replace(buf, "bomb", "watermelon");
        if(p == NULL)
            printf("%s", buf);
        else
            printf("%s", p);
    }
        free(p);
}
