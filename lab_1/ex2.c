#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void ex2() {
	double a, b, c, res1, res2;
	printf("������� a,b,c:\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	a ? pow(b, 2) - 4 * a * c >= 0 ? (res1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a), res2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a), printf("�����: \n%lf\n%lf\n", res1, res2)) : printf("��� �������������� ������\n") : printf("������ ��������� �� ����������");
	return;
}