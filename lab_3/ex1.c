#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
void ex1() {
	FILE* file;
	int size = 10, counter = 0, input_num = 0;
	printf("Введите число:");
	scanf("%d", &input_num);
	int* nums = malloc(sizeof(int) * size);
	if ((file = fopen("INPUT.TXT", "r")) == 0) {
		printf("Возникла ошибка открытия файла");
		return;
	}
	while (fscanf(file, "%d", &nums[counter]) != EOF) {
		if (nums[counter] == input_num) {
			nums[++counter] = nums[counter - 1];
		}
		if (++counter >= size - 2) {
			if ((nums = realloc(nums, (size *= 1.5) * sizeof(int))) == NULL) {
				printf("Выделение памяти окончилось неудачей");
				return;
			}
		}
	}
	fclose(file);
	if ((file = fopen("OUTPUT.TXT","w")) == 0) {
		printf("Возникла ошибка открытия файла");
		return;
	}
	for (int i = 0; i < counter; i++)
	{
		fprintf(file, "%d ", nums[i]);
	}
	fclose(file);
	return;
}
int main() { ex1(); }