#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void ex6() {
	double eps, tmp, result = 0;
	printf("¬ведите погрешность:");
	scanf("%lf", &eps);
	tmp = 1;
	for (float i = 1; tmp < 0 ? tmp * -1 : tmp > eps; i++) {
		result += tmp;
		tmp *= -2 / i;
	}
	printf("%lf", result);
	return;
}