#include <stdio.h>
#include <stdlib.h>

#define N 100

int NOD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return NOD(b, a % b);
}

typedef struct {
    int kx, ky;
} coef;

struct Stack {
    int n;
    coef a[N];
};

void stack_create(struct Stack * s)
{
    s->n = 0;
}

void stack_push(struct Stack * s, coef k)
{
    s->a[s->n] = k;
    s->n++;
}

coef stack_pop(struct Stack * s)
{
    s->n--;
    coef k = s->a[s->n];
    return k;
}

coef stack_get(struct Stack * s)
{
    return s->a[s->n];
}

void stack_print(struct Stack * s)
{
    int i;

    if (s->n)
        for (i = 0; i < s->n; i++)
            printf("%d %d | ", s->a[i].kx, s->a[i].ky);
    else
        printf("Empty stack");

    printf("\n");
}

int stack_is_empty(struct Stack * s)
{
    return !s->n;
}

int stack_size(struct Stack * s)
{
    return s->n;
}

void stack_clear(struct Stack * s)
{
    int i;

    for (i = 0; i < s->n; i++)
    {
        s->a[i].kx = 0;
        s->a[i].ky = 0;
    }

    s->n = 0;
}

int main()
{
    struct Stack array;

    stack_create(&array);

    coef k;
    int a, b, ca, cb, c, x, y, flag;

    scanf("%d%d%d", &a, &b, &c);

    ca = a;
    cb = b;

    if (c % NOD(a, b))
    {
        printf("No solutions.");
        return 0;
    }

    while ((a != 1) && (b != 1))
    {
        if (a > b)
        {
            k.kx = a / b;
            k.ky = 1;
            a %= b;
        }
        else
        {
            k.kx = 1;
            k.ky = b / a;
            b %= a;
        }
        stack_push(&array, k);
    }

    //printf("array: | ");
    //stack_print(&array);

    x = (a == 1) ? c : 0;
    y = (a == 1) ? 0 : c;

    flag = !!y;

    //printf("Solutions: x: %d y: %d\n", x, y);

    while (!stack_is_empty(&array))
    {
        k = stack_pop(&array);
        //printf("kx: %d ky: %d\n", k.kx, k.ky);
        //stack_print(&array);
        x -= (flag % 2) * k.ky * y;
        y -= !(flag % 2) * k.kx * x;
        flag++;
    }

    printf("x = %d - %dn; y = %d + %dn, n in Z.", x, cb, y, ca);

    return 0;
}
