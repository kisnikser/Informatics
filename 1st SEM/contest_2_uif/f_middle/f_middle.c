#include <stdio.h>

void toMiddle(int* x1, int* x2, int middle)
{
	float fx1 = *x1 + middle - ((float)(*x1 + *x2))/2;
	float fx2 = *x2 + middle - ((float)(*x1 + *x2))/2;
	int sr1 = fx1<0;
	int sr2 = fx2<0;
	*x1 = (int)(sr1*(fx1)+!sr1*(fx1 + 0.5));
	*x2 = (int)(sr2*(fx2)+!sr2*(fx2 + 0.5));
	printf("%d %d", *x1, *x2); 	
}

int main()
{
	int x1, x2, middle;
	scanf("%d%d%d", &x1, &x2, &middle);
	toMiddle(&x1, &x2, middle);
}
