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
Node *insert(int v, Node *h)
{
    
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = v;
    n->next = NULL;
    if (h ==NULL){
        return n;
    }
    Node *last = h;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = n;
    return h;
}
void show(Node *head)
{
    while (head != NULL&& head->value!= -888)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
Node * del_value(int v, Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if( head->value == v){
        Node * next = head->next;
        free(head);
        return next;
    }
    Node *del = head;
    Node *prev = NULL;
    while (del!= NULL && del->value != v )
    {
        prev = del;
        del = del->next;
    }
    if (del == NULL){
        return head ;
    }
    prev->next = del->next;
    free(del);
    return head;
}

int main()
{
    Node * head = NULL;
    head = insert(11, head);
    head = insert(12, head);
    head = insert(13, head);
    head = insert(14, head);
    head = del_value(11, head);
    show(head);
}
