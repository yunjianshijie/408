#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int parent[MAXN]; // parent[i] 表示元素i的父节点
int rank_[MAXN];  // rank_[i] 表示以i为根的树的高度（秩）
