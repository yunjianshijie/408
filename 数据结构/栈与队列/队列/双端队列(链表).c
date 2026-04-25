#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 力扣 641

typedef struct Node
{
    struct Node *next;
    struct Node *perv;
    int data;
} Node;

typedef struct
{
    Node *head;
    Node *rear;
    int maxsize;
    int size;
} MyCircularDeque;

bool myCircularDequeIsEmpty(MyCircularDeque *obj);
bool myCircularDequeIsFull(MyCircularDeque *obj);
MyCircularDeque *myCircularDequeCreate(int k)
{
    MyCircularDeque *ret = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
    ret->maxsize = k;
    ret->size = 0;
    ret->head = (Node *)malloc(sizeof(Node));
    // 链表不需要循环
    ret->head->next = NULL;
    ret->rear = ret->head;
    return ret;
}

bool myCircularDequeInsertFront(MyCircularDeque *obj, int value)
{
    if (obj->size == obj->maxsize)
    {
        return false;
    }
    // 头插
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = value;

    n->next = obj->head->next;
    n->perv = obj->head;
    if (obj->head->next != NULL)
    {
        obj->head->next->perv = n;
    }
    if (obj->rear == obj->head)
    {
        obj->rear = n;
    }
    obj->head->next = n;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque *obj, int value)
{
    if (obj->size == obj->maxsize)
    {
        return false;
    }
    obj->size++;
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = value;

    n->next = NULL;
    n->perv = obj->rear;

    obj->rear->next = n;

    obj->rear = n;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque *obj)
{
    if (myCircularDequeIsEmpty(obj))
    {
        return false;
    }
    obj->size--;
    // 头删
    Node *del = obj->head->next;
    obj->head->next = del->next;
    if (obj->size == 0)
    {
        obj->rear = obj->head;
    }
    else
        del->next->perv = obj->head;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque *obj)
{
    // 尾删
    if (myCircularDequeIsEmpty(obj))
    {
        return false;
    }
    obj->size--;
    //
    Node *rear = obj->rear;

    rear->perv->next = NULL;
    obj->rear = rear->perv;
    free(rear);
    return true;
}

int myCircularDequeGetFront(MyCircularDeque *obj)
{
    if (obj->size == 0)
    {
        return -1;
    }
    return obj->head->next->data;
}

int myCircularDequeGetRear(MyCircularDeque *obj)
{
    if (obj->size == 0)
    {
        return -1;
    }
    return obj->rear->data;
}

bool myCircularDequeIsEmpty(MyCircularDeque *obj)
{
    if (obj->size == 0)
        return true;
    return false;
}

bool myCircularDequeIsFull(MyCircularDeque *obj)
{
    if (obj->size == obj->maxsize)
    {
        return true;
    }
    return false;
}

void myCircularDequeFree(MyCircularDeque *obj)
{
}
