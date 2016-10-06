#include <stdio.h>

double const eps = 1.0e-5;

int main() {
  double spring_constants[3];
  double naturals[3];
  double xs[3], ys[3];
  int i;
  for(i = 0; i < 3; ++i) {
    printf("ばね%d:\n", i);
    printf("ばね定数?:\n");
    scanf("%e",  spring_constants + i * sizeof(double));
    printf("自然長?:\n");
    scanf("%e",  naturals + i * sizeof(double));
    printf("X座標?:\n");
    scanf("%e",  xs + i * sizeof(double));
    printf("Y座標?:\n");
    scanf("%e",  ys + i * sizeof(double));
  }
}
