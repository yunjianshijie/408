#include <stdio.h>
#include <stdbool.h>

#define MaxSzie 5
typedef struct
{
    int data[MaxSzie];
    int front, rear; // 队首，队尾
        // 队尾指针下一个位置为队首，是队满标准
} SqQueue;

//
void InitQueue(SqQueue *q)
{
    q->front = q->rear = 0;
}

int chu(int i){
    return i% MaxSzie;
}

bool Push(SqQueue *q, int data)
{
    if (chu(q->front) == chu( q->rear + 1))
    {
        printf("Push:队满\n");
        return false;
    }
    q->data[ chu(q->rear++)] = data; // 0 ,1
    printf("Push%d: %d\n", q->rear - 1, data);
    return true;
}

bool Pop(SqQueue *q, int *data)
{
    if(q->front == q->rear){
        printf("Push:队空");
        return false;
    }

    *data = q->data[chu(q->front++)];
    printf("POP %d:%d\n", q->front - 1, *data);
    return true;
}

void show(SqQueue *q)
{
    printf("队首：%d ,队尾:%d\n", q->front, q->rear);
    for (int i = q->front; i < q->rear; i++)
    {
        printf("%d ", q->data[i %MaxSzie]);
    }   
    printf("\n");
}

int main()
{
    SqQueue Q;
    InitQueue(&Q);
    Push(&Q, 1);
    Push(&Q, 2);
    int data;
    Pop(&Q, &data);
    // Pop(&Q, &data);
    // show(&Q);
    Push(&Q, 3);
    Push(&Q, 4);
    Push(&Q, 5);
    // Pop(&Q, &data);
    // Pop(&Q, &data);
    // Pop(&Q, &data);
    show(&Q);
}