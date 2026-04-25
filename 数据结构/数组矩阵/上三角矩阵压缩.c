#include <stdio.h>
#include <stdlib.h>

#define N 4 // 假设4阶上三角矩阵

// 对四阶矩阵的压缩存储
int *com_4(int a[][N])
{
    // 需要 N*(N+1)/2 个元素来存储上三角矩阵 (1+2+3+4=10)(求和公式) + 最后常数项
    int *result = (int *)malloc(sizeof(int) * N * (N + 1) / 2 + 1); 
    int index = 0;
    for(int i =0 ;i<N ;i++){
        for(int j =i ;j<N ;j++){
            result[index++] = a[i][j];
        }
    }
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
            if (i <= j)
            {                                            // 如果行小于列，是上半部分。
                result[i][j] = com[(i * (2 * N - i + 1)) / 2 + j - i]; // k = (i-1)*(2*n-i+2)/2+(j-i)(公式)  （和公式不一样)这里是+1是因为坐标从0开始的）(
            }
            else
            {                                            // 是下半部分
                result[i][j] = com[(N+1)*N /2]; //常数项
            }
        }
    }
    return result;
}

int get_index(int i, int j, int *com)
{
    if (i <= j)
    {
        return com[(i * (2 * N - i + 1)) / 2 + j - i];
    }
    else
    {
        return com[(N+1)*N /2]; // 常数项
    }
}

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
    // 定义一个4阶上三角矩阵
    int mat[N][N] = {
        {1, 2, 3, 4},
        {0, 5, 6, 7},
        {0, 0, 8, 9},
        {0, 0, 0, 10}};
    // 压缩存储
    int *com = com_4(mat);

    int **restored = restore(com);
    printf("恢复后的矩阵：\n");
    print_matrix(restored);
    return 0;
}