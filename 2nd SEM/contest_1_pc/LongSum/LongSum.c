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
    LongN* a = calloc(1, sizeof (LongN) + (b->n - 1) * sizeof(char));

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

// Представление отрицательных чисел в обратном коде
// Функция возвращает указатель на новую динамически выделенную
// переменную
LongN * invertLN(const LongN *a, int n)
{
    int i;
    LongN* tmp = 0;
    tmp = calloc(1, (sizeof (LongN) + (n - 1) * sizeof(char)));

    tmp->sign = a->sign;
    tmp->n = n;

    if (tmp->sign)
        for (i = 0; i < n; i++)
        {
            tmp->dig[i] = 99 - a->dig[i];
        }
    else
        for (i = 0; i < n; i++)
        {
            tmp->dig[i] = a->dig[i];
        }

    return tmp;
}

// Вычисление суммы двух длинных чисел.
// Функция должна вычислять сумму двух положительных чисел, двух отрицательных
// чисел и двух чисел с разными знаками.
// Для операций с отрицательными числами использовать обратный код числа.
LongN * sumLN(const LongN *a, const LongN *b)
{
    int i, p = 0, flag = 0;
    LongN* tmp = 0;
    LongN* atmp = 0;
    LongN* btmp = 0;

    int nmax = (a->n > b->n)? a->n : b->n;

    tmp = calloc(1, (sizeof (LongN) + nmax * sizeof(char)));
    tmp->n = nmax;

    atmp = invertLN(a, nmax);
    btmp = invertLN(b, nmax);

    for (i = 0; i < nmax; i++)
    {
        tmp->dig[i] = (atmp->dig[i] + btmp->dig[i] + p) % 100;
        p = (atmp->dig[i] + btmp->dig[i] + p) / 100;
    }

    if ((!atmp->sign) && (!btmp->sign))
    {
        tmp->dig[nmax] = (p) ? 1 : 0;
        tmp->n++;
    }
    else
    {
        tmp->sign = (atmp->sign + btmp->sign + p) % 2;
        p = (atmp->sign + btmp->sign + p) / 2;
        tmp->dig[0] += p;
    }

    tmp = invertLN(tmp, tmp->n);

    if (!tmp->dig[tmp->n - 1] && (tmp->n > 1))
        (tmp->n)--;

    for (i = 0; i < tmp->n; i++)
        if (tmp->dig[i])
            flag++;

    if (!flag)
        tmp->sign = 0;

    return tmp;
}

int main()
{
    LongN *a = 0, *b = 0, *c = 0;
	char s[201];

	scanf("%s", s);

	a = getLongN(s);

	scanf("%s", s);

	b = getLongN(s);

    c = div2LN(a, b);
    showDigit(c);

	destroyLN(a);
	destroyLN(b);
	destroyLN(c);
	return 0;
}
