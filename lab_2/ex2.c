#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
void  ex2() {
	int n = 0, maxi = 0, mini = 0, tmp, max, min;
	int* arr;
	printf("������� n:");
	scanf("%d", &n);
	if ((arr = malloc(sizeof(int) * n)) == NULL) {
		printf("��������� ������ ���������� ��������");
		return;
	}
	printf("������� ������������������:\n");
	// ���� ����������� � ������������ �������� � �� ������� ���������� ��������� � ������
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		arr[i] = tmp;
		if (!i)min = max = tmp;
		if (tmp <= min)
		{
			mini = i;
			min = tmp;
		} 
		if (tmp > max) 
		{
			maxi = i;
			max = tmp;
		}
	}
	//for (int i = maxi > mini ? mini : maxi; i < ((maxi > mini) ? maxi : mini); i++)	if (!(arr[i] & 1) && (arr[i - 1] != 0 || !i))arr[i] *= -1;
	// ��������� �� -1 ���������� �� ������� ��������
	for (int i = maxi > mini ? mini : maxi; i < ((maxi > mini) ? maxi : mini); i++) {
		if (arr[i] % 2 == 0 && (i == 0 || arr[i - 1] != 0)) {
			arr[i] *= -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	return;
}