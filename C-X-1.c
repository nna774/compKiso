#include <stdio.h>

double const eps = 1.0e-5;

int main() {
  double spring_constants[3];
  double naturals[3];
  double xs[3], ys[3];
  int i;
  for(i = 0; i < 3; ++i) {
    printf("ばね%d:\n", i+1);
    printf("ばね定数?:\n");
    scanf("%lf",  spring_constants + i);
    printf("自然長?:\n");
    scanf("%lf",  naturals + i);
    printf("X座標?:\n");
    scanf("%lf",  xs + i);
    printf("Y座標?:\n");
    scanf("%lf",  ys + i);
  }
  for(i = 0; i < 3; ++i) {
    printf("ばね%d:\n", i+1);
    printf("ばね定数: ");
    printf("%lf\n",  spring_constants[i]);
    printf("自然長: ");
    printf("%lf\n",  naturals[i]);
    printf("X座標: ");
    printf("%lf\n",  xs[i]);
    printf("Y座標: ");
    printf("%lf\n",  ys[i]);
  }
}
