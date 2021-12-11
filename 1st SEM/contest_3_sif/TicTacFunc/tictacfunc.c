#include <stdio.h>

typedef struct
{ 
	int h; // часы 
	int min; // минуты (от 0 до 59)
} TicTac;

void ScanTicTac(TicTac* a)
{
	scanf("%d %d", &(a->h), &(a->min));
}

void ScanMin(int* min)
{
	scanf("%d", &(*min));
}

// получает показание часов a и возвращает показание этих часов 
// через min минут, .
TicTac after(TicTac a, int min)
{
	a.min += min;
	a.h += a.min / 60;
	a.min %= 60;
	a.h %= 12;
	return a;
}

// "переводит" вперед стрелки этих часов (me) 
// на a.h часов и a.min минут 
void forward(TicTac* me, TicTac a)
{
	me->min += a.h * 60 + a.min;
	me->h += (me->min) / 60;
	me->min %= 60;
	me->h %= 12;		
}

// "переводит" назад стрелки этих часов (me) 
// на a.h часов и a.min минут 
void backward(TicTac* me, TicTac a)
{
	TicTac tmp;
	
	tmp.h = me->h;
	tmp.min = me->min;
	
	me->h = ((12 * 60 + tmp.h * 60 + tmp.min - a.h * 60 - a.min) % (12*60)) / 60;
	me->min = (12 * 60 + tmp.h * 60 + tmp.min - a.h * 60 - a.min) % 60;
}

// проверяет совпадают ли показания часов a и b
// если совпадают, возвращает 1, если нет - 0
int isEqualTime(TicTac a, TicTac b)
{
	int equal_h = a.h == b.h;
	int equal_min = a.min == b.min;
	return equal_h * equal_min;
}

// печатает показания этих часов в формате hh:mm\n
void printTic(TicTac a)
{
	printf("%02d:%02d\n", a.h, a.min);
}

int main()
{
	TicTac left, right;
	int min;
	
	ScanTicTac(&left);
	ScanTicTac(&right);
	ScanMin(&min);	
	
	printf("%d\n", isEqualTime(left, right));
	
	printTic(after(left, min));
	
	forward(&left, right);
	
	printTic(left);
	
	backward(&right, left);
	
	printTic(right);
}
