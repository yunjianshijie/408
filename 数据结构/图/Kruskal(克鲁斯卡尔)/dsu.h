
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXN 100005 // 最大元素数量，可根据需求修改

// 并查集核心数组
extern int parent[MAXN]; // parent[i] 表示元素i的父节点
extern int rank_[MAXN];   // rank_[i] 表示以i为根的树的高度（秩）

//
void dsu_init(int n);
int find(int x);
void unite(int x, int y);
bool isConnected(int x, int y);