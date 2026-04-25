#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
typedef struct LinkTable
{
    Node *head;
    Node *last;
    int size;
} Link;
Link *create_link()
{
    Link *link = (Link *)malloc(sizeof(Link));
    link ->head = (Node *)malloc(sizeof(Node));
    link->last = link->head;
    link ->head->next = NULL;
    link->size = 0;
    return link;
}
void insert(int v, Link *link)
{
   Node *n = (Node * )malloc(sizeof(Node));
    n->next =NULL;
    n->value = v;
    link->last->next =n;
    link->last = n;
}

void del_index(int index, Link *link)
{
    // index是从第一个开始
    int c = 0;
    Node * h = link ->head->next;
    Node * pev =link ->head;
    if(index >= link ->size || index <1 ){
        return ;
    }
    // 如果index用while循环，请在条件中写c !（）
    while(c <index-1){
        pev = h;
        h =h->next;
        c++;
    }
    link->size --;
    pev->next =  h ->next;
    if(h== link->last){
        link->last =NULL;
    }
    free(h);
}
void show(Link * link){
    Node *h  =link->head->next;
    while(h!=NULL){
        printf("%d  ",h->value);
        h= h->next;
    }
}

void ff(Link * link){
    //逆转链表
    // 改头
    if (link->head == NULL || link->head->next == NULL){
        return;
    }
    Node *old_first = link->head->next;
    Node *curr = link->head->next;
    Node *qian =NULL;
    Node * next = NULL;

    while(curr !=NULL ){
        next = curr->next;
        curr->next=qian;
        qian = curr;
        curr = next;
    }
   
    link->head->next = qian; 
    link ->last =old_first; 
}
void reverse(Link * link){
    Node *n  = link->head;
    link ->head = NULL;
    while (n!=NULL)
    {   
        Node * w = n->next;
        n->next = link->head;
        link->head = n;
        n=w;
    }
    
}
bool f_c(Link * link){
    Node * slow = link->head;
    Node * fast = slow;
    while(fast !=NULL && fast ->next != NULL){
        fast =fast->next->next;
        slow =slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}


int main()
{
    Link *link = create_link();
    // 11 22 33 44 55 66 77 88 99
    insert(11, link);
    insert(22, link);
    insert(33, link);
    reverse(link);
    show(link);
}
