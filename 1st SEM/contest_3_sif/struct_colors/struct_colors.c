#include <stdio.h>

typedef struct
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
}Color;

// считать RGB-формат с консоли
Color getColor()
{
	Color c;
	scanf("%hhd %hhd %hhd", &c.red, &c.green, &c.blue);
	return c;
}

// перевод из RGB-формата в число
unsigned long long convertToHTML(Color c)
{
	return c.blue + c.green * 256 + c.red * 256 * 256;
}

// преобразование числа цвета в RGB-формат
Color convertToRGB(unsigned long long c)
{
	Color tmp;
	tmp.red = c / (256 * 256);
	tmp.green = (c - tmp.red * 256 * 256) / 256;
	tmp.blue = c % 256;
	return tmp;
}

// печать цвета в RGB-формате (печать значений в десятичном виде через пробел)
// red green blue: 
// 255 128 222
// Печатать только числа!!
void printRGB(Color c)
{
	printf("%d %d %d\n", c.red, c.green, c.blue);
}

// печать цвета в HTML-формате. 
// Примеры: FFA902 0AA3FF
void printHTML(Color c)
{
	printf("%06llX\n", convertToHTML(c));
}

int main()
{
	Color z, z2;
	unsigned long long html;
	z = getColor();
	printRGB(z);
	html = convertToHTML(z);
	printf("%llu\n", html);
	printHTML(z);
	z2 = convertToRGB(html);
	printRGB(z2);
	return 0;
}

