#pragma once
#define NAME_LENGTH 20
#define SECOND_NAME_LENGTH 20
typedef struct znak
{
	char first_name[NAME_LENGTH];
	char second_name[SECOND_NAME_LENGTH];
	char* zodiac_sign;
	int birthday[3];
}Znak;
Znak* input_znak();
void identify_sign(Znak* this);
char* znak_to_string(Znak* this);
int greater(Znak* first, Znak* second);
int equal(Znak* first, Znak* second);
int less(Znak* first, Znak* second);


