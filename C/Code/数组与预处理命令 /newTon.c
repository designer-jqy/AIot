/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-08 15:36
* Last modified      :2020-11-08 15:36
* Filename           :newTon.c
* Description        :
----------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
double F(double x, double n) {
	return x * x - n;
}

double f(double x) {
	return 2 * x;
}

double newTon(double(*F)(double, double), double (*f)(double), double n) {
	double x = n / 2.0;
#define EPL 1e-7
	while (fabs(F(x, n)) > EPL) {
		x -= F(x,n) / f(x);
	}
#undef EPL
	return x;
}

double my_sqrt(double n) {
	return newTon(F, f, n);
}

int main() {
	double n;
	while(~scanf("%lf", &n)) {
		printf("sqrt(%g) = %g\n", n, sqrt(n));
		printf("my_sqrt(%g) = %g\n", n, my_sqrt(n));
	}

	return 0;
}
