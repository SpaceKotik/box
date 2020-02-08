#include "list.h"
#include <malloc.h>
#include <stdlib.h>

#define _POISON 0

typedef struct _elem_t{
	data_t data;
	struct _elem_t* next;
	struct _elem_t* prev;
} elem_t;

typedef struct _list_t{
	box b;
	elem_t* head;
	elem_t* tail;
	int size;
}list_t;

//comment
void list_push_back(box *list_b, data_t data_new) {
	list_t *list = (list_t*)(list_b);
	elem_t *elem = (elem_t*)calloc(1, sizeof(elem_t));
	elem->data = data_new;
	if (list->size == 0){
		list->head = elem;
		list->tail = elem;
		elem->next = NULL;
		elem->prev = NULL;
	} else {
		elem->next = NULL;
		elem->prev = list->tail;
		list->tail = elem;
	}
}

void list_pop_back(box *list_b) {
	list_t *list = (list_t*)(list_b);
	printf("%d\n", list->tail->data);
	list->tail->data = _POISON;
	if (list->size == 1) {
		free(list->tail);
		list->tail = NULL;
		list->head = NULL;
	} else {
		list->tail->prev = NULL;
		list->tail = list->tail->prev;
		free(list->tail->next);
		list->tail->next = NULL;
	}
}

int list_size(box *list_b){
	list_t *list = (list_t*)(list_b);
	return list->size;
}

void list_resize(box *list_b){
	list_t *list = (list_t*)(list_b);

}

void list_Dtor(box* list_b) {
	list_t *list = (list_t*)(list_b);
	//free(elem);
}

box* list_Ctor() {
	printf("List_Ctor\n");
	list_t* list = (list_t*)calloc(1, sizeof(list_t));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->b.Dtor = list_Dtor;
	return (box*) list;
}
