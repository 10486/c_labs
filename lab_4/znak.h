#pragma once
typedef struct znak
{
	char first_name[20];
	char second_name[20];
	char zodiac_sign[10];
	int birthday[3];
}Znak;
void print_student(Znak* this);
int greater(Znak* first, Znak* second);


