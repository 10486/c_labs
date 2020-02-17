#include <stdbool.h>
#include <malloc.h>
void ex1() {
	int n = 0;
	bool flag = true;
	printf("Введите n:");
	scanf("%d", &n);
	double tmp = 0, prev = 0, result = 0;
	double* arr;
	if ((arr = malloc(n * sizeof(double))) == NULL) {
		printf("Выделение памяти окончилось неудачей");
		return;
	}
	printf("Введите последовательность:\n");
	// Записываем элементы в список и проверяем на неубывание последовательность
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &tmp);
		if (i)if ((prev < 0 ? prev * prev : prev) > (tmp < 0 ? tmp * tmp : tmp))flag = false;
		arr[i] = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		if (flag)result += arr[i];
		else result *= arr[i];
	}
	printf("%lf", result);
	free(arr);
	return;
}