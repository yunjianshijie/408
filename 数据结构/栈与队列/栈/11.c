
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef char Element;

#define ERROR -2
#define MaxSize 30

typedef struct Stack
{
    Element data[MaxSize];
    int top;
} Stack;

//

Stack *Create()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    for (int i = 0; i < MaxSize; i++)
    {
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
bool isFull(Stack *s)
{
    if (s->top == MaxSize - 1)
    {
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
    s->data[++s->top] = data;
    return true;
}

// 出栈
Element Pop(Stack *s)
{
    if (isEmpty(s))
    {
        return ERROR;
    }
    return s->data[s->top--];
}
// 读取栈顶元素
Element GetTop(Stack *s)
{
    if (isEmpty(s))
    {
        return ERROR;
    }
    return s->data[s->top];
}

void cover(char *str, char *ret)
{
    int i = 0;
    char f;
    Stack *sta = Create();
    int j = 0;
    while (str[i] != '\0')
    {
        if ('0' <= str[i] && '9' >= str[i])
        {
            //  printf("%c", str[i]);
            ret[j++] = str[i];
        }
        else
        {
            f = GetTop(sta);
            if (str[i] == '(')
            {
                Push(sta, str[i]);
            }
            else if (str[i] == ')')
            {
                char s;
                while ((s = Pop(sta)) != '(')
                {
                    ret[j++] = s;
                    // printf("%c",s);
                }
            }
            else if (str[i] == '+' || str[i] == '-')
            {
                while (!isEmpty(sta) && (GetTop(sta) != '('))
                {
                    // printf("%c",Pop(sta));
                    ret[j++] = Pop(sta);
                }
                Push(sta, str[i]);
            }
            else if (f == '*' || f == '/')
            {
                //  printf("c",Pop(sta));
                ret[j++] = Pop(sta);
                Push(sta, str[i]);
            }
            else
            {
                Push(sta, str[i]);
            }
        }
        i++;
    }
    while (!isEmpty(sta))
    {
        ret[j++] = Pop(sta);
    }
    ret[j] = '\0';
}

int cal(char *str)
{
    Stack *stk = Create();
    for (int i = 0;  str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            Push(stk , str[i]-'0');
        }
        else
        {
            int num1 = Pop(stk) ;
            int num2 = Pop(stk) ;
            switch (str[i])
            {
            case '+':
                Push(stk, num1 + num2);
                break;
            case '-':
                Push(stk, num1 - num2);
                break;
            case '*':
                Push(stk, num1 * num2);
                break;
            case '/':
                Push(stk, num1 / num2);
                break;
            }
        }
    }
    int ret = Pop(stk);
    free(stk);
    return ret;
}

int main()
{
    char a[30];
    cover("(1+3)*6", a);
    printf("%s",a);
    printf("\n%d\n",cal(a));
}