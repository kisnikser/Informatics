#include <stdio.h>

// описание интервала времени
typedef struct
{
	int frst; // начало интервала 
	int scnd; // конец интервала
}TimeInterval;

// Два интервала (для разности)
typedef struct 
{
	TimeInterval lin1, lin2;
	int n;
} ParaIntervals;

// функция получения данных интервала с консоли
void getInterval(TimeInterval* tmp)
{
	scanf("%d %d", &tmp->frst, &tmp->scnd);
}

// функция печати интервала
void printInterval(TimeInterval tmp)
{
	printf("%d %d", tmp.frst, tmp.scnd);
}

void sortInterval(TimeInterval* tmp)
{
	if (tmp->frst > tmp->scnd)
		{
			int point = tmp->scnd;
			tmp->scnd = tmp->frst;
			tmp->frst = point;
		}
}

TimeInterval Cross(TimeInterval a, TimeInterval b)
{
	TimeInterval crosstime;
	if (a.scnd < b.frst)
		{
			crosstime.frst = 0;
			crosstime.scnd = 0;
		}
	else if (a.frst >= b.frst && a.scnd <= b.scnd)
		{
			crosstime.frst = a.frst;
			crosstime.scnd = a.scnd;
		}
	else if (a.frst <= b.frst && a.scnd >= b.scnd)
		{
			crosstime.frst = b.frst;
			crosstime.scnd = b.scnd;
		}
	else if (a.frst <= b.frst && a.scnd <= b.scnd)
		{
			crosstime.frst = b.frst;
			crosstime.scnd = a.scnd;
		}
	else if (b.frst <= a.frst && b.scnd <= b.scnd)
		{
			crosstime.frst = a.frst;
			crosstime.scnd = b.scnd;
		}
	return crosstime;
}

// функция, определяющее временные интервалы,
// являющийся разностью двух интервалов
// Если пересечение интервалов пусто, то 
// атрибуты возвращаемого интервала принимают значение -1
ParaIntervals intervalMinus(TimeInterval a, TimeInterval b)
{
	ParaIntervals diff;
	if (b.frst == 0 && b.scnd == 0)
		{
			diff.n = 1;
			diff.lin1.frst = a.frst;
			diff.lin1.scnd = a.scnd;
		}
	else if (a.frst == b.frst && a.scnd == b.scnd)
		{
			diff.n = 0;
			diff.lin1.frst = 0;
			diff.lin1.scnd = 0;
		}
	else if (b.frst == a.frst && b.scnd < a.scnd)
		{
			diff.n = 1;
			diff.lin1.frst = b.scnd;
			diff.lin1.scnd = a.scnd;
		}
	else if (b.frst > a.frst && b.scnd == a.scnd)
		{
			diff.n = 1;
			diff.lin1.frst = a.frst;
			diff.lin1.scnd = b.frst;
		}
	else if (b.frst > a.frst && b.scnd < a.scnd)
		{
			diff.n = 2;
			diff.lin1.frst = a.frst;
			diff.lin1.scnd = b.frst;
			diff.lin2.frst = b.scnd;
			diff.lin2.scnd = a.scnd;
		}
	return diff;
}

int main()
{
	TimeInterval time1, time2, crosstime;
	ParaIntervals diff;
	
	getInterval(&time1);
	getInterval(&time2);
	
	sortInterval(&time1);
	sortInterval(&time2);
	
	crosstime = Cross(time1, time2);
	
	diff = intervalMinus(time1, crosstime);
	
	if (diff.n == 0)
		printf("-1");
	if (diff.n == 1)
		printf("%d %d", diff.lin1.frst, diff.lin1.scnd);
	if (diff.n == 2)
		printf("%d %d %d %d", diff.lin1.frst, diff.lin1.scnd, diff.lin2.frst, diff.lin2.scnd);
	return 0;
}
