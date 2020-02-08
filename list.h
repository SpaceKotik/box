#pragma once
#include "box.h"

//публичный интерфейс к листу

typedef int data_t;

void list_push_back(struct _box *box, data_t data);
void list_pop_back(struct _box *box);
int list_size(struct _box *box);
void list_resize(struct _box *box);

box* list_Ctor();
