#include <stdio.h>
#include <stdlib.h>
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
    link->head = NULL;
    link->last = NULL;
    link->size = 0;
    return link;
}
void insert(int v, Link *link)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = v;
    n->next = NULL;
    link->size++;
    if (link->head == NULL)
    {
        link->head = n;
        link->last = n;
        return;
    }
    link->last->next = n;
    link->last = n;
}
void del_index(int index, Link *link)
{
    if (index < 1 || index > link->size)
    {
        return;
    }
    int c = 1;
    Node *del = link->head;
    Node *prev = NULL;
    while (c < index)
    {
        prev = del;
        del = del->next;
        c++;
    }
    if (prev == NULL)
    {
        Node *n = link->head;
        if (n == link->last)
        {
            link->last = NULL;
        }
        link->head = n->next;
        free(n);
    }
    else
    {
        prev->next = del->next;
        if (del == link->last)
        {
            link->last = prev;
        }
        free(del);
    }
    link->size--;
}

void del_odd(Link *link)
{
    Node *h = link->head;
    if (h == NULL)
    {
        return;
    }
    Node *prev = h;
    Node *del;
    while (prev != NULL && prev->next != NULL)
    {
        del = prev->next;
        prev->next = del->next;
        free(del);
        prev = prev->next;
    }
}

void del_e(Link *link) {
    Node *h =link ->head;
    if(h == NULL){
    return ;
    }
    h = h->next;
    link->head =h;
    Node *prev = h;
    Node *del;
    while (prev != NULL && prev->next != NULL)
    {
        del = prev->next;
        prev->next = del->next;
        free(del);
        prev = prev->next;
    }
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
    Link *link1 = create_link();
    // 11 22 33 44 55 66 77 88 99
    insert(11, link1);
    insert(22, link1);
    insert(33, link1);
    insert(44, link1);
    insert(55, link1);
    insert(66, link1);
    insert(77, link1);
    insert(88, link1);
    insert(99, link1);
    del_e(link1);
    show(link1->head);
}
