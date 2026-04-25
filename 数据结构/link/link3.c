#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
typedef struct Link{
    int size;
    Node * head ;
    Node * last;
}Link;

Link* create_link(){
    Link* link = (Link *)malloc(sizeof(Link));
    link->head =NULL;
    link->last =NULL;
    link->size = 0;
}

void  insert(int v,Link * link){
    Node * n = (Node *)malloc(sizeof(Node));
    n->value = v ;
    n->next = NULL;
    link-> size++;
    if(link->head == NULL){
        link ->head =n;
        link ->last =n;
        return;
    }
    link->last->next =n;
    link->last =n;
}

// 从1给index开始
void dev(int index,Link *link){
    Node * head = link->head;
    if (index > link->size && index <1 ){
        return ;
    }
    if( index == 1 ){
        if(link->size ==1){
            link->head =NULL;
            link->last = NULL;
        }else{
            link->head =head->next;
        }
        free(head);
        link->size--;
        return;
    }
    Node *del =head;
    Node *prev =NULL;
     for (int i = 0; i < index-1 ; i++)
    {
        prev =del;
        del=del->next;
    }
    prev->next =del->next;
    if(del->next==NULL){
        link->last =prev;
    }
    free(del);
    link->size--;
}
void show(Node *head)
{
    while (head != NULL && head->value != -888)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Link * link = create_link();
    insert(11,link);
    insert(22,link);
    insert(33,link);
    dev(3,link);
    dev(2,link);
    dev(1,link);
    show(link->head);
}
