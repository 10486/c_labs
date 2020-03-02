#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
void ex4() {
	int n = 0;
	int tmp = 0;
	int* result;
	int** matrix;
	printf("Введите n:");
	scanf("%d", &n);
	if ((result = malloc(sizeof(int) * (2 * n - 1))) == NULL){
		printf("Выделение памяти окончилось неудачей");
		return;
	}
	if ((matrix = malloc(sizeof(int*) * n)) == NULL) {
		printf("Выделение памяти окончилось неудачей");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		
		if ((matrix[i] = malloc(sizeof(int) * n)) == NULL) {
			printf("Выделение памяти окончилось неудачей");
			return;
		}
	}
	printf("Введите матрицу (матрица заполняется построчно)\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	
	// Считаем диагонали до побочной включительно
	for (int i = 0; i < n; i++)
	{
		tmp = 1;
		for (int j = 0; j <= i; j++)
		{
			tmp *= matrix[i - j][j];
		}
		result[i] = tmp;
	}
	// Считаем диагонали ниже побочной
	for (int i = 1; i < n; i++)
	{
		tmp = 1;
		for (int j = 0; j < n - i; j++)
		{
			tmp *= matrix[n - 1 - j][i + j];
		}
		result[n - 1 + i] = tmp;
	}
	// Вывод
	for (int i = 0; i < 2 * n - 1; i++)
	{
		printf("%d ", result[i]);
	}
	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	free(result);
	return;
}
int main() { ex4(); }