#include <stdio.h>

typedef struct
{
	float coord; // начальная координата точки
	float v0; // начальная скорость точки
	float a;  // ускорение точки
	float m; // масса точки
}MassPoint;

// получает параметры точки с консоли (три дробных числа, записанных через пробел)
MassPoint getParam()
{
	MassPoint m;
	scanf("%f %f %f %f", &m.m, &m.coord, &m.v0, &m.a);
	return m;
}

// вычисляет новые значения параметров точки в момент времени time 
// и возвращает новую координату точки
float move(MassPoint* m, int time)
{
	m->coord += m->v0 * time + m->a * time * time / 2;
	m->v0 += m->a * time;
	return m->coord;
}

// возвращает координату точки m2 относительно m1 и изменяет значения параметров точек
// точки не сталкиваются. Они "проплывают" мимо друг друга 
float pointByPoint(MassPoint *m1, MassPoint *m2, int time)
{
	move(m1, time);
	move(m2, time);
	return m2->coord - m1->coord;
}

// печать параметров точки с точностью до 2 знаков после запятой в формате
// масса,координта,скорость,ускорение (через запятую без пробелов) c переносом строки 
// пример: 0.10,25.20,-15.5,0.30
void printM(MassPoint a)
{
	printf("%.2f,%.2f,%.2f,%.2f\n", a.m, a.coord, a.v0, a.a);
}

int main()
{
	MassPoint m1, m2;
	int time;

	m1 = getParam();
	m2 = getParam();
	
	scanf("%d", &time);
	
	printM(m1);
	printM(m2);

	printf("%.2f\n", pointByPoint(&m1, &m2, time));
	
	printM(m1);
	printM(m2);
	
	return 0;
}
