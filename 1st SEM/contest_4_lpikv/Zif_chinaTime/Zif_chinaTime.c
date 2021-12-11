#include <stdio.h>

int main()
{
	int h, m;
	scanf("%d %d", &h, &m);
	if (h * 60 + m >= 1420 || h * 60 + m <= 100)
		printf("Мышь");
	if (h * 60 + m >= 101 && h * 60 + m <= 234)
		printf("Бык");
	if (h * 60 + m >= 235 && h * 60 + m <= 314)
		printf("Тигр");
	if (h * 60 + m >= 315 && h * 60 + m <= 460)
		printf("Заяц");
	if (h * 60 + m >= 461 && h * 60 + m <= 590)
		printf("Дракон");
	if (h * 60 + m >= 591 && h * 60 + m <= 680)
		printf("Змея");
	if (h * 60 + m >= 681 && h * 60 + m <= 824)
		printf("Лошадь");
	if (h * 60 + m >= 825 && h * 60 + m <= 940)
		printf("Коза");
	if (h * 60 + m >= 941 && h * 60 + m <= 1060)
		printf("Обезьяна");
	if (h * 60 + m >= 1061 && h * 60 + m <= 1180)
		printf("Петух");
	if (h * 60 + m >= 1141 && h * 60 + m <= 1300)
		printf("Собака");
	if (h * 60 + m >= 1301 && h * 60 + m <= 1419)
		printf("Кабан");
	}
