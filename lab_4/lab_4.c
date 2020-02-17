#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "znak.h"
#include <malloc.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#define MAX_SIZE 12
void sort(Znak* arr, int len);
Znak* find(Znak* arr, int len, char* second_name);
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Znak* arr = malloc(sizeof(Znak) * MAX_SIZE);
	int stop = 0;
	int len = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		len++;
		printf("Введите имя:");
		scanf("%s", arr[i].first_name);
		printf("Введите фамилию:");
		scanf("%s", arr[i].second_name);
		do {
			printf("Введите дату рождения(дд мм гггг)\n");
			scanf("%d %d %d", &(arr[i].birthday[0]), &(arr[i].birthday[1]), &(arr[i].birthday[2]));
		} while (!(arr[i].birthday[1] > 0 && arr[i].birthday[1] < 13 && arr[i].birthday[0]>0 && arr[i].birthday[0] < 31 && arr[i].birthday[2] > 0));
		identify_sign(&arr[i]);
		printf("Для продолжения ввода введите '0', для окончания ввода '1' ");
		scanf("%d", &stop);
		if (stop)break;

	}if ((arr = realloc(arr, sizeof(Znak) * (len + 1))) == NULL) {
		printf("Возникла ошибка с выделением памяти");
		exit(1);
	}
	sort(arr, len);
	char s_name[20];
	printf("Введите фамилию искомого человека: ");
	scanf("%s", s_name);
	Znak* tmp = find(arr, len, s_name);
	if (tmp == NULL) {
		printf("Человека с такой фамилией нет\n");
	}
	else {
		print_person(tmp);
	}
	////Вывод всех людей
	//for (int i = 0; i < len; i++)
	//{
	//	print_person(&arr[i]);
	//}
	return 0;
}
void sort(Znak* arr, int len) {
	Znak tmp;
	for (int i = 0; i < len; i++) {
		char flag = 1;
		for (int j = 0; j < len - (i + 1); j++) {
			if (greater(&(arr[i]), &(arr[i + 1]))) {
				flag = 0;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (flag) {
			break;
		}
	}
}
Znak* find(Znak* arr, int len, char* second_name) {
	for (int i = 0; i < len; i++)
	{
		if (!strcmp(arr[i].second_name, second_name)) {
			printf("%s\n",arr[i].second_name);
			return &arr[i];
		}
	}
	return NULL;
}