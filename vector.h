#pragma once
#include "box.h"

//публичный интерфейс к листу

//empty, size, max_size, 


void vector_Dtor (struct _box *box);
void vector_print_all_elems (struct _box *box);
void vector_insert (struct _box *box, int pos, int elem);
int vector_erase (struct _box *box, int pos);
int vector_capacity (struct _box *box);
int vector_size (struct _box *box);
void vector_clear (struct _box *box);	


box* vector_Ctor();