#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
void init(Node *head)
{
    head->value = -888;
    head->next = NULL;
}
void insert(int v, Node *h)
{
    if (h->value == -888)
    { // 处理头节点
        h->value = v;
        return;
    }
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = v;
    n->next = NULL;
    Node *last = h;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = n;
}
void show(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
void del_value(int v, Node *head)
{
    if (head == NULL)
    {
        return;
    }
    if( head->value == v){
        head->value =-888;
        return;
    }
    Node *del = head;
    Node *prev = NULL;
    while (del!= NULL && del->value != v )
    {
        prev = del;
        del = del->next;
    }
    if (del == NULL){
        return;
    }
    prev->next = del->next;
    free(del);
}

int main()
{
    Node head;
    init(&head);
    insert(11, &head);
    insert(12, &head);
    insert(13, &head);
    insert(14, &head);
    del_value(15,&head);
    show(&head);
}
