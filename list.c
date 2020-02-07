#include "list.h"
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

struct _list{
	box b;
	char* name;
};

typedef struct _list list;

box* list_create() {
	list* list = (list*)calloc(1, sizeof(list));
	list->name = "list_n";
	return (box*) list;
}

box* list_create() {
	box *temp = (box*)calloc(1, sizeof(box));
	return temp;
}

void Dtor(* list) {
	free(list);
}