/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-07 21:54
* Last modified      :2020-11-07 21:54
* Filename: newDun.c
* Description: 
----------------------------------------------------------*/
/*-------------------------------------------------------------
牛顿迭代求解
--------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

double F(double x, double n) {
	return x * x - n;
}

double f(double x) {
	return 2 * x;
}

double NewTon(double(*F)(double, double), double(*f)(double), double n) {
	double x = n / 2.0;
	#define EPS 1e-7
	while (fabs(F(x, n)) > EPS) {
		x -= F(x,n) / f(x);
	}
	#undef EPS

	return x;
}

double my_sqrt(double n) {
	return NewTon(F, f, n);
}

int main() {
    double n;
	while (~scanf("%lf", &n)) {
		printf("sqrt(%g) = %g\n", n, sqrt(n));
		printf("my_sqrt(%g) = %g\n", n, my_sqrt(n));
	}
    return 0;
}
