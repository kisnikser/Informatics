#include <stdio.h>

struct Info
{
	int timestamp;
	int id;
	int recept_id;
};

struct Info GetInfo()
{
	struct Info man;
	scanf("%d%d%d", &man.timestamp, &man.id, &man.recept_id);
	return man;
}

int main()
{
	int a[10000] = {0}, n, i, count = 0, idmax = 0, idmin = 10000;
		
	scanf("%d", &n);
	
	struct Info recept[10000] = {0};
	
	for (i = 0; i < n; i++)
	{
		recept[i] = GetInfo();
		a[recept[i].id]++;
		if (recept[i].id > idmax)
			idmax = recept[i].id;
		if (recept[i].id < idmin)
			idmin = recept[i].id;
	}
	
	for (i = idmin; i <= idmax; i++)
		if (a[i] != 0)
			count ++;
	
	printf("%d", count);
	
	return 0;
}
