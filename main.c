#include <stdio.h>
#include <math.h>

double f(double p, double q, double r, double x) {
    return p * pow(x, 3) + q * x + r;
}

double bisection(double p, double q, double r, double a, double b, int n, double eps) {
    double fa = f(p, q, r, a);
    double fb = f(p, q, r, b);

    if (fa * fb >= 0) {
        printf("Bisection method cannot guarantee convergence with the given interval [%lf, %lf]\n", a, b);
        return 0.0;
    }

    for (int i = 0; i < n; i++) {
        double c = (a + b) / 2.0;
        double fc = f(p, q, r, c);

        printf("Iteration %d: x = %lf, f(x) = %lf\n", i + 1, c, fc);

        if (fabs(fc) < eps) {
            printf("Converged to root %lf within tolerance %lf (after %d iterations)\n", c, eps, i + 1);
            return c;
        }

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    printf("Bisection method did not converge within %d iterations\n", n);
    return 0.0;
}

int main() {
    double p, q, r, a, b, eps;
    int n;

    printf("Enter the coefficients p, q, and r: ");
    scanf("%lf %lf %lf", &p, &q, &r);

    printf("Enter the interval endpoints a and b: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the maximum number of iterations n: ");
    scanf("%d", &n);

    printf("Enter the error tolerance eps: ");
    scanf("%lf", &eps);

    double root = bisection(p, q, r, a, b, n, eps);

    if (root != 0.0) {
        printf("The root is approximately %lf\n", root);
    }

    return 0;
}
