#pragma once
struct _box{
	//print/destory/insert
	void (*Dtor)(struct _box *box);
};

typedef struct _box box;

//ddfsd