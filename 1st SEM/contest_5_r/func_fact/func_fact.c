#include <stdio.h>

int fact(int n);

int main()
{
	int n;   
	int res; 
	scanf("%d", &n);
	res = fact(n);
	printf("%d\n", res);
	return 0;
}

// Реализация функции fact
int fact(int n)
{   
	int res;
	if (n <=1) 
		return 1;
	res = n * fact(n-1);
	return res;
}
