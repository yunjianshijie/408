#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;          
    struct Node *prev; 
    struct Node *next;
} Node;


typedef struct
{
    Node *top;       
    Node *head;  
    int used_pre;      
} Stack;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 初始化
void initStack(Stack *stack)
{
    stack->top = NULL;
    stack->head = NULL;
    stack->used_pre = 0;
    for (int i = 0; i < 10; i++)
    {
        Node *node = createNode(0);
        // 头插
        node->next = stack->head;
        if (stack->head)
        {
            stack->head->prev = node;
        }
        stack->head = node;
    }
}

// 入栈
void push(Stack *stack, int val)
{
    Node *newNode;

    if (stack->used_pre < 10)
    {
        newNode = stack->head;
        stack->head = stack->head->next; 
        if (stack->head)
        {
            stack->head->prev = NULL;
        }
        stack->used_pre++; 
        newNode->data = val;
    } else {
        newNode = createNode(val);
    }
    // 双向链表栈顶插入
    newNode->next = stack->top;
    if (stack->top)
    {
        stack->top->prev = newNode;
    }
    stack->top = newNode;

    printf("入栈：%d\n", val);
}

// 出栈
int pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("栈空，出栈失败！\n");
        return -1;
    }

    Node *temp = stack->top;
    int val = temp->data;
    // 栈顶指针后移
    stack->top = stack->top->next;
    if (stack->top)
    {
        stack->top->prev = NULL;
    }

    if (stack->used_pre > 0)
    {
        temp->next = stack->head;
        if (stack->head)
        {
            stack->head->prev = temp;
        }
        stack->head = temp;
        stack->used_pre--;
    }
    else
    {
        free(temp);
    }

    printf("出栈：%d\n", val);
    return val;
}

// 遍历栈 
void traverseStack(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("栈为空！\n");
        return;
    }
    Node *p = stack->top;
    printf("栈元素（栈顶->栈底）：");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Stack stack;
    initStack(&stack);

    for (int i = 1; i <= 10; i++)
    {
        push(&stack, i);
    }
    traverseStack(&stack);
    push(&stack, 11);
    traverseStack(&stack);

    for (int i = 0; i < 11; i++)
    {
        pop(&stack);
    }
    traverseStack(&stack);

    // destroyStack(&stack);
    return 0;
}