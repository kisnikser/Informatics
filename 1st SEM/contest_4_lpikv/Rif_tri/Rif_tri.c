#include <stdio.h>

struct Triangle 
{
    int a;      // длины сторон треугольника
    int b;
    int c;
};

int correctTriangle(struct Triangle t)
{
	return (t.a < t.b + t.c && t.b < t.a + t.c && t.c < t.a + t.b) ? 1 : 0;
}

int main() 
{
    struct Triangle tr;
    
    scanf("%d%d%d", &tr.a, &tr.b, &tr.c);
    printf("%s\n", correctTriangle(tr) ? "YES" : "NO");
    
    return 0;
}
