#include <stdio.h>
#include <stdlib.h>

#define Max_VertexMum 100

// 边表结点
typedef struct Node
{
    int vid; // 指向的结点的下标
    struct Node *next;
} Node;

//
typedef struct Graph
{
    Node *vertex;
    int v_count;
} Graph;

Graph *create_graph(int v_count)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->vertex = (Node *)malloc(sizeof(Node) * v_count);
    for (int i = 0; i < g->v_count; i++)
    {
        g->vertex[i].vid = i;
        g->vertex[i].next = NULL;
    }
    g->v_count = v_count;
    return g;
}

void addNode(int v, int w, Graph *g)
{
    Node *vn = (Node *)malloc(sizeof(Node));
    vn->vid = v;
    vn->next = NULL;

    if (g->vertex[w].next == NULL)
    {
        g->vertex[w].next = vn;
        return;
    }
    Node *last = g->vertex[v].next;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = vn;
}

void addEdge(int v, int w, Graph *g)
{
    addNode(v, w, g);
    addNode(w, v, g);
}

typedef struct VE
{
    int *vs;
    int size;
} VE;

VE *get_adj(int s, Graph *g)
{
    Node n = g->vertex[s];
    Node *n1 = n.next;
    VE *ve = (VE *)malloc(sizeof(VE));
    ve->vs = (int *)malloc(sizeof(int) * g->v_count);
    ve->size = 0;
    while (n1!= NULL)
    {
        ve->vs[ve->size++]= n1->vid;
        n1 = n1->next;
    }
    return ve;
}

void graph_show(Graph * g){
    printf("图的顶点数为: %d\n", g->v_count);
    for (size_t i = 0; i < g->v_count; i++)
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
    //get_adj(0, g);
    graph_show(g);
    return 0;
}
