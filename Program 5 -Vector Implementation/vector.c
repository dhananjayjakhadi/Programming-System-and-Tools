#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"


Vector *initVector()
{
	Vector *v;
	v = (Vector *)malloc(sizeof(Vector));
 	v-> current_size=0;
	v-> max_size=0;
	v->data =NULL;
	return v;
}

void vectorInsert(Vector * v, int index, Data d)
{
	if(index >= v->max_size) {
		v->max_size = (index * 2) + 1;
		Data *new_array = malloc(sizeof(Data) * v->max_size);
		memset(new_array, -1, sizeof(Data) * v->max_size);
		memcpy(new_array, v->data, sizeof(Data) * v->current_size);
		free(v->data);
		v->data = new_array;
   	}

   	v->data[index] = d;
   	
	if(index >= v->current_size) {
		v->current_size = index + 1;
	}
}

Data * vectorRead(Vector * array, int index)
{
	if(index >= array->max_size || index < 0) {
		return NULL;
	} else {
		return &(array->data[index]);
	}
}


void vectorRemove(Vector * array, int index)
{
	int i=0,j=0;
	if(index >= array->max_size || index < 0) {
		return;
	}
	Data *new_array = malloc(sizeof(Data) * (array->max_size-1));
	for(i=0;i<index;i++)
	{
		new_array[j] = array->data[i];
		j++;
	}
	i++;
	for(;i<array->max_size;i++)
	{
		new_array[j] = array->data[i];
		j++;
	}
	free(array->data);
	array->data = new_array;
	array->current_size--;
	array->max_size--;
}

void vectorInsertIncremental(Vector * v, int index, Data d)
{
	if(index >= v->max_size) {
		v->max_size = index + 1;
		Data *new_array = malloc(sizeof(Data) * v->max_size);
		memset(new_array, -1, sizeof(Data) * v->max_size);
		memcpy(new_array, v->data, sizeof(Data) * v->current_size);
		free(v->data);
		v->data = new_array;
   	}

   	v->data[index] = d;
   	
	if(index >= v->current_size) {
		v->current_size = index + 1;
	}
}

void * deleteVector(Vector * array)
{
	free(array->data);
	array->data = NULL;
	free(array);
	array = NULL;
	return NULL;

}

void vectorInsertMine(Vector * v, int index, Data d)
{
	if(index >= v->max_size) {
		v->max_size = index + 10;
		Data *new_array = malloc(sizeof(Data) * v->max_size);
		memset(new_array, -1, sizeof(Data) * v->max_size);
		memcpy(new_array, v->data, sizeof(Data) * v->current_size);
		free(v->data);
		v->data = new_array;
   	}

   	v->data[index] = d;
   	
	if(index >= v->current_size) {
		v->current_size = index + 1;
	}
}