#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"list.h"
List *createList()
{
	List *list;
	list = (List *) malloc(sizeof(List));
	if (list == NULL) {
		printf("No memory was allocated for list");
		exit(0);
	}
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void insertData(List * list, int index, Data data)
{

	int i;
	//case when list is empty, just insert at the head
	if (list->head == NULL) {
		Node *newnode;
		newnode = (Node *) malloc(sizeof(Node));
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;
		list->head = newnode;
		list->tail = newnode;
	} else {
		Node *node;
		node = list->head;
		for (i = 0; i < index; i++) {
			if (node->next == NULL) {
				break;
			}
			node = node->next;
		}
		Node *newnode;
		newnode = (Node *) malloc(sizeof(Node));
		newnode->data = data;
		newnode->prev = node;
		newnode->next = node->next;
		node->next = newnode;
		if (node == list->tail) {
			list->tail = newnode;
		}
	}
}

void removeData(List * list, int index)
{
	Node *node;
	int i;
	if (index >= 0) {
		node = list->head;
		for (i = 0; i < index; i++) {
			if (node->next == NULL) {
				return;
			}
			node = node->next;
		}
	} else {
		node = list->tail;
		for (i = 0; i < index; i--) {
			if (node->prev == NULL) {
				return;
			}
			node = node->prev;
		}
	}
	if (node->prev != NULL) {
		(node->prev)->next = node->next;
	}
	if (node->next != NULL) {
		(node->next)->prev = node->prev;
	}
	if (node == list->head) {
		list->head = node->next;
	}
	if (node == list->tail) {
		list->tail = node->prev;
	}
	node->prev = NULL;
	node->next = NULL;
	free(node);
	node = NULL;
}

Data *readData(List * list, int index)
{
	Node *current = list->head;
	int i = 0;
	while (current != NULL && i < index) {
		current = current->next;
		i++;
	}
	if (i == index) {
		return &current->data;
	} else {
		return NULL;
	}
}

int isEmpty(List * list)
{
	if (list->head == NULL && list->tail == NULL)
		return 1;
	return 0;
}

void deleteList(List * list)
{
	while (!isEmpty(list)) {
		removeData(list, 0);
	}
	free(list);
	list = NULL;
}

int searchForward(List * list, Data searchKey)
{
	Node *current = list->head;
	int count = 1;
	if (current == NULL)
		return -1;
	else {
		while (current != NULL
		       && current->data.value != searchKey.value) {
			current = current->next;
			count++;
		}
	}
	if (current == NULL)
		return -1;
	else
		return count - 1;
}

int searchBackward(List * list, Data searchKey)
{
	Node *current = list->tail;
	int count = 1;
	if (current == NULL)
		return -1;
	else {
		while (current != NULL
		       && current->data.value != searchKey.value) {
			current = current->prev;
			count++;
		}
	}
	if (current == NULL)
		return -1;
	else
		return count - 1;
}

void push(Stack * stack, Data value)
{
	if (stack->list == NULL) {
		stack->list = createList();
	}
	insertData(stack->list, INT_MAX, value);
}

Data pop(Stack * stack)
{
	Data d;
	d.value = 0;
	if (isEmpty(stack->list)) {
		return d;
	}
	if (stack->list->tail == stack->list->head) {
		d.value = stack->list->tail->data.value;
		free(stack->list->tail);
		stack->list->tail = NULL;
		stack->list->head = NULL;
	} else {
		Node *tail = stack->list->tail;
		d.value = tail->data.value;	//tail->data.value;
		tail->prev->next = NULL;
		stack->list->tail = stack->list->tail->prev;
		stack->list->tail->next = NULL;
		free(tail);
	}
	return d;
}

void enqueue(Queue * queue, Data value)
{
	if (queue->list == NULL) {
		queue->list = createList();
	}
	insertData(queue->list, INT_MAX, value);
}

Data dequeue(Queue * queue)
{
	Data *data = readData(queue->list, 0);
	Data ret;
	ret.value = data->value;
	removeData(queue->list, 0);
	return ret;
}
