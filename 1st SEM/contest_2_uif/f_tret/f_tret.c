#include <stdio.h>

void oneTr(float* x1, float* x2)
{
	float fx0 = (*x1 + *x2)/2;
	float fx1 = *x1;
	float fx2 = *x2;
	int sr = fx2>fx1;
	float dist = sr*(fx2 - fx1) + !sr*(fx1 - fx2);
	*x1 = fx0 - dist/6;
	*x2 = fx0 + dist/6;
}

int main()
{
	float x1, x2;
	scanf("%f%f", &x1, &x2);
	oneTr(&x1, &x2);
	printf("%f %f", x1, x2);
}
