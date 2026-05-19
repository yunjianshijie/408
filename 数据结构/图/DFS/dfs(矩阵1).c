#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 50
typedef struct
{
    int data[MaxSize];
    int top;
} SqStack;


void InitStack(SqStack *s)
{
    s->top = -1;
}

SqStack *creat_stack(){
    SqStack * ret =(SqStack *)malloc(sizeof(SqStack));
    InitStack(ret);
    return ret;
}

bool StackEmpty(SqStack *s)
{
    // 如果是空栈
    if (s->top == -1)
    {
        return true;
    }
    return false;
}

// 入栈
bool Push(SqStack *s, int data)
{
    //
    if (s->top == MaxSize - 1)
    {
        return false;
    }
    s->top++;
    s->data[s->top] = data;
    return true;
}

// 出栈
bool Pop(SqStack *s, int *data)
{
    //
    if (s->top == -1)
    {
        return false;
    }
    *data = s->data[s->top];
    s->top--;
    return true;
}
// 读取栈顶元素
bool GetTop(SqStack *s, int *data)
{
    //
    if (s->top == -1)
    {
        return false;
    }
    *data = s->data[s->top];
    return true;
}

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


int visited[6] = {0};

void DFS(Graph *g, int i)
{
    printf("%d", i); // 只拜访
    visited[i] = 1;
    for (int j = 0; j < g->v_count; j++)
    {
        if (visited[j] != 1 && g->vertex[i][j] == 1)
        {
            DFS(g, j);
        }
    }
}

// s 是起始点，v 是当前结点的父节点
void dfs(int v, int s ,int * marked ,int * visit, Graph * g){
     marked[s] = 1;
     visit[s] =v;
     VE * ve = get_adj(s,g);
     for(int  i=0;i< ve->size;i++){
        int w =ve->vs[i];
        if(marked[w] != 1){
            dfs(s,w,marked,visit,g);
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
    // DFS(g, 1);
    int  marked[6] = {0};
    int  visit[6] = {0};

    dfs(5,5,marked,visit,g);

    int c =5;
    SqStack *ska = creat_stack();
    for (int i = 0; i < g->v_count; i++)
    {
        for(int j =i ;j!= c ;j =visit[j]){
            Push(ska, j);
        }
        printf("%d到顶点%d的一条路径是:",c,i);
        Push(ska, c);
        while (!StackEmpty(ska))
        {
            int k ;
            Pop(ska, &k);
            if ( k== i){
                printf("%d",k);
            }else{
                printf("%d->", k);
            }
        }
        printf("\n");
    }
}
