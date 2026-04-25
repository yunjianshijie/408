#include <stdio.h>
#include <stdbool.h>

#define Maxsize 50

typedef struct  ShStack{
    int data[Maxsize];
    int top0;
    int top1;
} ShStack;

void InitStack(ShStack * s){
    s->top0 = -1;
    s->top1 = Maxsize;
}


// 空表
bool StackEmpty(ShStack *s,int model)
{
    if(model== 0 && s->top0 ==-1 ){
        return true;
    }
    if(model ==1 && s->top1 == Maxsize ){
        return true;
    }
    return false;
}


// 入栈
bool Push(ShStack * s, int data,int model){
    if (s->top0 == s->top1-1){
        return false;
    }
    if(model == 0){
        s->data[++s->top0] =data;
        return true;
    }
    if(model == 1){
        s->data[--s->top1] =data;
        return true;
    }
    return false;
}

// 出战 
bool Pop(ShStack *s,int * data ,int model){
    if(model == 0&& s->top0 != -1 ){
        *data = s->data[s->top0--];
        return true;
    }
    if(model == 1 && s->top1 !=Maxsize){
        *data = s->data[s->top1++];
        return true;
    }
    return false;
}

// 
bool GetTop(ShStack *s, int *data ,int model){
    if (model == 0 && s->top0 != -1)
    {
        *data = s->data[s->top0];
        return true;
    }
    if (model == 1 && s->top1 != Maxsize)
    {
        *data = s->data[s->top1];
        return true;
    }
    return false;
}

void show(ShStack s){
    if(s.top0 ==-1){
        printf("栈0为空\n");
    }else{
        printf("栈0:");
        for(int i =0 ;i<= s.top0;i++){
            printf("%d  ",s.data[i]);
        }
        printf("\n");
    }
    if (s.top1 == Maxsize)
    {
        printf("栈1为空\n");
    }
    else
    {
        printf("栈1:");
        for (int i = Maxsize-1; i >=s.top1; i--)
        {
            printf("%d  ", s.data[i]);
        }
        printf("\n");
    }

}
int main(){
    ShStack s ;
    InitStack(&s);
    if(StackEmpty(&s,1)){
        printf("1为空\n");
    }
    Push(&s,1,1);
    int top =0;
    Pop(&s,&top,1);
    printf("top = %d \n",top);
    show(s);
    return 0;
}