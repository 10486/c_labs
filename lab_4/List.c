#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include <malloc.h>
#include <string.h>
char* list_to_string(List* list) {
	int length = size(list);
	int total = 1;
	char** items = malloc(sizeof(char*) * length);
	Node* tmp = list->head;
	for (int i = 0; i < length; i++)
	{
		items[i] = znak_to_string(tmp->data);
		total += strlen(items[i]);
		tmp = tmp->next;
	}
	char* buffer = calloc(total + 1 ,sizeof(char));
	for (int i = 0; i < length; i++){
		strcat(buffer, items[i]);
	}
	for (int i = 0; i < length; i++)
	{
		free(items[i]);
	}
	free(tmp);
	free(items);
	return buffer;
}
void append(List* list, Znak* znak) {
	Node* tmp = calloc(1, sizeof(Node));
	tmp->data = znak;
	if (list->head == NULL) {
		list->tail = list->head = tmp;
	}
	else {
		if (less(znak, list->head->data)) {
			list->head->prev = tmp;
			tmp->next = list->head;
			list->head = tmp;
		}
		else {
			Node* current = list->head->next;
			if (current != NULL) {
				while (greater(znak, current->data) || equal(znak, current->data)) {
					current = current->next;
					if (current->next == NULL) {
						list->tail = current->next = tmp;
						tmp->prev = current;
						return;
					}
				}
			}
			tmp->next = current->next;
			tmp->next->prev = tmp;
			current->next = tmp;
			tmp->prev = current;
		}
	}
}
Znak* find_in_list(List* list, char* s_name) {
	
	for(Node* tmp = list->head;tmp != NULL; tmp = tmp->next)
	{
		if (!strcmp(tmp->data->second_name, s_name))return tmp->data;
	}
	return NULL;
}
int size(List* list) {
	int length = 0;
	Node* cur = list->head;
	while (cur != NULL) {
		length++;
		cur = cur->next;
	}
	return length;
}