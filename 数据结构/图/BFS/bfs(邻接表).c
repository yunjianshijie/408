#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <stdbool.h>

#define Max_VertexMum 100

// 边表结点
typedef struct ArcNode
{
    int adjvex; // 指向的结点的下标
    struct ArcNode *nextarc;
} ArcNode;

// 顶点结点
typedef struct VNode
{
    int adjvex;
    ArcNode *firstarc;
} VNode, AdjList[Max_VertexMum];

//
typedef struct Graph
{
    // 原书写最大数组，改了一下
    // AdjList vertices;
    VNode *vertices;
    // 顶点数， 弧数
    int vexnum, arcnum;
} Graph;

//

Graph *create_graph(int v_count)
{
    Graph *q = (Graph *)malloc(sizeof(Graph));
    q->vertices = (VNode *)malloc(sizeof(VNode) * v_count);
    q->vexnum = v_count;
    q->arcnum = 0;
    return q;
}

void AddNode(int v, int w, Graph *g)
{
    ArcNode *vn = (ArcNode *)malloc(sizeof(ArcNode));
    vn->nextarc = NULL;
    vn->adjvex = v;
    if (g->vertices[w].firstarc == NULL)
    {
        g->vertices[w].firstarc = vn;
        return;
    }
    ArcNode *n = g->vertices[w].firstarc;
    while (n->nextarc != NULL)
    {
        n = n->nextarc;
    }
    n->nextarc = vn;
}

void addEdge(int v, int w, Graph *g)
{
    AddNode(v, w, g);
    AddNode(w, v, g);
    g->arcnum++;
}
typedef struct VE
{
    int *vs;
    int size;
} VE;

VE *get_adj(int s, Graph *g)
{
    VE *ve = (VE *)malloc(sizeof(VE));
    ve->vs = (int *)malloc(sizeof(int) * g->vexnum);
    ve->size = 0;
    ArcNode *n = g->vertices[s].firstarc;
    while (n != NULL)
    {
        // printf("%d", n->adjvex);
        ve->vs[ve->size++] = n->adjvex;
        n = n->nextarc;
    }
    return ve;
}

void Graph_show(Graph *g)
{
    printf("图的顶点数为: %d\n", g->vexnum);
    for (size_t i = 0; i < g->vexnum; i++)
    {
        printf("顶点%d 连接边的顶点:", i);
        VE *ve = get_adj(i, g);
        for (int j = 0; j < ve->size; j++)
        {
            printf("%d ", ve->vs[j]);
        }
        printf("\n");
    }
}

// bfs
void bfs(Graph *g, int i, bool *visited, SqQueue *q)
{
    //  拜访先打印
    printf("%d",i);
    visited[i] = true;
    EnQueue(q,i);
    while (!Queue_Empty(q))
    {
        int s  = DeQueue(q);
        VE *ve = get_adj(s,g);
        for(int i =0; i< ve->size ;i++){
            if(!visited[ve->vs[i]]){
                EnQueue(q,ve->vs[i]);
                printf("%d",ve->vs[i]);
                visited[ve->vs[i]] = true;
            }
        }
    }
}

int main()
{
    Graph *g = create_graph(6);
    addEdge(0, 1, g);
    addEdge(0, 3, g);
    addEdge(0, 4, g);
    addEdge(1, 4, g);
    addEdge(1, 2, g);
    addEdge(1, 5, g);
    addEdge(2, 5, g);
    addEdge(3, 4, g);
    addEdge(3, 5, g);
    Graph_show(g);

    bool *visited = (bool *)malloc(sizeof(bool) * g->vexnum);
    SqQueue *q = creat_queue();
    bfs(g, 0, visited, q);

    return 0;
}