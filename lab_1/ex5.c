#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void ex5() {
	int n;
	double tmpsin = 0, tmpcos = 0, result = 0;
	printf("Введите n:");
	scanf("%d", &n);
	if (n <= 0) {
		printf("Введенно не верное занчение n\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		tmpsin += sin(i);
		tmpcos += cos(i);
		result += tmpsin / tmpcos;
	}
	printf("%lf", result);
	return;
}
int main() { ex5(); }