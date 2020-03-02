#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
void ex1() {
	double a, b, x, y, z;
	printf("Введите x,y,z: \n");
	scanf("%lf %lf %lf", &x, &y, &z);
	if (x + M_PI_2 > 1 || x + M_PI_2 < -1) printf("Введено неверное значение x\n");
	else
	{
		if ((a = .5 + pow(sin(y), 2) + acos(x + M_PI_2)) == 0) {
			printf("Делитель равен нулю\n");
		}
		else {
			a = 2 * cos(x - M_PI_4) / a;
			printf("a = %lf\n", a);
		}
	}
	if ((b = 3. + pow(z, 2.) / 5.) == 0) {
		printf("Делитель равен нулю\n");
	}
	else {
		b = 1. + (pow(z, 2.) / b);
		printf("b = %lf", b);
	}
	return;
}
int main() { ex1(); }