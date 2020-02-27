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


bool istail(list_t* list) {
	if (list->next == NULL)
		return 1;
	else
		return 0;
}

void list_insert(box *list_b, int pos, data_t data) {
	list_t *list = (list_t*)(list_b);
	list_t* cur = list;

	elem_t *elem = (elem_t*)calloc(1, sizeof(elem_t));
	elem->data = data_new;
	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}
	if (list->size == 0) {
		list->head = elem;
		list->tail = elem;
		elem->next = NULL;
		elem->prev = NULL;
	} else if (istail(cur)) {
		elem->next = NULL;
		elem->prev = list->tail;
		list->tail = elem;		
	} else {
		elem->next = cur->next;
		elem->prev = cur;
		cur->next->prev = elem;
		cur->next = elem;
	}
}

data_t list_get(box *list_b, data_t pos) {
	list_t *list = (list_t*)(list_b);
	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}
	return cur->data;
}

void list_print_all_elems (box *list_b) {
	list_t *list = (list_t*)(list_b);

	cur = list;
	do {
		printf("%d ", cur->data);
		cur = cur->next;
	} while (!istail(cur));
}

void list_dump (box *list_b) {
	list_t *list = (list_t*)(list_b);

	printf("\n#____________| LIST_DUMP |\n");
	if (list->size == 0)
		printf("list is empty\n");
	else
		list_print_all_elems(list_b);
	printf("\n#___________| END L_DUMP |\n");
}

data_t list_erase(box *list_b, data_t pos) {
	list_t *list = (list_t*)(list_b);
	data_t data = cur->data;

	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}
	if (istail(cur)) {
		return list_pop_back(list_b);
	} else if(pos == 0) {
		cur->next->prev = NULL;
		list->head = cur->next;
		free(cur);
	} else {
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		free(cur);
	}

	return data;
}

void list_push_back(box *list_b, data_t data_new) {
	list_t *list = (list_t*)(list_b);
	n_tail = list_size - 1
	list_insert(n_tail);
}

data_t list_pop_back(box *list_b) {
	list_t *list = (list_t*)(list_b);
	data_t data = list->tail->data;
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

	return data;
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
