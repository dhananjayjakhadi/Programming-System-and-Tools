#ifndef VECTOR_H
#define VECTOR_H
#define EMPTY 0

typedef struct
{
	int value;
}Data;

typedef struct{
	Data *data;
	unsigned int current_size;
	unsigned int max_size;
}Vector;

Vector * initVector();
void vectorInsert(Vector * array, int index, Data value);
void vectorInsertIncremental(Vector * array, int index, Data value);
void vectorInsertMine(Vector * array, int index, Data value);
Data * vectorRead(Vector * array, int index);
void vectorRemove(Vector * array, int index);
void * deleteVector(Vector *);

#endif
