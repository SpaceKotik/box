#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#include "list.h"
#include "vector.h"

int main() {
	box* l = list_Ctor();
	box* v = vector_Ctor();

	
	int i;
	for(i = 0; i < 15; ++i) {
		v->push_back(v, i);
	}
	
	//v->insert(v, 2, 20);
	v->print_all_elems(v);

	//v->Dtor(v);
	l->Dtor(l);


/*float *p = malloc (sizeof(float));
int *p2 = (int*)p;
float *p3 = (float*)p2;
free(p3);
printf("ok\n");*/
	return 0;
}