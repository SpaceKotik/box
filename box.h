#pragma once


typedef struct _box {

	void (*Dtor)(struct _box *box);
	void (*print_all_elems)(struct _box *box);
	void (*push_back)(struct _box *box, int elem);
	int (*pop_back)(struct _box *box);
	void (*insert)(struct _box *box, int pos, int elem);
	int (*erase)(struct _box *box, int pos);
	int (*capacity)(struct _box *box);
	int (*size)(struct _box *box);
	int (*max_size)(struct _box *box);
	void (*shrink_to_fit)(struct _box *box);
	int (*get)(struct _box *box, int pos);
	void (*clear)(struct _box *box);
	void (*bsort)(struct _box *box);

	void (*dump)(struct _box *box);
} box;