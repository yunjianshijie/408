#include<stdio.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct linkStack
{
    struct Node *head;
    int size;
}LinkStack;

void InitStack(LinkStack * s){
    s->head = (Node*)malloc(sizeof(Node));
    s->size =0;
    s->head->next =NULL;
}

bool Push(LinkStack * s, int data){
    s->size ++;
    Node * n =(Node *)malloc(sizeof(Node));
    n->data =data;
    n->next =s->head->next;
    s->head->next =n;
    return true;
}

bool Pop(LinkStack *s ,int *data){
    if(s->size == 0){
        return false;
    }
    s->size --;
    Node * del = s->head->next;
    s->head->next =del->next;
    *data = del->data;
    free(del);
    return true;
}

bool GetTop(LinkStack *s ,int *data){
    if (s->size == 0)
    {
        return false;
    }
    *data = s->head->next->data;
    return true;
}

int main(){

}