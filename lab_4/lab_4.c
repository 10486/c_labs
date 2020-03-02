#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "List.h"
#include "znak.h"
#include <malloc.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#define MAX_SIZE 12
void sort(Znak* arr, int len);
Znak* find(Znak* arr, int len, char* second_name);
void array_variant() {
	Znak* arr = malloc(sizeof(Znak) * MAX_SIZE);
	int stop = 0;
	int len = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		len++;
		arr[i] = *input_znak();
		printf("Для продолжения ввода введите '0', для окончания ввода '1' ");
		scanf("%d", &stop);
		if (stop)break;

	}if ((arr = realloc(arr, sizeof(Znak) * (len + 1))) == NULL) {
		printf("Возникла ошибка с выделением памяти");
		exit(1);
	}
	sort(arr, len);
	char s_name[SECOND_NAME_LENGTH];
	printf("Введите фамилию искомого человека: ");
	scanf("%s", s_name);
	Znak* tmp = find(arr, len, s_name);
	if (tmp == NULL) {
		printf("Человека с такой фамилией нет\n");
	}
	else {
		printf("%s", znak_to_string(tmp));
	}
	//Вывод всех людей
	for (int i = 0; i < len; i++)
	{
		printf("%s", znak_to_string(&arr[i]));
	}
}
void list_variant() {
	List* list = calloc(1, sizeof(List));
	int stop = 0;
	int len = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		len++;
		append(list, input_znak());
		printf("Для продолжения ввода введите '0', для окончания ввода '1' ");
		scanf("%d", &stop);
		if (stop)break;

	}
	char s_name[SECOND_NAME_LENGTH];
	printf("Введите фамилию искомого человека: ");
	scanf("%s", s_name);
	Znak* tmp = find_in_list(list, s_name);
	if (tmp == NULL) {
		printf("Человека с такой фамилией нет\n");
	}
	else {
		printf("%s", znak_to_string(tmp));
	}
	//Вывод всех людей
	printf("%s", list_to_string(list));
}
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	list_variant();
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
			return &arr[i];
		}
	}
	return NULL;
}