#include <stdio.h>
#include <stdlib.h>

// Функция обхода в глубину
// На вход подаются массив кабелей, массив пройденных вершин и две вершины:
// одна для проверки, вторая - прямой предок
void dfs(int (*cabel)[100], int * used, int N, int v, int p)
{
    used[v] = 1;

    for (int i = 0; i < N; i++)
    {
        if (cabel[v][i])
        {
            if (!used[i])
                dfs(cabel, used, N, i, v);
            else if (i != p)
            {
                printf("1");
                exit(1);
            }
        }
    }
}

int main()
{
    int N; // количество вершин в графе
    int v1, v2, s; // переменные для ввода записей о кабелях
    int cabel[100][100]; // массив кабелей
    int * used = calloc(100, sizeof(int)); // массив пройденных вершин
    int i, j; // счетчики

    for (i = 0; i < 100; i++) // обнуляем массив кабелей
        for (j = 0; j < 100; j++)
            cabel[i][j] = 0;

    scanf("%d", &N);

    while (scanf("%d %d %d", &v1, &v2, &s) != EOF)
    {
        if (!s) // если скорость кабеля 0, то не учитываем его
            continue;

        cabel[v1][v2] = 1; // есть связь между
        cabel[v2][v1] = 1; // v1 и v2 вершинами
    }

    /*for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%d", cabel[i][j]);
        printf("\n");
    }*/


    for (i = 0; i < N; i++)
    {
        if (!used[i])
            dfs(cabel, used, N, i, -1);
    }

    printf("0");
    free(used);

    return 0;
}
