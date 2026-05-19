#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100 // 最大顶点数
#define INF 65535  // 无穷大（表示无边）

// 邻接矩阵存储图
typedef struct
{
    int vexs[MAXVEX];          // 顶点表
    int arc[MAXVEX][MAXVEX];   // 邻接矩阵
    int numVertexes, numEdges; // 顶点数、边数
} MGraph;

// 创建无向网图（邻接矩阵）
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("请输入顶点数和边数：");
    scanf("%d%d", &G->numVertexes, &G->numEdges);

    // 初始化顶点
    for (i = 0; i < G->numVertexes; i++)
        G->vexs[i] = i;

    // 初始化邻接矩阵为 INF
    for (i = 0; i < G->numVertexes; i++)
        for (j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INF;

    // 读入边
    for (k = 0; k < G->numEdges; k++)
    {
        printf("输入边(vi, vj)的下标 i, j, 权值 w：");
        scanf("%d%d%d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = w; // 无向图对称
    }
}

// Dijkstra 算法：求 v0 到其余各顶点的最短路径
void Dijkstra(MGraph *G, int v0)
{
    int n = G->numVertexes;

    // dist[i]：当前 v0 到 i 的最短路径长度
    int dist[MAXVEX];
    // path[i]：i 的前驱顶点（用于回溯路径）
    int path[MAXVEX];
    // visited[i] = 1 表示顶点 i 已确定最短路径
    int visited[MAXVEX];

    int i, j, k, min;

    // 1. 初始化
    for (i = 0; i < n; i++)
    {
        dist[i] = G->arc[v0][i]; // v0 到 i 的直接距离
        visited[i] = 0;          // 都未确定
        path[i] = -1;            // 无前驱
    }
    dist[v0] = 0;    // 起点到自己距离 0
    visited[v0] = 1; // 起点已确定

    // 2. 循环 n-1 次，找剩下 n-1 个点的最短路径
    for (i = 1; i < n; i++)
    {
        min = INF;
        k = -1;

        // 找：未确定 + 距离最小 的顶点 k
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }

        // 没有可达顶点，退出
        if (k == -1)
            break;

        visited[k] = 1; // k 加入已确定集合

        // 3. 松弛操作：用 k 更新其他顶点的最短路径
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && G->arc[k][j] != INF && dist[k] + G->arc[k][j] < dist[j])
            {
                dist[j] = dist[k] + G->arc[k][j];
                path[j] = k;
            }
        }
    }

    // 4. 输出结果
    printf("\nDijkstra 算法（起点：%d）\n", v0);
    for (i = 0; i < n; i++)
    {
        printf("顶点 %d -> 顶点 %d 最短距离：%d\t路径：", v0, i, dist[i]);

        // 倒序打印路径
        int temp[MAXVEX], len = 0;
        int cur = i;
        while (cur != -1)
        {
            temp[len++] = cur;
            cur = path[cur];
        }
        for (j = len - 1; j >= 0; j--)
            printf("%d ", temp[j]);
        printf("\n");
    }
}

int main()
{
    MGraph G;
    CreateMGraph(&G);

    int start;
    printf("\n请输入起点编号：");
    scanf("%d", &start);

    Dijkstra(&G, start);
    return 0;
}