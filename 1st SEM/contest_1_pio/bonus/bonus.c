#include <stdio.h>

int main()
	{
	int L, Z, Dn, D, M, B, money, prem;
	scanf("%d%d%d%d%d%d", &L, &Z, &Dn, &D, &M, &B);
	prem = L*Dn<=D*Z;
	money = M*L + prem*B;
	printf("%d", money);
	}
