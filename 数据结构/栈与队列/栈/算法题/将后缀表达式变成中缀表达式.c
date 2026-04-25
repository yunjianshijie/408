#include <stdio.h>
#include <stdbool.h>

// 力扣150

bool isNumber(char *token)
{
    return strlen(token) > 1 || ('0' <= token[0] && token[0] <= '9');
}

int evalRPN(char **tokens, int tokensSize)
{

    int sk[10001];
    int top = -1;
    int ret = 0;
    if (tokensSize == 1)
    {
        return atoi(tokens[0]);
    }

    for (int i = 0; i < tokensSize; i++)
    {
        if (isNumber(tokens[i]))
        {
            sk[++top] = atoi(tokens[i]);
        }
        else
        {
            int num2 = sk[--top];
            int num1 = sk[--top];
            switch (tokens[i][0])
            {
            case '+':
                sk[top++] = num1 + num2;
                break;
            case '-':
                sk[top++] = num1 - num2;
                break;
            case '*':
                sk[top++] = num1 * num2;
                break;
            case '/':
                sk[top++] = num1 / num2;
                break;
            }


            // 这里写的不好：
            // if (tokens[i][0] == '+')
            // {
            //     ret = sk[top] + sk[top - 1];
            //     sk[top - 1] = ret;
            //     top--;
            // }
            // else if (tokens[i][0] == '-')
            // {
            //     ret = sk[top - 1] - sk[top];
            //     sk[top - 1] = ret;
            //     top--;
            // }
            // else if (tokens[i][0] == '*')
            // {
            //     ret = sk[top - 1] * sk[top];
            //     sk[top - 1] = ret;
            //     top--;
            // }
            // else
            // {
            //     ret = sk[top - 1] / sk[top];
            //     sk[top - 1] = ret;
            //     top--;
            // }
        }
    }
    return ret;
}