#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <wincon.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void ex2();
union MyUnion
{
	float f;
	int i;
};
int main() {
	int ex = 0;
	scanf("%d", &ex);
	if (ex == 2) {
		float n=0.1;
		scanf("%f", &n);
		ex2(&n);
		n*=-1;
		ex2(&n);
	}
	else if(ex == 4)
	{

	}
}


void ex2(float* num) {
	union MyUnion a;
	a.f = *num;
	char buff[33];
	for (int i = 0; i < 32; i++)
	{
			buff[31-i] = ((1 << i) & a.i) >> i;
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 32; i++)
	{
		if(!i)SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
		if (i)SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 2));
		if(i>9)SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 3));
		if (i == 10)SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
		printf("%d", buff[i] < 0 ? buff[i] * -1 : buff[i]);
	}
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	printf("\n");
}