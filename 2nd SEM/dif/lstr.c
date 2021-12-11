#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 1. хранить
// 2. печатать
// 3. складывать ?? (правильно)
// 4. вычитать ?? (правильно_
// 5. умножать

// 27895647
// 01....
int main()
{
    char s1[101];
    char s2[101];
    char res[101] = {0};
    char buf[101] = {0};
    char *p1 = 0, * p2 = 0 ;
    scanf("%s", s1);
    scanf("%s", s2);
    int i, p = 0, sum1 = 0, sum2 = 0, sum = 0;
    int len1, len2;
    int int1, int2;
    p1 = s1;
    p2 = s2;

    len1 = strlen(p1);
    len2 = strlen(p2);
    p1 = (len1 > 5) ? p1 + len1 - 5 : p1;
    p2 = (len2 > 5) ? p2 + len2 - 5 : p2;
    printf("%s %d\n%s %d\n", p1, len1, p2, len2);
    sscanf(p1, "%d", &int1);
    sscanf(p2, "%d", &int2);
    sum1 = (int1 + int2 + p) % 100000;
    p = (int1 + int2) / 100000;
    printf("sum1: %d p: %d\n", sum1, p);
    p1[0] = '\0';
    p2[0] = '\0';
    sprintf(buf, "%d", sum1);
    strcat(buf, res);
    strcpy(res, buf);
    p1 = s1;
    p2 = s2;
    len1 = strlen(p1);
    len2 = strlen(p2);
    p1 = (len1 > 5) ? p1 + len1 - 5 : p1;
    p2 = (len2 > 5) ? p2 + len2 - 5 : p2;
    printf("%s %d\n%s %d\n", p1, len1, p2, len2);

    int1 = 0;
    int2 = 0;
    sscanf(p1, "%d", &int1);
    sscanf(p2, "%d", &int2);

    sum2 = (int1 + int2 + p) % 100000;
    p = (int1 + int2 + p) / 100000;
    printf("sum2: %d p: %d\n", sum2, p);
    sprintf(buf, "%d", sum2);
    strcat(buf, res);
    strcpy(res, buf);
    printf("%s", res);
}
