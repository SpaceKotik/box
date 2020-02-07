#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#include "list.h"
#include "vector.h"

int main() {
	box* l = list_create();
	box* v = vector_create();

	l->Dtor(l);
	v->Dtor(v);
	return 0;
}