#include <stdio.h>
#include <math.h>

double const eps = 1.0e-5;
int const MAX_STEP = 100000;
int const DIV_D = 1000;

void calc_powers(double const * const spring_constants,
		 double const * const naturals,
		 double const * const xs,
		 double const * const ys,
		 double const * const current,
		 double powers[][2]) {
  int i = 0;
  for(i = 0; i < 3; ++i) {
    double len = sqrt(pow(xs[i] - current[0], 2) + pow(ys[i] - current[1], 2));
//    powers[i] = len < naturals[i] ? 0 : (spring_constants[i] * (len - naturals[i]));
    powers[i][0] = len < naturals[i] ? 0 : (spring_constants[i] * (xs[i] - current[0]));
    powers[i][1] = len < naturals[i] ? 0 : (spring_constants[i] * (ys[i] - current[1]));
  }
}

int main() {
  double spring_constants[3];
  double naturals[3];
  double xs[3], ys[3];
  int i, t = 0;
  double current[2] = { 100, 100 }; // x, y
  double prev[2] = { 0, 0 }; // x, y
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
  for(t = 0; t < MAX_STEP; ++t) {
    double powers[3][2]; // 各ばねについて{x, y}方向
    double sums[2] = { 0, 0 };
    calc_powers(spring_constants, naturals, xs, ys, current, powers);
    for(i = 0; i < 3; ++i) {
//      printf("%lf, %lf\n", powers[i][0], powers[i][1]);
      sums[0] += powers[i][0];
      sums[1] += powers[i][1];
    }
    // ひっぱられる時に動く微少量
    double const dx = sums[0] / DIV_D;
    double const dy = sums[1] / DIV_D;
    current[0] += dx;
    current[1] += dy;
//    puts("");
    printf("%lf, %lf\n", current[0], current[1]);

    if (sqrt(pow(prev[0] - current[0], 2) + pow(prev[1] - current[1], 2)) < eps) {
      break;
    }
    prev[0] = current[0];
    prev[1] = current[1];
  }
  printf("%lf, %lf\n", current[0], current[1]);
}
