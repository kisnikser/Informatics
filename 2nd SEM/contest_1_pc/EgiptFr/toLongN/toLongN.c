#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
// a[0] * 100^0 + a[1] * 100^1 + .. + a[n - 1] * 100^(n-1)
	int n; 			// размер числа в разрядах
	char sign;	// знак числа
	char dig[0];	// массив для хранения "цифр" числа (одна точно есть):
}LongN;

// Функция преобразует цифры, записанные строкой символов в
// "длинное число" в формате описанной выше структуры
// и возвращает указатель на переменную в динамической области памяти
LongN *  getLongN(char * s)
{
    LongN* tmp = 0;
    tmp = calloc(1, (sizeof (LongN) + 100 * sizeof(char)));

    int i, len;
    char* p = s;

    if (s[0] == '\0')
    {
        tmp->n = 1;
        return tmp;
    }

    if ((s[0] == '+') || (s[0] == '-'))
    {
        if (s[0] == '-')
            tmp->sign = 1;
        s[0] == '\0';
        s++;
    }

    len = strlen(s);
    tmp->n = ( len + 1 ) / 2;

    for (i = 0; i < tmp->n; i++)
    {
        len = strlen(s);
        p = (len > 1) ? s + len - 2 : s;
        sscanf(p, "%hhd", &(tmp->dig[i]));
        p[0] = '\0';
    }

    return tmp;
}

// Функция для получения копии данного числа.
// Должна быть получена другая переменная с той же информацией, что и исходная
LongN * copyLN(const LongN *b)
{
    LongN* a = calloc(1, sizeof (LongN) + (b->n) * sizeof(char) + 1);

    memcpy(a, b, sizeof (LongN) + (b->n) * sizeof(char));

    return a;
}

// Функция печати числа: первым печатается знак числа, далее через пробел
// "цифры" числа: + 34 56 11 или - 1 22 30
void showDigit(const LongN *a)
{
    int i;

    if (a->sign)
        printf("- ");
    else
        printf("+ ");

    for (i = (a->n) - 1; i > -1; i--)
        printf("%d ", a->dig[i]);

    printf("\n");
}


// Функция освобождения памяти, выделенной для хранения числа
void destroyLN(LongN * a)
{
    free(a);
}

int main()
{
    LongN *a = 0, *b = 0, *c = 0, * cp = 0;
	char s[201];

	scanf("%s", s);

	a = getLongN(s);

	scanf("%s", s);

	b = getLongN(s);

	showDigit(a);
	showDigit(b);

	cp = copyLN(a);
	showDigit(cp);
    
	destroyLN(a);
	destroyLN(b);
	destroyLN(c);
	destroyLN(cp);
	return 0;
}
