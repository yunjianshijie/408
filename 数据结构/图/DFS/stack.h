#include <stdio.h>
#include <stdbool.h>

#define MaxSize 50
typedef struct
{
    int data[MaxSize];
    int top;
} Stack;

Stack * create_stack();

bool StackEmpty(Stack *s);
bool Push(Stack *s, int data);
bool Pop(Stack *s, int *data);
bool GetTop(Stack *s, int *data);