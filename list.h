#pragma once
#include "box.h"

//публичный интерфейс к листу
/*
list:
N	 0    1    2
EL  |h|->| |->|t|


*/

typedef int data_t;

void list_push_back(struct _box *box, data_t data);
data_t list_pop_back(struct _box *box);
int list_size(struct _box *box);
void list_insert (box *list, int pos, data_t elem);
void list_resize(struct _box *box);
data_t list_erase (box *list, data_t pos);
data_t vector_get(box *list, data_t pos);
void list_print_all_elems (box *list);

void list_Dtor(box* list);
box* list_Ctor();


/*
void vector_print_all_elems (box *vec);

data_t vector_capacity (box *vec);

data_t vector_max_size(box *vec);
void vector_clear (box *vec);
void vector_dump (box *vec);
void vector_shrink_to_fit (box *vec);


*/