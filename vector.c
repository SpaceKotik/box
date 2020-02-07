#include "vector.h"
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

typedef struct _vector{
	box b;
	char* name;
} vector;

box* vector_Ctor() {
	vector* vector = (struct _vector*)calloc(1, sizeof(vector));
	vector->name = "vec_n";
	return (box*) vector;
}

void vector_Dtor(vector* vec) {
	free(vec);
}