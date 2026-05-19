#include "graph_matrix.h"
#include "dsu.h"
#define graph_vnum 6

int parent[MAXN]; // parent[i] 表示元素i的父节点
int rank_[MAXN];  // rank_[i] 表示以i为根的树的高度（秩）

typedef struct Edge
{
    int u;
    int v;
    int info; // 权值
} Edge;

int cmp(const void *a, const void *b)
{
    return ((Edge *)a)->info - ((Edge *)b)->info;
}

void kruskal(Graph * g){
    // 可以把边存储到一个堆里来拿取最小值。
    // 这里是放一起排序。
    Edge edges[graph_vnum * graph_vnum];

    // 边的条数
    int count =0 ;

    for (int i = 0; i < g->v_count; i++)
    {
        for (int j = i + 1; j < g->v_count; j++)
        {
            if (g->vertex[i][j] != INT_MAX)
            {
                edges[count].u = i;
                edges[count].v = j;
                edges[count].info = g->vertex[i][j];
                count++;
            }
        }
    }

    // 排序
    qsort(edges, count, sizeof(Edge), cmp);

    // 初始化并查集
    dsu_init(g->v_count);
    // 
    int nums = 0;
    // 总权值
    int sum = 0;

    // 开始选边
    for(int i =0 ;i< g->v_count ;i++){
        // 从小到大的选择。
        if(!isConnected(edges[i].u,edges[i].v)){
            // 合并
            unite(edges[i].u, edges[i].v);
            // 输出
            printf("顶点：%d->%d ， 权值： %d\n",edges[i].u,edges[i].v,edges[i].info);
            sum += edges[i].info;
            nums++;
        }
        // 
        if(nums == g->v_count-1){
            break;
        }
    }
    printf("总权值为:%d\n",sum);
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
    kruskal(g);
}