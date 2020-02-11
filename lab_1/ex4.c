#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void ex4() {
	const int MIN = -34, MAX = 90;
	int tmp, result = 1, flag = 0;
	printf("¬ведите последовательность:\n");
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
