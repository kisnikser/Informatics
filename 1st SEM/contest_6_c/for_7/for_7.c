#include <stdio.h>
#include <stdlib.h>

long long sort(long long* a, long long* b)
{
	if (a < b)
	{
		long long tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

int main()
{
	long long a, b, tmpa, tmpb, NOD, NOK;
	
	scanf("%lld%lld", &a, &b);
	
	sort(&a, &b);
	
	tmpa = a;
	tmpb = b;
	
	while (tmpa > 0 && tmpb > 0)
	{
		tmpa %= tmpb;
		sort(&tmpa, &tmpb);
	}
	
	if (tmpa == 0)
		NOD = tmpb;
	else
		NOD = tmpa;
	
	NOK = a * b / NOD;
	
	printf("%lld %lld", NOD, NOK);
	
	return 0;
}
