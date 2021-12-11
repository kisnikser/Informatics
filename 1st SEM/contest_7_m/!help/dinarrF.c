#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #### array:  1 | 2 | 10 | 33 | -7 |######
//              0   1    2   3     4
// a->
typedef int ** D2Arr;

D2Arr createD2Arr(int n, int m)
{
//	printf("create\n");
	D2Arr darr = calloc(1,  n * m * sizeof(int) + n * sizeof( int *) );
	int * arr = (int *) (darr + n);
	for (int i = 0; i < n ; i++)
		darr[i] = arr + i * m;
//	printf("from create\n");
	return darr;
};

void destroyD2Arr(D2Arr a)
{
	free( a );
}

void printD2Arr(D2Arr a, int n, int m)
{
//	printf("print\n");
	for ( int y = 0; y < n; y++)
	{
		for ( int x = 0 ; x < m; x ++)
			printf("%d ",  a[y][x] );
		printf("\n"); 
	}
//	printf("print_ ok\n");	
}
// 3 3 
// 1 2 3 4 5 6 7 8 9
D2Arr  getD2Arr(int *n, int *m)
{
	printf("get\n");
	scanf("%d%d", n, m);
	D2Arr ar = createD2Arr(*n, *m);
	printf("ar: %p\n", ar);
	int *p  = (int *)(ar + ( * n) );
	printf("p: %p\n", p);
	for (int i = 0; i < ( * n) * ( * m); i ++){
		
		scanf("%d", p + i);
	}

	printf("get_ ok\n");
	return ar;
}

D2Arr  getD2ArrAll(int *n, int *m)
{
	printf("get\n");
	FILE *fin = fopen ("d.dat", "rb");
	fscanf(fin, "%d%d", &n, &m);
	int ret = fread(z, sizeof(unsigned char) * n * m, 1, fin);
	
	return ar;
}

int main()
{
	int n, m;
	D2Arr darr =  getD2Arr(&n, &m) ;
	printD2Arr(darr, n, m);
	destroyD2Arr(darr);
	return 0;
}

