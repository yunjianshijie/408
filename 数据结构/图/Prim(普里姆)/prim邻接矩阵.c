#include "graph_matrix.h"

#define graph_vnum 6

void Prim(Graph *g)
{
    //
    int lowcost[graph_vnum];
    // 保存前驱结点
    int adjvex[graph_vnum];
    //
    int sum = 0;

    int v0 = 0;

    // 将0到所有结点的距离保存
    for (int i = 1; i < g->v_count; i++)
    {
        lowcost[i] = g->vertex[v0][i];
        if (g->vertex[v0][i] != INT_MAX)
            adjvex[i] = v0;
    }
    for (int i = 1; i < g->v_count; i++)
    {
        int min = INT_MAX;
        int minvex = -1;
        for (int j = 0; j < g->v_count; j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                minvex = j;
            }
        }
        // // 这里找到最小输出
        printf("边%d->%d , 权值：%d \n", adjvex[minvex], minvex, min);
        sum += min;
        // // 这里循环给找这个点的最小值 jilu
        lowcost[minvex] = 0;
        for (int j = 0; j < g->v_count; j++)
        {
            if (lowcost[j] > g->vertex[minvex][j])
            {
                lowcost[j] = g->vertex[minvex][j];
                adjvex[j] = minvex;
            }
        }
    }
    printf("最小生成树最小权值和为 %d\n", sum);
}

int main()
{
    Graph *g = creat_graph(graph_vnum);
    addEdge(0, 1, 6, g);
    addEdge(0, 2, 1, g);
    addEdge(0, 3, 5, g);
    addEdge(1, 2, 5, g);
    addEdge(1, 4, 3, g);
    addEdge(2, 3, 5, g);
    addEdge(2, 4, 6, g);
    addEdge(2, 5, 4, g);
    addEdge(3, 5, 2, g);
    addEdge(4, 5, 6, g);
    VE *s = get_adj(1, g);
    Prim(g);
}