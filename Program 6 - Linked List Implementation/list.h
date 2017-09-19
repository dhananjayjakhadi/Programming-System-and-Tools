#ifndef LIST_H
#define LIST_H
#define EMPTY 0

typedef struct data {
  int value;
}Data;

typedef struct  Node {
  Data data;
  struct Node* next;
  struct Node* prev;
}Node;

typedef struct List {
  struct Node* head;
  struct Node* tail;
}List;

typedef struct Stack  {
  List* list;
}Stack;

typedef struct Queue {
  List* list;
}Queue;

List* createList();
void insertData(List * , int , Data );
void removeData(List * , int );
Data* readData(List * , int );
int isEmpty(List *);
void deleteList(List * );
int searchForward(List *, Data);
int searchBackward(List *, Data);
void push(Stack *, Data);
Data pop(Stack *);
void enqueue(Queue *, Data);
Data dequeue(Queue *);

#endif
