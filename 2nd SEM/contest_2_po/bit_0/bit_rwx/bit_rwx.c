#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, check = 7;
    char* rwx[8] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};

    scanf("%o", &N);

    printf("%s%s%s", rwx[(N & (check << 6)) >> 6], rwx[(N & (check << 3)) >> 3], rwx[N & check]);

    return 0;
}
