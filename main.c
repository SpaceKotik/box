#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#include "list.h"
#include "vector.h"

void bubble_sort(struct _box *vec) {

	int i, j;
	for (i = 0; i < vec->size(vec) - 1; i++) {
		for (j = 0; j < vec->size(vec)-i-1; ++j)
		{
			if (vec->get(vec, j) > vec->get(vec, j+1)) {
				vec->insert(vec, j+2, vec->get(vec, j));
				vec->erase(vec, j);
			}
		}
	}
}

void test_vector(){
	
	box* v = vector_Ctor();
	int i;
	v->push_back(v, 20);
	v->push_back(v, -15);
	v->shrink_to_fit(v);
	v->dump(v);
	for(i = 0; i < 15; ++i) {
		v->insert(v, 2, i);
	}
	v->dump(v);

	printf("erased\n");
	v->erase(v, 5);
	v->dump(v);

	v->erase(v, 5);
	printf("erased\n");
	v->dump(v);

	v->pop_back(v);
	v->pop_back(v);
	v->pop_back(v);
	v->pop_back(v);

	v->dump(v);
	//printf("%d %d %d\n", v->capacity(v), v->size(v), v->max_size(v));
	//v->bsort(v);
	//v->dump(v);
	bubble_sort(v);
	v->dump(v);

	v->Dtor(v);
}









int main() {
	box* l = list_Ctor();
	l->Dtor(l);

	test_vector();

	return 0;
}