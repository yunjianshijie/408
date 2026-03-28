#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Node{
    int value;
    struct Node * next;
}Node;

void insert(int v, Node * head){


    Node * n = (Node *)malloc(sizeof(Node));
    n->value = v;
    n->next =NULL;
    Node * last = head;
    while(last->next != NULL){
        last = last ->next;
    }
    last->next =n;
}

void show(Node * head){
    Node * now = head->next;
    printf("head ->");
    while(now!=NULL){
        printf("%d ->",now->value);
        now =now ->next;
    }
    printf("NULL\n");
} 

void init(Node *head){
    head ->next =NULL;
    head ->value = -1;
}

bool dev(int v,Node * head ){
    // Node * h =head;
    // while(h->next !=NULL){
    //     if (h->next->value == v){
    //         break;
    //     }
    //     h = h->next;
    // }
    // if (h->next->value!= v){
    //     return false;
    // }
    // // 前驱
    // Node *tmp =h->next;
    // h->next =tmp ->next;
    // free(tmp);
    // return true;

    if(head ==NULL){
        return;
    }
    Node * del = head;
    Node *


}

int main(){
    Node head;
    init(&head);
    insert(11 ,&head); 
    insert(22 ,&head);
    dev(22,&head);
    dev(1,&head);
    show(&head);
    return 0;
}



