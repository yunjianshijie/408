#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
#define INF 65535

// 边结构体
typedef struct Edge
{
    int u;      // 起点
    int v;      // 终点
    int weight; // 权值
} Edge;

// 邻接矩阵图
typedef struct
{
    int vex[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int vexNum, edgeNum;
} MGraph;

// 并查集父数组
int parent[MAXVEX];

// 并查集查找根节点 + 路径压缩
int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// 合并集合
void unite(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        parent[fy] = fx;
}

// 边排序比较函数
int cmp(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// 创建邻接矩阵无向网
void CreateGraph(MGraph *G)
{
    int i, j, w;
    printf("输入顶点数 边数：");
    scanf("%d%d", &G->vexNum, &G->edgeNum);

    // 初始化顶点
    for (i = 0; i < G->vexNum; i++)
        G->vex[i] = i;

    // 矩阵初始化为无穷
    for (i = 0; i < G->vexNum; i++)
        for (j = 0; j < G->vexNum; j++)
            G->arc[i][j] = INF;

    // 录入边
    for (int k = 0; k < G->edgeNum; k++)
    {
        scanf("%d%d%d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = w;
    }
}

// Kruskal最小生成树
void Kruskal(MGraph *G)
{
    Edge edges[MAXVEX * MAXVEX];
    int cnt = 0;
    int total = 0;

    // 1. 提取所有有效边
    for (int i = 0; i < G->vexNum; i++)
    {
        for (int j = i + 1; j < G->vexNum; j++)
        {
            if (G->arc[i][j] != INF)
            {
                edges[cnt].u = i;
                edges[cnt].v = j;
                edges[cnt].weight = G->arc[i][j];
                cnt++;
            }
        }
    }

    // 2. 边按权值升序排序
    qsort(edges, cnt, sizeof(Edge), cmp);

    // 3. 初始化并查集
    for (int i = 0; i < G->vexNum; i++)
        parent[i] = i;

    // 4. 遍历选边
    int select = 0;
    for (int i = 0; i < cnt; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(u) != find(v))
        {
            unite(u, v);
            printf("选取边 %d-%d 权值：%d\n", u, v, w);
            total += w;
            select++;
            // 选够n-1条直接退出
            if (select == G->vexNum - 1)
                break;
        }
    }
    printf("最小生成树总权值：%d\n", total);
}

int main()
{
    MGraph G;
    CreateGraph(&G);
    printf("\nKruskal算法最小生成树：\n");
    Kruskal(&G);
    return 0;
}