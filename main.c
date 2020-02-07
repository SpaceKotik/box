#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#include "list.h"
#include "vector.h"

int main() {
	box* l = list_Ctor();
	box* v = vector_Ctor();


	v->Dtor(v);
	l->Dtor(l);

	return 0;
}