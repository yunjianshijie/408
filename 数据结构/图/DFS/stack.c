#include "stack.h"

void InitStack(Stack *s);


Stack * create_stack(){
    Stack * sk = (Stack *)malloc(sizeof(Stack));
    InitStack(sk);
    return sk;
}


void InitStack(Stack *s)
{
    s->top = -1;
}

bool StackEmpty(Stack *s)
{
    // 如果是空栈
    if (s->top == -1)
    {
        return true;
    }
    return false;
}

// 入栈
bool Push(Stack *s, int data)
{
    //
    if (s->top == MaxSize - 1)
    {
        return false;
    }
    s->top++;
    s->data[s->top] = data;
    return true;
}

// 出栈
bool Pop(Stack *s, int *data)
{
    //
    if (s->top == -1)
    {
        return false;
    }
    *data = s->data[s->top];
    s->top--;
    return true;
}
// 读取栈顶元素
bool GetTop(Stack *s, int *data)
{
    //
    if (s->top == -1)
    {
        return false;
    }
    *data = s->data[s->top];
    return true;
}

