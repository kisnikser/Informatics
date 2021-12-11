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
    const char *brackets = "([{<)]}>"; // массив скобок
    char bracket; // полученная скобка
    char * p;

    struct Stack *sp = stack_create(50); // стек для записи скобок

    while ((bracket = getchar()) != EOF)
    {
        if ((p = strchr(brackets, bracket)) == NULL)
            continue;

        if (!(((int)(p - brackets)) / 4))
            stack_push(sp, ((int)(p - brackets)) % 4);
        else
        {
            if (stack_is_empty(sp))
            {
                printf("NO");
                stack_destroy(sp);
                return 0;
            }

            if ((((int)(p - brackets)) % 4) != stack_pop(sp))
            {
                printf("NO");
                stack_destroy(sp);
                return 0;
            }
        }
    }

    if (stack_is_empty(sp))
        printf("YES");
    else
        printf("NO");

    stack_destroy(sp);
    return 0;
}
