#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double const EPS = 1e-5;
int const MAX_STEP = 1000;

double fun(double a, double b, double c,
         double d, double e, double f, double x) {
  return a * pow(x, 5) + b * pow(x, 4) + c * pow(x, 3) +
    d * pow(x, 2) + e * x + f;
}

double fd(double a, double b, double c,
          double d, double e, double f, double x) {
  return 5* a * pow(x, 4) + 4 * b * pow(x, 3) + 3 * c * pow(x, 2) +
    2 * d * x + e;
}

int main() {
  double x;
  double a, b, c, d, e, f;
  bool ok = false;

  puts("initilal x?");
  scanf("%lf", &x);
  puts("a?");
  scanf("%lf", &a);
  puts("b?");
  scanf("%lf", &b);
  puts("c?");
  scanf("%lf", &c);
  puts("d?");
  scanf("%lf", &d);
  puts("e?");
  scanf("%lf", &e);
  puts("f?");
  scanf("%lf", &f);

  for (int t = 0; t < MAX_STEP; ++t) {
    double y = fun(a, b, c, d, e, f, x);
    if (fabs(y) < EPS) {
      ok = true;
      break;
    }
    x = x - y / fd(a, b, c, d, e, f, x);
    printf("%d: %lf\n", t, x);
  }

  if (ok) {
    printf("sol: %lf\n", x);
  } else {
    puts("dose not converge...");
  }

  printf("f(%lf) = %lf\n", x, fun(a, b, c, d, e, f, x));
  return 0;
}
