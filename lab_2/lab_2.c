#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "ex.h"
int main() {
	setlocale(LC_ALL, "");
	int var;
	printf("Введите номер задания:");
	scanf("%d", &var);
	switch (var) {
	case 1:
		ex1();
		break;
	case 2:
		ex2();
		break;
	case 3:
		ex3();
		break;
	case 4:
		ex4();
		break;
	default:
		printf("Задания с таким номером нет");
	}
	return 0;
}