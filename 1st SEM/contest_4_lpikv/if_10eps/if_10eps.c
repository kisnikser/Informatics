#include <stdio.h>
#include <math.h>

int main ()
{
    float a, b;         // Длины
    float eps = 0.5;    // Точность

    // Получить a и  b из консоли
    scanf ("%f%f", &a, &b);
    
    // Сравнить |a - b| c eps  и 
    // напечатать YES, если ПОЧТИ РАВНЫ
    // напечатать NO, если не равны 
    // |a - b| = fabs(a - b)
    if ( fabs(a-b) <= eps )
        printf ("YES\n");
    else
        printf ("NO\n");
        
    return 0;
}
