#pragma once
struct _box{
	//print/destory/insert
	void (*Dtor)(struct _box *box);
	void (*print_all_elems)(struct _box *box);
	//void (*push_back)(struct _box *box, int elem);
	//void (*pop_back)(struct _box *box);
	void (*insert)(struct _box *box, int pos, int elem);
	int (*erase)(struct _box *box, int pos);
	int (*capacity)(struct _box *box);
	int (*size)(struct _box *box);
	//int (*max_size)(struct _box *box);
	//void (*shrink_to_fit)(struct _box *box);
	//void (*resize)(struct _box *box);
	void (*clear)(struct _box *box);

};

typedef struct _box box;