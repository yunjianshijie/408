#include <stdio.h>
#include <stdlib.h>

// 最大顶点数
#define MAXVEX 100
// 用无穷大表示无边（这里用 65535，符合 408 标准）
#define INF 65535

// 邻接矩阵存储的图结构
typedef struct
{
    // 顶点数组
    int vexs[MAXVEX];
    // 邻接矩阵
    int arc[MAXVEX][MAXVEX];
    // 顶点数、边数
    int numVertexes, numEdges;
} MGraph;

// 创建无向网图（邻接矩阵）
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("请输入顶点数和边数：");
    scanf("%d%d", &G->numVertexes, &G->numEdges);

    // 初始化顶点
    for (i = 0; i < G->numVertexes; i++)
    {
        G->vexs[i] = i;
    }

    // 初始化邻接矩阵：全部为无穷大
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = INF;
        }
    }

    // 读入边信息
    for (k = 0; k < G->numEdges; k++)
    {
        printf("输入边(vi, vj)的下标 i, j 和权值 w：");
        scanf("%d%d%d", &i, &j, &w);
        // 无向图，对称赋值
        G->arc[i][j] = w;
        G->arc[j][i] = w;
    }
}

// Prim 算法：生成最小生成树
void Prim(MGraph *G)
{
    // 保存最小权值
    int lowcost[MAXVEX];
    // 保存当前顶点的前驱节点（表示边：adjvex[i] -> i）
    int adjvex[MAXVEX];
    // 总权值和
    int sum = 0;

    int i, j, k;
    // 从 0 号顶点开始生成
    int v0 = 0;

    // 1. 初始化
    for (i = 0; i < G->numVertexes; i++)
    {
        // lowcost[i] = 0 号顶点到 i 的权值
        lowcost[i] = G->arc[v0][i];
        // 所有顶点的前驱初始化为 0
        adjvex[i] = v0;
    }
    // 起点自己的权值设为 0，表示已加入生成树
    lowcost[v0] = 0;

    // 2. 循环 n-1 次，把剩下 n-1 个顶点加入树
    for (i = 1; i < G->numVertexes; i++)
    {
        int min = INF;
        k = 0;

        // 找到权值最小的顶点 k
        for (j = 0; j < G->numVertexes; j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        }

        // 输出这条边：adjvex[k] -> k
        printf("边：%d -> %d，权值：%d\n", adjvex[k], k, min);
        sum += min;

        // 把 k 加入生成树（权值置 0）
        lowcost[k] = 0;

        // 更新 lowcost 和 adjvex
        for (j = 0; j < G->numVertexes; j++)
        {
            if (lowcost[j] != 0 && G->arc[k][j] < lowcost[j])
            {
                lowcost[j] = G->arc[k][j];
                adjvex[j] = k;
            }
        }
    }

    printf("最小生成树总权值：%d\n", sum);
}

int main()
{
    MGraph G;
    CreateMGraph(&G);
    printf("\n最小生成树（Prim 算法）：\n");
    Prim(&G);
    return 0;
}