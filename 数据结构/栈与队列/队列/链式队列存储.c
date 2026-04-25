#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkNode{
    int data;
    struct LinkNode * next;
} LinkNode;

typedef struct 
{
    LinkNode *front ,*rear;
  
} LinkQueue;

void InitQueue(LinkQueue * q){
    q->front = (LinkNode *)malloc(sizeof(LinkNode));
    q->front->next =NULL;
    q->rear= NULL;
}

void EnQueue(LinkQueue * q ,int data){
    LinkNode * n = (LinkNode *)malloc(sizeof(LinkNode));
    n->data = data;
    n->next = NULL;
    if(q->front->next == NULL){
        q->rear =n;
        q->front->next = n;
    }else{
        q->rear->next =n;
        q->rear =n;
        printf("插入%d\n",data);
    }
}

bool DeQueue(LinkQueue * q ,int * data){
    if(q->front->next == NULL){
        return false ;
    }
    *data = q->front->data;

    LinkNode * del = q->front->next;
    *data = del->data;
    q->front->next = del->next;

    free(del);
}


void show(LinkQueue * q){
    LinkNode * n = q->front->next;
    while(n!= NULL){
        printf("%d  ",n->data);
        n=n->next;
    }
    printf("\n");
}




int main(){
    
    LinkQueue q;
    InitQueue(&q);
    EnQueue(&q, 1);
    EnQueue(&q, 2);
    EnQueue(&q, 3);
    EnQueue(&q, 4);
    show(&q);
    int data;
    DeQueue(&q ,&data);
    show(&q);
    return 0;
}
