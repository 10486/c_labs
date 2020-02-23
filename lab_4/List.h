#pragma once
#include "znak.h"
typedef struct list
{
	struct node* head;
	struct node* tail;
}List;
typedef struct node 
{
	struct node* next;
	struct node* prev;
	Znak* data;
}Node;
void append(List* list, Znak* znak);
Znak* find_in_list(List* list, char* s_name);
char* list_to_string(List* list);