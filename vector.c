#include "vector.h"
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

typedef struct _vector{
	box b;
	char* name;
} vector;

box* vector_create() {
	vector* vector = (vector*)calloc(1, sizeof(vector));
	vector->name = "vec_n";
	return (box*) vector;
}

void Dtor(vector* vec) {
	free(vec);
}