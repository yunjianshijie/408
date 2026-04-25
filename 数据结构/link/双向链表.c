#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    Node * prev;
    Node * next;
    int value;
} Node;

typedef struct DoubleLink{
Node * head;
}DLink;

void insert_last(int v,  DLink * d){

    Node * curr = d->head;
    while(curr->next !=NULL){
        curr =curr ->next ;
    }
    Node* n =(Node *)malloc(sizeof(Node));
    n->value = v;
    n->next =NULL;
    n->prev =curr;
    curr->next =n;
}
void del_index(int index,DLink * d){
    int c =1;
    Node * curr = d->head->next;
    while(c<index && curr!=NULL){
        curr =curr->next;
    }
    if(curr ==NULL){
        return;
    }
    curr->prev->next =curr->next;
    curr->next->prev= curr->prev;
    free(curr);

}