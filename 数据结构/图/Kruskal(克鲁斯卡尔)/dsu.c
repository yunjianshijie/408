#include "dsu.h"

int parent[MAXN]; // parent[i] 表示元素i的父节点
int rank_[MAXN];  // rank_[i] 表示以i为根的树的高度（秩）

// 初始化并查集：每个元素的父节点是自己，树高为1
void dsu_init(int n)
{
    for (int i = 1; i <= n; i++)
    { // 元素编号从1开始（也可改为0）
        parent[i] = i;
        rank_[i] = 1;
    }
}

// 查找操作 + 路径压缩
int find(int x)
{
    // 递归实现：找到根节点后，直接将路径上所有节点的父节点指向根（路径压缩）
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// 合并操作 + 按秩合并（把矮的树挂到高的树上）
void unite(int x, int y)
{
    // 先找到两个元素的根节点
    int root_x = find(x);
    int root_y = find(y);

    //  already in the same set
    if (root_x == root_y)
    {
        return;
    }

    // 按秩合并：将高度小的树挂到高度大的树的根上
    if (rank_[root_x] < rank_[root_y])
    {
        parent[root_x] = root_y;
    }
    else
    {
        parent[root_y] = root_x;
        // 如果两棵树高度相同，合并后高度+1
        if (rank_[root_x] == rank_[root_y])
        {
            rank_[root_x]++;
        }
    }
}

// 判断两个元素是否连通
bool isConnected(int x, int y)
{
    return find(x) == find(y);
}
