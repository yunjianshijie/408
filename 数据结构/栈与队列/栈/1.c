#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int Element;

#define ERROR -2 
#define MaxSize 30

typedef struct Stack
{
    Element data[MaxSize];
    Element top;
} Stack;

//

Stack *Create()
{
    Stack * s =(Stack *)malloc(sizeof(Stack));
    for(int i = 0;i<MaxSize ;i++){
        s->data[i] = -100;
    }
    s->top = -1;
    return s;
}

bool isEmpty(Stack *s)
{
    // 如果是空栈
    if (s->top == -1)
    {
        return true;
    }
    return false;
}
bool isFull(Stack * s){
    if(s->top == MaxSize -1){
        return true;        
    }
    return false;
}

// 入栈
bool Push(Stack *s, Element data)
{
    //
    if (isFull(s))
    {
        return false;
    }
    s->data[++ s->top] = data;
    return true;
}

// 出栈
int Pop(Stack *s)
{
    if (isEmpty(s))
    {
        return ERROR;
    }
    return s->data[s->top--];
}
// 读取栈顶元素
int GetTop(Stack *s)
{
    if (isEmpty(s))
    {
        return ERROR;
    }
    return s->data[s->top];
}

int main(int argc, char const *argv[])
{
    Stack *s = Create();
    for(int i =0 ;i< 21 ;i++){
        Push(s,i+1);
        printf("{}%d \n ", i+1);
    }
    for(int i =0;i<20;i++){
        printf("{%d}%d \n ",i,Pop(s));
    }

 
    return 0;
}
