#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	unsigned long long a, b;
	
	scanf("%lld%lld", &a, &b);
	
	int z, i = 0, j = 0, flag = 0;
	
	while (flag != 1)
	{
		i++;
		if (a < (int)(pow(2, i)))
			flag = 1;
	}
	
	while (flag != 1)
	{
		j++;
		if (b < (int)(pow(2, j)))
			flag = 1;
	}
	
	int max, count;
	
	if (i >= j)
	{
		max = i;
		count = i - j;	
	}
	else
	{
		max = j;
		count = j - i;	
	}	
	
	unsigned long long* aarray = (unsigned long long*)calloc(max, sizeof(unsigned long long));
	unsigned long long* barray = (unsigned long long*)calloc(max, sizeof(unsigned long long));
	
	if (i >= j)
		for (z = max; z > 0; z--)
		{
			aarray[z] = a % 2;
			a /= 2;
			barray[z - count] = b % 2;
			b /= 2;
		}
	else
		for (z = max; z > 0; z--)
		{
			aarray[z - count] = a % 2;
			a /= 2;
			barray[z] = b % 2;
			b /= 2;
		}
	
	int k = 0;
	
	for (z = 1; z <= max; z++)
	{
		if (aarray[z] != barray[z])
			k++;
	}

	printf("%d", count + k);

	return 0;
}
