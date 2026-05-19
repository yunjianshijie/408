#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 1e9

typedef struct Graph
{
    int **vertex;
    int v_count;
} Graph;

typedef struct VE
{
    int *vs;
    int size;
} VE;

Graph *creat_graph(int n);
void addEdge(int i, int j, int info, Graph *g);
void show(Graph *g);
VE *get_adj(int s, Graph *g);