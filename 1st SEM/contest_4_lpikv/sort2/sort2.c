#include <stdio.h>

void sort2(int* a, int* b)
{
	if (*a > *b)
		{
			int tmp = *b;
			*b = *a;
			*a = tmp;
		}
}

int main() 
{
    int x, y;
    
    scanf("%d%d", &x, &y);
    sort2(&x, &y);
    printf("%d %d\n", x, y);
    
    return 0;
}
