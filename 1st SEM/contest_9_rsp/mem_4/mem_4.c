#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int* str = (int*)calloc(1000, sizeof(int));
    int x;
    int i = 1;

    while(scanf("%d", &x) != EOF)
    {
        str[i] = x;
        i++;
    }
    
    int n = i - 1;
    
    for (i = n; i >= 1; i--)
    {
        printf("%d ", str[i]);
    }
    
    free(str);
    
    return 0;;	
}
