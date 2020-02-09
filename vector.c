#include "vector.h"
#include <malloc.h>
#include <stdlib.h>

typedef struct _vector{

	
	struct _box mt;

	int *data;
	int size;
	int capacity;
	int max_size;

} vector;


void swap (int* a, int *b) {
	int temp = *a;
	// /temp = a;
	*a = *b;
	*b = temp;
}

void vector_print_all_elems (struct _box *vec) {

	vector *temp_v = (vector*)(vec);

	int i;
	for(i = 0; i < temp_v->size; ++i) {
		printf("%d ", temp_v->data[i]);
	}
	printf("\n");
}

void vector_push_back (box *vec, int elem) {
	vector *temp_v = (vector*)(vec);
/*
	if (temp_v->size >= temp_v->capacity) {
		temp_v->data = (int*)realloc(temp_v->data, 2*(temp_v->capacity)*(sizeof(int)));
		temp_v->capacity *= 2;
		}
*/
	temp_v->data[temp_v->size++] = elem;
	printf("size: %d capacity: %d\n", temp_v->size, temp_v->capacity);
}

void vector_insert (struct _box *vec, int pos, int elem) {

	vector *temp_v = (vector*)(vec);

	/*if (temp_v->size >= temp_v->capacity) {
		temp_v->data = (int*)realloc(temp_v->data, 2*(temp_v->capacity)*(sizeof(int)));
		temp_v->capacity *= 2;
	}*/

	temp_v->data[temp_v->size++] = elem;

	int i;
	for (i = temp_v->size-1; i > pos; ++i) {
		swap(&temp_v->data[i], &temp_v->data[i-1]);
	}


}

int vector_erase (struct _box *vec, int pos) {

	return 0;
}

int vector_capacity (struct _box *vec) {
	vector *temp_v = (vector*)(vec);
	return temp_v->capacity;
}

int vector_size (struct _box *vec) {
	vector *temp_v = (vector*)(vec);
	return temp_v->size;
}

void vector_clear (struct _box *vec) {

	vector *temp_v = (vector*)(vec);

	temp_v->data = realloc(temp_v->data, 32*(sizeof(int)));
	temp_v->capacity = 32;
	temp_v->size = 0;
}

void vector_Dtor(box* vec) {

	vector *temp_v = (vector*)(vec);
	free(temp_v->data);
	free(temp_v);
}

box* vector_Ctor() {
	printf("b\n");
	vector* vector = (struct _vector*)calloc(1, sizeof(vector));
	vector->data = (int*)calloc(32, sizeof(int));

	vector->size = 0;
	vector->capacity = 32;

	vector->mt.Dtor = vector_Dtor;
	vector->mt.print_all_elems = vector_print_all_elems;

	vector->mt.push_back = vector_push_back;

	vector->mt.insert = vector_insert;
	vector->mt.erase = vector_erase;
	vector->mt.capacity = vector_capacity;
	vector->mt.size = vector_size;
	vector->mt.clear = vector_clear;

	return (box*)vector;
}