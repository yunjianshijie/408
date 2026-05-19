
#include "queue.h"
#include <stdlib.h>
SqQueue *creat_queue(){
    SqQueue * q = (SqQueue *)malloc(sizeof(SqQueue));
    InitQueue(q);
    return q;
}

void InitQueue(SqQueue *q)
{
    q->front = q->rear = 0;
}

int chu(int i)
{
    return i % MaxSzie;
}

bool EnQueue(SqQueue *q, int data)
{
    if (chu(q->front) == chu(q->rear + 1))
    {
        // printf("Push:队满\n");
        return false;
    }
    q->data[chu(q->rear++)] = data; // 0 ,1
    // printf("Push%d: %d\n", q->rear - 1, data);
    return true;
}

bool Pop(SqQueue *q, int *data)
{
    if (q->front == q->rear)
    {
    //    printf("Push:队空");
        return false;
    }

    *data = q->data[chu(q->front++)];
    // printf("POP %d:%d\n", q->front - 1, *data);
    return true;
}
int DeQueue(SqQueue *q){
    if (q->front == q->rear)
    {
        // printf("Push:队空");
        return -1;
    }

    int data = q->data[chu(q->front++)];
    // printf("POP %d:%d\n", q->front - 1, *data);
    return data;
}

bool Queue_Empty(SqQueue * q){
    if(q->front == q->rear){
        return true;
    }
    return false;

}

void queue_show(SqQueue *q)
{
    printf("队首：%d ,队尾:%d\n", q->front, q->rear);
    for (int i = q->front; i < q->rear; i++)
    {
        printf("%d ", q->data[i % MaxSzie]);
    }
    printf("\n");
}
