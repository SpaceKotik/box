#include "vector.h"
#include <malloc.h>
#include <stdlib.h>
#include "box.h"

#define MAX_SIZE 1024
#define DEFAULT_SIZE 32

typedef struct _vector{

	box mt;

	data_t *data;
	data_t size;
	data_t capacity;
	data_t max_size;

} vector;



void swap (int* a, data_t *b) {
	data_t temp = *a;
	*a = *b;
	*b = temp;
}

void vector_bubble_sort(struct _box *vec) {

	vector *temp_v = (vector*)(vec);

	int i, j;
	for (i = 0; i < temp_v->size - 1; i++) {
		for (j = 0; j < temp_v->size-i-1; ++j)
		{
			if (temp_v->data[j] > temp_v->data[j+1])
				swap(&temp_v->data[j], &temp_v->data[j+1]);
		}
	}
}


data_t vector_get(struct _box *vec, int pos) {
	vector *temp_v = (vector*)(vec);
	return temp_v->data[pos];
}

void vector_print_all_elems (struct _box *vec) {

	vector *temp_v = (vector*)(vec);

	data_t i;
	for(i = 0; i < temp_v->size; ++i) {
		printf("%d ", temp_v->data[i]);
	}
	printf("\n");
}

void vector_push_back (box *vec, data_t elem) {

	vector *temp_v = (vector*)(vec);

	if (temp_v->size >= temp_v->capacity) {
		if (temp_v->capacity*2 > temp_v->max_size) {
			printf("Exception: vector size limit reached\n");
			return;
		}

		temp_v->data = (int*)realloc(temp_v->data, 2*(temp_v->capacity)*(sizeof(int)));
		temp_v->capacity *= 2;
		}

	temp_v->data[temp_v->size++] = elem;
}

void vector_insert (struct _box *vec, data_t pos, data_t elem) {

	vector *temp_v = (vector*)(vec);

	if (temp_v->size >= temp_v->capacity) {
		if (temp_v->capacity*2 > temp_v->max_size) {
			printf("Exception: vector size limit reached\n");
			return;
		}
		temp_v->data = (int*)realloc(temp_v->data, 2*(temp_v->capacity)*(sizeof(int)));
		temp_v->capacity *= 2;
	}

	temp_v->data[temp_v->size++] = elem;

	data_t i;
	for (i = temp_v->size-1; i > pos; --i) {
		swap(&temp_v->data[i], &temp_v->data[i-1]);
	}	
}

data_t vector_erase (struct _box *vec, data_t pos) {

	vector *temp_v = (vector*)(vec);
	
	data_t i;
	for (i = pos; i < temp_v->size; ++i) {
		swap(&temp_v->data[i], &temp_v->data[i+1]);
	}
	temp_v->size--;

	return 0;
}

data_t vector_capacity (struct _box *vec) {

	vector *temp_v = (vector*)(vec);

	return temp_v->capacity;
}

data_t vector_size (struct _box *vec) {

	vector *temp_v = (vector*)(vec);

	return temp_v->size;
}

void vector_clear (struct _box *vec) {

	vector *temp_v = (vector*)(vec);

	temp_v->data = realloc(temp_v->data, DEFAULT_SIZE*(sizeof(int)));
	temp_v->capacity = DEFAULT_SIZE;
	temp_v->size = 0;
}

void vector_dump (box *vec) {

	vector *temp_v = (vector*)(vec);

	printf("\n##########VECTOR DUMP##########\n\n");
	printf("size: %d capacity: %d max_size: %d\n\n", temp_v->size, temp_v->capacity, temp_v->max_size);
	printf("Elements in vector: \n");
	if (temp_v->size == 0) {
		printf("empty\n");
	}
	else {
		vec->print_all_elems(vec);
	}
	printf("\n###############################\n");
}

data_t vector_max_size (box* vec) {

	vector *temp_v = (vector*)(vec);

	return temp_v->max_size;
}

void vector_Dtor(box* vec) {

	vector *temp_v = (vector*)(vec);

	free(temp_v->data);
	free(temp_v);
}

void vector_shrink_to_fit(box* vec) {

	vector *temp_v = (vector*)(vec);

	temp_v->data = (int*)realloc(temp_v->data, (temp_v->size)*(sizeof(int)));
	temp_v->capacity = temp_v->size;
}

data_t vector_pop_back (box *vec) {
	
	vector *temp_v = (vector*)(vec);

	temp_v->size--;
	return temp_v->data[temp_v->size];
}

box* vector_Ctor() {
	printf("b\n");
	vector* vector = (struct _vector*)calloc(1, sizeof(struct _vector));
	vector->data = (int*)calloc(DEFAULT_SIZE, sizeof(int));

	vector->size = 0;
	vector->capacity = DEFAULT_SIZE;
	vector->max_size = MAX_SIZE;

	vector->mt.Dtor = vector_Dtor;
	vector->mt.print_all_elems = vector_print_all_elems;

	vector->mt.push_back = vector_push_back;

	vector->mt.insert = vector_insert;
	vector->mt.erase = vector_erase;
	vector->mt.capacity = vector_capacity;
	vector->mt.size = vector_size;
	vector->mt.clear = vector_clear;
	vector->mt.dump = vector_dump;
	vector->mt.max_size = vector_max_size;
	vector->mt.shrink_to_fit = vector_shrink_to_fit;
	vector->mt.pop_back = vector_pop_back;
	vector->mt.get = vector_get;

	vector->mt.bsort = vector_bubble_sort;

	return (box*)vector;
}