#include<stdio.h>
#include<stdbool.h>


#define MaxSize 50 
typedef struct {
    int data[MaxSize];
    int top;
}SqStack;

//

void InitStack(SqStack * s){
    s->top =-1;
}

bool StackEmpty(SqStack * s){
    //如果是空栈
    if(s->top == -1){
        return true;
    }
    return false;
}

//入栈
bool Push(SqStack *s,int data){
    // 
    if(s->top == MaxSize -1){
        return false;
    }
    s->top++;
    s->data[s->top]=data;
    return true;
}

// 出栈
bool Pop(SqStack *s,int * data){
    // 
    if(s->top == -1){
        return false;
    }
    *data = s->data[s->top];
    s->top --;
    return true;
}
//读取栈顶元素
bool GetTop(SqStack *s,int * data){
    //
    if (s->top == -1)
    {
        return false;
    }
    *data = s->data[s->top];
    return true;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

