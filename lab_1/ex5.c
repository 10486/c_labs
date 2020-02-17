#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void ex5() {
	int n;
	double tmpsin, tmpcos, result = 0;
	printf("Введите n:");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		tmpsin = 0;
		tmpcos = 0;
		for (int j = 1; j <= i; j++)
		{
			tmpsin += sin(j);
			tmpcos += cos(j);
		}
		result += tmpsin / tmpcos;
	}
	printf("%lf", result);
	return;
}