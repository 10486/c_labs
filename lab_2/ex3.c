#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
void ex3() {
	float counter = 0;
	int n = 0, tmp = 0, negative = 0, flag = 0;
	int* arr;
	printf("Введите n:");
	scanf("%d", &n);
	if((arr = malloc(sizeof(int) * n )) == NULL) {
	printf("Выделение памяти окончилось неудачей");
	return;
	}
	printf("Введите последовательность:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		if (tmp % 2 == 0)counter += 0.5;
		if (tmp < 0)negative = tmp;
		arr[i] = tmp;
	}
	if ((arr = realloc(arr, sizeof(int) * (n + (int)counter))) == NULL) {
		printf("Выделение памяти окончилось неудачей");
		return;
	}
	// Вставляем отрицательный элемент
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0 && flag) {
			flag = 0;
			for (int j = n; j > i; j--)
			{
				arr[j] = arr[j - 1];
			}
			arr[i] = negative;
			n++;
			i++;
		}
		else if (arr[i] % 2 == 0) {
			flag = 1;
		}
	}
	// Удаляем нули
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0) {
			for (int j = i; j < n-1; j++)
			{
				arr[j] = arr[j + 1];
			}
			n--;
			i--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	return;
}
