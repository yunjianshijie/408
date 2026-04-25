#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define MAXSIZE 20


typedef int Element;
typedef struct Queue
{
    Element * data;
    int index;
} Queue;

Queue * create_queue(int size){
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q->data = (Element *)malloc(sizeof(Element)*size);
    q->index = 0;
    return q;
}

void enqueue(Element e, Queue *q){
    q->data[q->index] =e;
    q->index++;
}

Element chu( Queue *q)
{
    Element e = q->data[0];
    for(int i =0 ;i<q->index-1 ;i++){
        q->data[i] = q->data[i+1];
    }
    q->index--;
    return e;
}

bool full(Queue *q)
{
    if(q->index == MAXSIZE){
        return true;
    }
    return false;
}

bool iffree(Queue *q)
{
    if (q->index == 0)
    {
        return true;
    }
    return false;
}

int main(){
    // 数到3
    Queue * q =create_queue(20);
    for(int i = 1 ;i<=10 ;i++){
        enqueue(i,q);
    }
    int n =10;
    int count =0;
    while (n!= 1)
    {
        count ++;
        if(count ==3){
            chu(q);
            count = 0;
            n--;
            continue;
        }
        
        enqueue(chu(q),q);
    }

    
}   

// 创建链式类栈，10个node 不释放

// 数据压缩算法


