#include <stdio.h>
#include <stdbool.h>

#define Max 10

int you(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return 2;
}

void cover(char *str, char *ret)
{
    int i = 0;
    char sk[Max];
    int top = -1;
    int curr = -1;
    while (str[i] != '\0')
    {
        if ('0' <= str[i] && '9' >= str[i])
        {
            printf("%c", str[i]);
        }
        else
        {
            // 如果遇到* /存入 st如果遇到的 没有和 优先级低的 ，直接输出，
            // 如果栈顶是 * / 就是出之前那个。
            while (top != -1 && you(sk[top]) >= you(str[i])) //
            {
                printf("%c", sk[top--]);
            } 
            sk[++top] = str[i];
            // if (top != -1 && you(str[i])==1)
            // {
            //     //如果是+ -的话把栈都放出来
            //      while (top!=-1)
            //      {
            //         printf("%c",sk[top--]);
            //      }
            // }else if(top != -1 && you(str[i]) == 2 && you(sk[top]) == 2){
            //     // 这个直接进栈
            // }
            // sk[++top] = str[i];
           
        }
        i++;
    }
    // 把栈里面的东西放
    while (top != -1)
    {
        printf("%c", sk[top--]);
    }
}

int main()
{
    cover("1+3*5*6-2", NULL);
}