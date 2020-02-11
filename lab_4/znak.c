#include "znak.h"
#include <stdio.h>
void print_student(Znak* this) {
	printf("Имя: %s\nФаимлия: %s\nЗнак зодиака: %s\nДата рождения: %d.%d.%d\n\n", this->first_name, this->second_name, this->zodiac_sign, this->birthday[0], this->birthday[1], this->birthday[2]);
	return;
}
int greater(Znak* first, Znak* second) {
	if (first->birthday[2] > second->birthday[2])return 1;
	else if (first->birthday[2] == second->birthday[2]) {
		if (first->birthday[1] > second->birthday[1])return 1;
		else if (first->birthday[1] == second->birthday[1])
			if (first->birthday[0] > second->birthday[0])return 1;
	}
	return 0;
}
