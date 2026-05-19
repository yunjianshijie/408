#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

#define INT_MAX 1e9

typedef struct Graph
{
    int **vertex;
    int v_count;
} Graph;

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

void addEdge(int i, int j, Graph *g)
{
    g->vertex[i][j] = 1;
    g->vertex[j][i] = 1;
}
void graph_show(Graph *g)
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

typedef struct VE
{
    int *vs;
    int size;
} VE;

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





// 广度优先搜索
void bfs(Graph * g , int i , bool * visited , SqQueue * q){
    printf("%d ", i);
    visited[i] = true ;
    // 将顶点顶入栈
    EnQueue(q, i);
    while(!Queue_Empty(q)){
        int v =DeQueue(q);
        // 访问所有邻接点
        VE * ve = get_adj(v,g);
        for(int i =0 ;i<ve->size ;i++){
            if(!visited[ve->vs[i]]){
                printf("%d ", ve->vs[i]);
                visited[ve->vs[i]] = true;
                EnQueue(q, ve->vs[i]);
            }
        }
    }
}



int main()
{
    Graph *g = creat_graph(6);
    addEdge(0, 1, g);
    addEdge(0, 3, g);
    addEdge(0, 4, g);
    addEdge(1, 4, g);
    addEdge(1, 2, g);
    addEdge(1, 5, g);
    addEdge(2, 5, g);
    addEdge(3, 4, g);
    addEdge(3, 5, g);
    // VE *s = get_adj(1, g);
    
    bool * visited = (bool*)malloc(sizeof(bool)* g->v_count);
    SqQueue * q = creat_queue();
    bfs(g,0,visited,q);

    return 0;
}