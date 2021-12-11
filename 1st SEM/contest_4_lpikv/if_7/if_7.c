#include <stdio.h>

typedef struct 
{
	int l; // number of line
	int c; // number of column
}Point;

int main()
{
	Point lad, fig;
	scanf("%d %d %d %d", &lad.l, &lad.c, &fig.l, &fig.c);
	(lad.l == fig.l || lad.c == fig.c) ? printf("YES") : printf("NO");
}
