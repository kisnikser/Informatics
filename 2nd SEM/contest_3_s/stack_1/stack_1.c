#include <stdio.h>
#include <stdlib.h>

#define N 100
typedef int Data;

struct Stack {
    int n;
    Data a[N];
};

void stack_create(struct Stack * s)
{
    s->n = 0;
}

void stack_push(struct Stack * s, Data x)
{
    s->a[s->n] = x;
    s->n++;
}

Data stack_pop(struct Stack * s)
{
    s->n--;
    Data x = s->a[s->n];
    s->a[s->n] = 0;
    return x;
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

void stack_clear(struct Stack * s)
{
    int i;

    for (i = 0; i < s->n; i++)
        s->a[i] = 0;

    s->n = 0;
}

int main()
{
    struct Stack s;
    int x;

    stack_create(&s);
    stack_push(&s, 5);
    stack_print(&s);
    stack_push(&s, 19);
    stack_print(&s);
    x = stack_size(&s);
    printf("size=%d\n", x);
    x = stack_pop(&s);
    printf("x=%d\n", x);
    stack_print(&s);
    x = stack_pop(&s);
    printf("x=%d\n", x);
    stack_print(&s);

    return 0;
}
