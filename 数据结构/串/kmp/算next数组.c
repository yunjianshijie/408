#include <stdio.h>
#include <string.h>

char *longestPrefix(char *s)
{
    int len = strlen(s);
    static int next[100001]; // 静态数组，避免栈溢出

    next[0] = 0;
    int i = 1;
    int p_len = 0;

    while (i < len)
    {
        if (s[i] == s[p_len])
        {
            p_len++;
            next[i++] = p_len;
        }
        else if (p_len == 0)
        {
            next[i++] = 0;
        }
        else
        {
            p_len = next[p_len - 1];
        }
    }

    int size = next[len - 1];

    static char res[100001];
    strncpy(res, s, size);
    res[size] = '\0';

    return res;
}

int main()
{
    char s[100001];
    printf("请输入字符串：");
    scanf("%s", s);

    char *ans = longestPrefix(s);
    printf("最长相等前后缀：%s\n", ans);

    return 0;
}