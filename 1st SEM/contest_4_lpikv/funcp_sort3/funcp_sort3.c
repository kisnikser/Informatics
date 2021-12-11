#include <stdio.h>

void sort3(int* a, int* b, int* c)
{
	int x = *a;
	int y = *b;
	int z = *c;
	if (x < y)
		if (x < z)
			if (z < y)
				{
					*a = x;
					*b = z;
					*c = y;
				}
			else
				{
					*a = x;
					*b = y;
					*c = z;
				}
		else 
			{
				*a = z;
				*b = x;
				*c = y;
			}
	else 
		if (x > z)
			if (y > z)
				{
					*a = z;
					*b = y;
					*c = x;
				}
			else 
				{
					*a = y;
					*b = z;
					*c = x;
				}
		else
			{
				*a = y;
				*b = x;
				*c = z;
			}
}

int main() 
{
    int x, y, z;
    
    scanf("%d%d%d", &x, &y, &z);
    sort3(&x, &y, &z);
    printf("%d %d %d\n", x, y, z);
    
    return 0;
}        
