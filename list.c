#include "list.h"
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

struct _list{
	box b;
	char* name;
};

typedef struct _list list;



/*box* list_create() {
	box *temp = (box*)calloc(1, sizeof(box));
	return temp;
}*/

void list_Dtor(box* box) {
	//free(list);
}

box* list_Ctor() {
	printf("a\n");
	list* list = (struct _list*)(calloc(1, sizeof(list)));
	list->name = "list_n";
	list->b.Dtor = list_Dtor;
	return (box*) list;
}