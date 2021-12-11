#include <stdio.h>

int main()
{
	int price, delta, money, day = 1, days = 0;
	scanf("%d%d%d", &price, &delta, &money);
	while (money >= price)
	{
		day ++;
		days ++;
		money -= price;
		if (day == 8)
		{
			day = 1;
			price += delta;
		}
	}
	printf("%d", days);
}
