#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "znak.h"
#include <malloc.h>
#include<locale.h>
#define MAX_SIZE 12
void sort(Znak* arr, int len);
int main() {
	setlocale(LC_ALL, "");
	Znak* arr = malloc(sizeof(Znak) * MAX_SIZE);
	int stop = 0;
	int len = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		len++;
		printf("������� ���:");
		scanf("%s", arr[i].first_name);
		printf("������� �������:");
		scanf("%s", arr[i].second_name);
		printf("������� ���� �������:");
		scanf("%s", arr[i].zodiac_sign);
		printf("������� ���� ��������(�� �� ����)");
		scanf("%d %d %d", &(arr[i].birthday[0]), &(arr[i].birthday[1]), &(arr[i].birthday[2]));
		printf("��� ����������� ����� ������� '0', ��� ��������� ����� '1'");
		scanf("%d", &stop);
		if (stop)break;

	}if ((arr = realloc(arr, sizeof(Znak) * (len + 1))) == NULL) {
		printf("�������� ������ � ���������� ������");
		exit(1);
	}
	sort(arr, len);
	for (int i = 0; i < len; i++)
	{
		print_student(&arr[i]);
	}
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