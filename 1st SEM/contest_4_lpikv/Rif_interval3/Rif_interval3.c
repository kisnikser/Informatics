#include <stdio.h>

// описание интервала времени
typedef struct
{
	int frst; // начало интервала 
	int scnd; // конец интервала
}TimeInterval;

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

// функция, определяющее временной интервал,
// являющийся объединением двух интервалов
// Если объединение интервалов пусто, то 
// атрибуты возвращаемого интервала принимают значение -1
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

int main()
{
	TimeInterval time1, time2, crosstime;
	
	getInterval(&time1);
	getInterval(&time2);
	
	sortInterval(&time1);
	sortInterval(&time2);
	
	crosstime = Cross(time1, time2);
	
	(crosstime.frst == 0 && crosstime.scnd == 0) ? printf("-1") : printf("%d %d", crosstime.frst, crosstime.scnd);
}
