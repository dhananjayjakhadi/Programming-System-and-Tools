#ifndef BST_H
#define BST_H
#define EMPTY 0
typedef struct data
{
        int value;
}Data;

typedef struct node
{
	Data data;
	struct node *left, *right, *parent;
}Node;

typedef struct tree {
	Node *root;
}Tree;

Node * createNode(Data d, Node * parent);
Tree * createTree();
Data * insert(Tree *, Data);
Data * insertNode(Node *node,Data value);
void sort(Tree *, Data *);
Data * search(Tree * tree , Data value);
Node * searchNode(Node * node,Data value);
int compare(Tree *t, Tree * copy);
Tree * clone(Tree *t);
void deleteTree(Tree * bst);
void removeData(Tree * bst, Data value);

#endif
