#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int hh;
	int mm;
}Time;

Time TimePlusMin(Time* a, int min)
{
	a->mm += min;
	a->hh += a->mm / 60;
	a->mm %= 60;
}

Time TimePlusTime(Time* a, Time b)
{
	a->mm += b.mm;
	a->hh += a->mm / 60;
	a->mm %= 60;
	a->hh += b.hh;
	a->hh %= 12;
}

Time TimeMinusTime(Time* a, Time b)
{
	a->hh -= 1;
	a->mm += 60;
	a->mm -= b.mm;
	a->hh = (12 + a->hh - b.hh) % 12;
}

int IsEqualTime(Time a, Time b)
{
	if (a.hh == b.hh && a.mm == b.mm)
		return 1;
	else
		return 0;
}

void TimeScan(Time* a)
{
	scanf("%d:%d", a.hh, a.mm);
}

void TimePrint(Time a)
{
	printf("%d:%d", a.hh, a.mm);
}

int main()
{
	Time byax, myax, byax_f, myax_b, global, razn;
	int days = 0, nb, nm, flag;
	
	TimeScan(&byax);
	scanf("%d", &nb);
	TimeScan(&byax_f);
	
	TimeScan(&myax);
	scanf("%d", &nm);
	TimeScan(&myax_b);
	
	global.hh = 0;
	global.mm = 0;
	
	razn = myax;
	TimeMinusTime(&razn, byax)
	
	if (razn.mm + 60 * razn.hh % (byax_f.mm + 60 * byax_f.hh + myax_b.mm + 60 * myax_b.hh) != 0)
		printf("NO");
	else
	{
		for (i = 0; i < (razn.mm + 60 * razn.hh % (byax_f.mm + 60 * byax_f.hh) + 1); i++)
		{
			for (j = 0; j < (razn.mm + 60 * razn.hh % (myax_b.mm + 60 * myax_b.hh) + 1); j++)
			{
			
			}
		}
	}
	return 0;
}
