#include "vector.h"
#include <malloc.h>
#include <stdlib.h>

typedef struct _vector{
	box b;
	int *data;
	int size;
	int capacity;
	int max_size;
} vector;

void vector_print_all_elems (struct _box *vec) {

	vector *temp_v = (vector*)(vec);

	int i;
	for(i = 0; i < temp_v->size; ++i) {
		printf("%d ", temp_v->data[i]);
	}
	printf("\n");
}

void vector_insert (struct _box *vec, int pos, int elem) {
	
	vector *temp_v = (vector*)(vec);

	if (temp_v->size >= temp_v->capacity) {
		temp_v->data = realloc(temp_v->data, 2*(temp_v->capacity)*(sizeof(int)));
		temp_v->capacity *= 2;
	}

	temp_v->data[temp_v->size++] = elem;

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
	vector->b.Dtor = vector_Dtor;
	return (box*) vector;
}