#pragma once
#include "box.h"

typedef int data_t;

//публичный интерфейс к вектору

void vector_print_all_elems (box *vec);
void push_back (box *vec, data_t elem);
data_t pop_back (box *vec);
void vector_insert (box *vec, int pos, data_t elem);
data_t vector_erase (box *vec, data_t pos);
data_t vector_capacity (box *vec);
data_t vector_size (box *vec);
data_t vector_max_size(box *vec);
void vector_clear (box *vec);
void vector_dump (box *vec);
void vector_shrink_to_fit (box *vec);
data_t vector_get(box *vec, data_t pos);

void bsort (box *vec);

void vector_Dtor (box *vec);
box* vector_Ctor();