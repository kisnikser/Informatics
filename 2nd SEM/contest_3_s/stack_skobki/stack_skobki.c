#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;

struct Stack {
    int n;
    int size;
    Data * a;
};

struct Stack * stack_create(int size)
{
    struct Stack * s = calloc(1, sizeof(struct Stack));
    s->a = calloc(size, sizeof(Data));
    s->n = 0;
    s->size = size;
    return s;
}

void stack_push(struct Stack * s, Data x)
{
    if (s->n >= s->size)
    {
        s->size += 1000;
        s->a = realloc(s->a, s->size * sizeof(Data));
    }

    s->a[s->n] = x;
    s->n++;
}

Data stack_pop(struct Stack * s)
{
    s->n--;
    return s->a[s->n];
}

Data stack_get(struct Stack * s)
{
    return s->a[s->n];
}

void stack_print(struct Stack * s)
{
    int i;

    if (s->n)
        for (i = 0; i < s->n; i++)
            printf("%d ", s->a[i]);
    else
        printf("Empty stack");

    printf("\n");
}

int stack_size(struct Stack * s)
{
    return s->n;
}

int  stack_is_empty(struct Stack * s)
{
    return !s->n;
}

void stack_clear(struct Stack * s)
{
    int i;

    for (i = 0; i < s->n; i++)
        s->a[i] = 0;

    s->n = 0;
}

void stack_destroy(struct Stack * s)
{
    free(s->a);
    free(s);
}

int main()
{
    const char *open = "([{<"; // массив открывающих скобок
    const char *close = ")]}>"; // массив закрывающих скобок
    char bracket; // полученная скобка
    int get; // взятая из стека скобка
    int i; // счётчик
    int k = 0; // количество "свободных" открывающих скобок
    char* p = 0; // указатель на открывающую скобку
    char* q = 0; // указатель на закрывающую скобку

    struct Stack *sp = stack_create(50); // стек для записи скобок

    while (scanf("%c", &bracket) != EOF)
    {
        for (i = 0; i < 4; i++)
        {
            if (bracket == open[i])
            {
                stack_push(sp, i);
                k++;
                //stack_print(sp);
            }
            if (bracket == close[i])
            {
                if (stack_is_empty(sp))
                {
                    printf("NO");
                    stack_destroy(sp);
                    return 0;
                }
                get = stack_pop(sp);
                k--;
                if (i != get)
                {
                    printf("NO");
                    stack_destroy(sp);
                    return 0;
                }
                //stack_print(sp);
            }
        }
    }

    //printf("%d\n", k);

    if (!k)
        printf("YES");
    else
        printf("NO");

    stack_destroy(sp);
    return 0;
}
