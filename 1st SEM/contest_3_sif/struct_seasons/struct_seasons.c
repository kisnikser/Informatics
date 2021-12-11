#include <stdio.h>

typedef struct
{
	int yy; // год
	char mm; // месяц
	char dd; // день
}Data;

typedef struct
{
	int yy; // год
	char season; // время года (зима - 0, весна - 1, лето - 2, осень - 3)
	int day; // день от начала текущего времени года
}Season;

int DIM(Data date, int n)
{
	int srfeb = n == 2;
	int sr29 = date.yy % 4 == 0;
	int sr30 = ( n == 4 ) || ( n == 6 ) || ( n == 9 ) || ( n == 11 );
	int sr31 = !(srfeb + sr30);
	return srfeb * (!sr29 * 28 + sr29 * 29) + sr30 * 30 + sr31 * 31;
}

// получает параметры даты с консоли (три целых числа через тире:
// YYYY-MM-DD)
// Например, 2020-12-13
Data getData()
{
	Data tmp;
	scanf("%d-%hhd-%hhd", &tmp.yy, &tmp.mm, &tmp.dd);
	return tmp;
}

// Печатает дату в формате: YYYY-MM-DD завершая переносом строки (\n)
void printData(Data date)
{
	printf("%04d-%02hhd-%02hhd\n", date.yy, date.mm, date.dd);
}

// конвертирует дату в формат Season и возвращает это значение
// зима с 1 декабря по конец февраля, весна - с 1 марта по 31 мая, лето - с 1 июня по 31 августа, 
// осень - с 1 сентября по 30 ноября
Season convToSeas(Data date)
{
	Season ssn;
	ssn.yy = date.yy;
	ssn.season = (date.mm / 3) % 4;
	int k = (date.mm - ssn.season * 3);
	int srdec = date.mm == 12;
	int sr1 = k>0;
	int sr2 = k>1;
	int d1 = date.mm - 1;
	int d2 = date.mm - 2;
	ssn.day = date.dd + !srdec * (sr1 * (DIM(date, d1) + sr2 * DIM(date, d2)));
	return ssn;
}

//  печать времени года в формате: YYYY-SS-DD (SS - номер времени года, 
// DD - день от начала времени года, завершая переносом строки
void printS(Season ssn)
{
	printf("%04d-%02hhd-%02hhd\n", ssn.yy, ssn.season, ssn.day);
}

int main()
{
	Data dat;
	Season seas;
	dat = getData();
	printData(dat);
	seas = convToSeas(dat);
	printS(seas);

	return 0;
}
