#include <stdio.h>
void ex3() {
	int sum;
	for (int i = 10; i < 100; i++)
	{
		sum = i % 10 + i / 10;
		if ((sum + 1) * sum == i) printf("%d\n", i);
	}
	return;
}
int main() { ex3(); }