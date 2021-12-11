#include <stdio.h>

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int N, i;
    int a[50000], b[50000], c[50000];
    int queue[50000] = {0}; // массив с временем очереди

    scanf("%d", &N);

    for (i = 0; i < N; i++)
        scanf("%d %d %d", &a[i], &b[i], &c[i]);

    queue[0] = a[0]; // минимальное время для очереди из одного человека - время покупки им одного телефона

    if (N >= 2)
        queue[1] = min(b[0], queue[0] + a[1]);

    if (N >= 3)
        queue[2] = min(c[0], min(queue[0] + b[1], queue[1] + a[2]));

    for (i = 3; i < N; i++)
        queue[i] = min(queue[i - 3] + c[i - 2], min(queue[i - 2] + b[i - 1], queue[i - 1] + a[i]));

    printf("%d", queue[N - 1]);

    return 0;
}
