#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSzie 5
typedef struct
{
    int data[MaxSzie];
    int front, rear; // 队首，队尾
                     // 队尾指针下一个位置为队首，是队满标准
} SqQueue;


SqQueue* creat_queue();
void InitQueue(SqQueue *q);
bool EnQueue(SqQueue *q, int data);
bool Pop(SqQueue *q, int *data);
int  DeQueue(SqQueue *q);
void queue_show(SqQueue *q);
bool Queue_Empty(SqQueue *q);