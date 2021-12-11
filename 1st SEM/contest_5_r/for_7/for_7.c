#include <stdio.h>
#include <stdlib.h>

long long NOD(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return NOD(b, a % b);
}

void sort(long long* a, long long* b)
{
	if (*a < *b)
	{
		long long tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

int main()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	sort(&a, &b);
	printf("%lld %lld", NOD(a, b), a * b / NOD(a, b));	
}
