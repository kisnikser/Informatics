#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){	
	int n, m;
	unsigned char * z = calloc( 1024, sizeof(char));
	FILE *fin = fopen ("d.dat", "rb");
	fscanf(fin, "%d%d", &n, &m);

	int ret = fread(z, sizeof(unsigned char) * n * m, 1, fin);

	printf("ret: %d %d %d %s\n", ret, n, m, z);
}
