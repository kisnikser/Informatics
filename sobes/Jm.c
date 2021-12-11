#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int n;
    int a[250000];
};

void stack_create(struct Stack * s)
{
    s->n = 0;
}

void stack_push(struct Stack * s, int x)
{
    s->a[s->n] = x;
    s->n++;
}

int stack_pop(struct Stack * s)
{
    s->n--;
    return s->a[s->n];
}

int stack_get(struct Stack * s)
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
	const char *brackets = "([{<)]}>"; // массив скобок
	char bracket; // полученная скобка
	char * p;

	stack_create(&s);

	while ((bracket = getchar()) != EOF)
	{
		if ((p = strchr(brackets, bracket)) == NULL)
			continue;

		if (!(((int)(p - brackets)) / 4))
			stack_push(&s, ((int)(p - brackets)) % 4);
		else
		{
			if (!stack_size(&s))
			{
				printf("NO");
				stack_clear(&s);
				return 0;
			}

			if ((((int)(p - brackets)) % 4) != stack_pop(&s))
			{
				printf("NO");
				stack_clear(&s);
				return 0;
			}
		}
	}

    if (!stack_size(&s))
        printf("YES");
    else
        printf("NO");

    stack_clear(&s);
    return 0;
}
