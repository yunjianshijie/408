#include "graph_matrix.h"

void init(Graph *g, int v_count);
Graph *creat_graph(int n)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    init(g, n);
    return g;
}

void init(Graph *g, int v_count)
{
    g->v_count = v_count;
    g->vertex = (int **)malloc(sizeof(int *) * v_count);
    for (int i = 0; i < v_count; i++)
    {
        g->vertex[i] = (int *)malloc(sizeof(int) * v_count);
        for (int j = 0; j < v_count; j++)
        {
            if (i == j)
            {
                g->vertex[i][j] = 0;
            }
            else
            {
                g->vertex[i][j] = INT_MAX;
            }
        }
    }
}

void addEdge(int i, int j, int info, Graph *g)
{
    g->vertex[i][j] = info;
    g->vertex[j][i] = info;
}
void show(Graph *g)
{
    for (int i = 0; i < g->v_count; i++)
    {
        for (int j = 0; j < g->v_count; j++)
        {
            if (g->vertex[i][j] == INT_MAX)
            {
                printf("M ");
            }
            else
            {
                printf("%d ", g->vertex[i][j]);
            }
        }
        printf("\n");
    }
}

VE *get_adj(int s, Graph *g)
{
    VE *ve = (VE *)malloc(sizeof(VE));
    ve->vs = (int *)malloc(sizeof(int) * g->v_count);
    int count = 0;
    for (int i = 0; i < g->v_count; i++)
    {
        if (g->vertex[i][s] == 1)
        {
            ve->vs[ve->size++] = i;
        }
    }
    return ve;
}
