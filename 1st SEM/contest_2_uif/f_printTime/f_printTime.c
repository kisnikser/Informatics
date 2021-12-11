#include <stdio.h>

void printLocalTime(int hMos, int h, int hplane)
{
	int sr = hMos<(h+hplane);
	printf("%d %d", (24 + hMos - h + hplane)%24, 5 + !sr*(hMos - h + hplane)/24-sr*(1+(h + hplane - hMos)/24));
}

int main()
{
	int hMos, h, hplane;
	scanf("%d%d%d", &hMos, &h, &hplane);
	printLocalTime(hMos, h, hplane);	
}
