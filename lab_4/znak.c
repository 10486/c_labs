#include "znak.h"
#include <stdio.h>
// Если находиться в функции identify_sign то выводит крякозябры 
char signs_name[12][10] = { "Козерог", "Водолей", "Рыбы", "Овен", "Телец", "Близнецы", "Рак", "Лев", "Дева", "Весы", "Скорпион", "Стрелец", };
void print_person(Znak* this) {
	printf("\nИмя: %s\nФаимлия: %s\nЗнак зодиака: %s\nДата рождения: %02d.%02d.%04d\n", this->first_name, this->second_name, this->zodiac_sign, this->birthday[0], this->birthday[1], this->birthday[2]);
	return;
}
//true если первый больше второго(строго)
int greater(Znak* first, Znak* second) {
	if (first->birthday[2] > second->birthday[2])return 1;
	else if (first->birthday[2] == second->birthday[2]) {
		return greater_excl_year(first->birthday, second->birthday);
	}
	return 0;
}
//true есди они равны
int equal(Znak* first, Znak* second) {
	if (first->birthday[2] == second->birthday[2] && equal_excl_year(first->birthday, second->birthday))return 1;
	return 0;
}
//true если первый меньше второго(строго)
int less(Znak* first, Znak* second) {
	return !(greater(first, second) || equal(first, second));
}
int greater_excl_year(int* first, int* second) {
	if (first[1] > second[1])return 1;
	else if (first[1] == second[1])
		if (first[0] > second[0])return 1;
	return 0;
}
int equal_excl_year(int* first, int* second) {
	if (first[0] == second[0] && first[1] == second[1])return 1;
	return 0;
}
int less_excl_year(int* first, int* second) {
	return !(greater_excl_year(first, second) || equal_excl_year(first, second));
}
void identify_sign(Znak* this) {
	int sign = -1;
	int signs[12][2] = {
		{19, 1},
		{19, 2},
		{20, 3},
		{20, 4},
		{21, 5},
		{21, 6},
		{22, 7},
		{23, 8},
		{23, 9},
		{22, 10},
		{22, 11},
		{21, 12}
	};
	for (int i = 0; i < 12; i++)
	{
		if (less_excl_year(this->birthday, signs[i]) || equal_excl_year(this->birthday, signs[i])) {
			sign = i;
			break;
		}
	}
	if (sign == -1)sign = 0;
	this->zodiac_sign = signs_name[sign];
	return;
}