#include <stdio.h>
#include <stdlib.h>

#define N 4 // 假设4阶对称矩阵

// 对四阶矩阵的压缩存储
int *com_4(int a[][N])
{
    int *result = (int *)malloc(sizeof(int) * N * (N + 1) / 2); // 需要 N*(N+1)/2 个元素来存储对称矩阵 (1+2+3+4=10)(求和公式)
    int index = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            result[index++] = a[i][j];
            // printf("%d : %d ",index ,a[i][j]);
        }
    } // 存储下三角部分（包括对角线）
    return result;
}

// 从压缩存储恢复原矩阵
int **restore(int *com)
{
    int **result = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        result[i] = (int *)malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++)
        {
            if (i < j)
            {                                            // 如果行小于列，是上半部分。
                result[i][j] = com[j * (j + 1) / 2 + i]; // k = j(j+1)/2 +i-1 (公式)  （这里是+1是因为坐标从0开始的）
            }
            else
            {                                            // 是下半部分
                result[i][j] = com[i * (i + 1) / 2 + j]; // k = i(i+1)/2 +j-1 (公式)
            }
        }
    }
    return result;
}

int get_index(int i, int j, int *com)
{
    if (i < j)
    {
        return com[j * (j + 1) / 2 + i];
    }
    else
    {
        return com[i * (i + 1) / 2 + j];
    }
}

// for (int i = 1; i <= N; i++)
// {
//     for (int j = 1; j <= N; j++)
//     {
//         int pos;
//         if (j <= i)
//             pos = i * (i - 1) / 2 + j - 1; // 转数组0下标
//         else
//             pos = j * (j - 1) / 2 + i - 1; // 用上三角对称点

//         printf("%d\t", arr[pos]);
//     }
//     printf("\n");
// }

void print_matrix(int **mat)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // 定义一个4阶对称矩阵
    int mat[N][N] = {
        {1, 2, 3, 4},
        {2, 5, 6, 7},
        {3, 6, 8, 9},
        {4, 7, 9, 10}};
    // 压缩存储
    int *com = com_4(mat);

    int **restored = restore(com);
    printf("恢复后的矩阵：\n");
    print_matrix(restored);
    return 0;
}