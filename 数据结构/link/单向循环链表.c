#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    struct Node *next;
    int value;
}Node;
typedef struct Link
{
    Node * head;
    int size;    
} Link;

void InitLink(Link * l){
    l->head =(Node *)malloc(sizeof(Node));
    l->size =0;
    l->head->next =l->head;
}

void insert(Link * l , int v){
    Node * n = (Node *)malloc(sizeof(Node));
    n->next  = NULL;
    n->value = v;
    Node * prev = l->head;
    Node * curr = l->head->next;
    while(curr != l->head){
        prev =curr;
        curr =curr->next;
    }
    n->next =prev->next;
    prev->next =n;
    l->size++;
}

void del(Link *l ,int index){
    if(index <1 && index >=l->size){
        return;
    }
    int c =0;
    Node *prev =l->head;
    while(c< index -1){
        prev =prev->next;
        c++;
    }
    Node *curr =prev ->next;
    prev->next = curr->next;
    free(curr);
    l->size --;
}

void show(Link * l){
    Node * curr =l->head->next;
    while(curr!=l->head){
        printf (" %d",curr->value);
        curr= curr->next;
    }
}

int main(){
    Link l ;
    InitLink(&l);
    insert(&l,1);
    insert(&l,2);
    del(&l,2);
    show(&l);
}