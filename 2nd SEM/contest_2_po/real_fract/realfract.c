#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int NOD(int a, int b) {
  while (a != b) {
    if (a > b)
      a -= b;
    else
      b -= a;
  }
  return a;
}

int main() {
  float a;
  int i = 0; // экспонента
  int k = 0; // количество цифр в мантисе
  int l = 0; // перевод мантисы в десятичное
  int j = 0; // для перевода в десятич
  int p = 0; // счетчик для массива
  scanf("%f", &a);
  int b = (int)(a);
  a = a - b;
  if (a == 0) {
    printf("%d(0/1)", b);
    return 0;
  }
  int *m = (int *)calloc(24, sizeof(int));
  while (fabs(a - 1) >= 0.001 && a < 1) {
    a = a * 2;
    i++;
  }
  while (fabs(a - 1) >= 0.001) {
    if (a < 1) {
      m[p] = 0;
      a = a * 2;
      k++;
      p++;
    }
    if (a > 1) {
      m[p] = 1;
      a = a - 1;
      a = a * 2;
      k++;
      p++;
    }
  }
  m[p] = 1;
  for (int r = p; r > -1; r--) {
    l = m[r] * (int)(pow(2, j)) + l;
    j++;
  }

  int y = NOD(l, (int)(pow(2, k + i)));
  printf("%d(%d/%d)\n", b, l / y, (int)(pow(2, k + i)) / y);
  free(m);
  return 0;
}
