#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

Node * createNode(Data d, Node *parent)
{
  Node *n = malloc(sizeof(Node));
  if(n == NULL) {
    exit(-1);
  } else {
    n->parent =NULL;
    n->left = NULL;
    n->right = NULL;
    n->data = d ;
  }
  return n;
}

Tree * createTree()
{
  Tree * t =  malloc(sizeof(Tree));
  if(t == NULL) {
    exit(-1);
  } else {
    t->root = NULL;
  }
  return t;
}

Data * insert(Tree * bst, Data value)
{

  if(bst->root == NULL)
  {
    Node * new_node = createNode(value, NULL);
    bst->root = new_node;
  } else {
    return insertNode(bst->root,value);
  }
}

Data * insertNode(Node *node,Data value){
  Node * current = node;
  Node * new_node = createNode(value, NULL);

  while( current != NULL){
    new_node->parent=current;
    if(new_node->data.value == current->data.value){
      free(new_node);
      new_node = NULL;
      return NULL;
    }

    if(new_node->data.value < current->data.value){
      current = current->left;
    }
    else{
      current = current->right;
    }
  }

  if(new_node->data.value < new_node->parent->data.value){
    new_node->parent->left = new_node;
  }
  else{
    new_node->parent->right = new_node;
  }
}

void sortAuxilary(Node *node, Data arr[], int *i){
  if(node == NULL)
  return ;
  sortAuxilary(node->left, arr, i);
  arr[*i] = node->data;
  ++*i;
  sortAuxilary(node->right, arr, i);
}

void sort(Tree *bst, Data *d)
{
  int array_start = 0;
  sortAuxilary(bst->root,d,&array_start);
}

Data * search(Tree * tree,Data value) {
  if(tree->root == NULL)
  return NULL;
  else
  return &searchNode(tree->root,value)->data;
}

Node * searchNode(Node * node,Data value) {
  if(node == NULL)
  return NULL;

  if(node->data.value == value.value)
  return node;
  else if(value.value < node->data.value)
  return searchNode(node->left,value);
  else
  return searchNode(node->right,value);
}


int compareTrees(struct node * tree1, struct node * tree2) {
  if(tree1==NULL && tree2==NULL) return(1);
  else if (tree1 !=NULL && tree2 !=NULL) {
    return(tree1->data.value == tree2->data.value &&
      compareTrees(tree1->left, tree2->left) &&
      compareTrees(tree1->right, tree2->right)
    );

  }
  else return(0);
}
int compare(Tree * t, Tree * copy)
{
  if( t != NULL && copy != NULL){
    return compareTrees(t->root,copy->root);
  }
  else if(t == NULL && copy == NULL)
  return 1;
  else if(t == NULL || copy == NULL)
  return 0;
}

void preordert(Node *n, Tree * tree)
{
  if(n != NULL){
    insert(tree, n->data);
    preordert(n->left,tree);
    preordert(n->right,tree);
  } else return;
}

Tree * clone(Tree *t)
{
  Tree * new = createTree();
  preordert(t->root,new);
  return new;
}

void removeData(Tree *bst, Data value){

  Node *node1;
  node1=search(bst,value);

  if(node1==NULL){
    return ;
  }
  else{
    if(node1->left==NULL && node1->right==NULL){
      removeLeaf(bst,node1);
    }
    else{
      if(node1->left==NULL || node1->right==NULL){
        if (bst->root->data.value == node1->data.value) {
        }
        shortCircuit(bst,node1);
      }
      else{
        if (bst->root->data.value == node1->data.value) {
        }
        promotion(bst,node1);
      }
    }
  }
}
void removeLeaf(Tree *bst, Node *d_node){
  if(bst->root==d_node)
  {
    free(d_node);
    d_node=NULL;
    bst->root=NULL;
  }
  else{
    if(d_node->parent->right==d_node){
      d_node->parent->right=NULL;
      free(d_node);
      d_node=NULL;
    }
    else{
      d_node->parent->left=NULL;
      free(d_node);
      d_node=NULL;
    }
  }
}

void shortCircuit(Tree *bst, Node *d_node){
  if (d_node->data.value == bst->root->data.value) {
    if (d_node->left != NULL) {
      bst->root = d_node->left;
      free(d_node);
      d_node = NULL;
    } else{
      bst->root = d_node->right;
      free(d_node);
      d_node = NULL;
    }
    return;
  }
  if(d_node->parent->left==d_node){
    if(d_node->left==NULL){
      d_node->parent->left=d_node->right;
      d_node->parent->left->parent = d_node->parent;
    }
    else{
      d_node->parent->left=d_node->left;
      d_node->parent->left->parent = d_node->parent;
    }
  }
  else{
    if(d_node->left==NULL){
      d_node->parent->right=d_node->right;
      d_node->parent->right->parent = d_node->parent;
    }
    else{
      d_node->parent->right=d_node->left;
      d_node->parent->right->parent = d_node->parent;
    }

  }
  free(d_node);
  d_node=NULL;
}

void promotion(Tree *bst, Node *d_node){
  if (d_node->data.value == bst->root->data.value) {
    bst->root = d_node;
  }
  Node *current = d_node->right;

  while (current->left != NULL) {
    current = current->left;
  }
  d_node->data = current->data;

  if (current->left == NULL && current->right == NULL) {
    removeLeaf(bst, current);
    return;
  }

  if (current->left == NULL || current->right == NULL) {
    shortCircuit(bst, current);
    return;
  }
}


void  deleteAux(Node *n, Tree * t){
  if (n != NULL) {
    deleteAux(n->left,t);
    deleteAux(n->right,t);
    free(n);
    n = NULL;
  }


}
void deleteTree(Tree* bst){
  deleteAux(bst->root,bst);
  free(bst);
  bst = NULL;
}
