#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#include "list.h"
#include "vector.h"

int main() {
	box* l = list_Ctor();
	box* v = vector_Ctor();

	l->Dtor(l);
	v->Dtor(v);
	return 0;
}