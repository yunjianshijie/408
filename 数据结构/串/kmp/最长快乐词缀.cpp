#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    string longestPrefix(string s)
    {
        // 算next,
        int len = s.size();
        int next[100001];

        next[0] = 0;   // 第一个
        int i = 1;     // 当前标点
        int p_len = 0; // 前缀长度

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

        return s.substr(0, size);
    }
};