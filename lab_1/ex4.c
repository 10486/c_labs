﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void ex4() {
	const int MIN = -34, MAX = 90;
	long long result = 1;
	int tmp, flag = 0;
	printf("Введите последовательность:\n");
	while (1)
	{
		scanf("%d", &tmp);
		if (!tmp)break;
		if (tmp >= MIN && tmp <= MAX)
		{
			result *= tmp;
			flag = 1;
		}
	}
	printf("%d", flag ? result : 0);
	return;
}
int main() { ex4(); }