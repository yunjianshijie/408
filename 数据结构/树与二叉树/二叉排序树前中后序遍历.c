#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int value;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

BiTree Create_BTree()
{
    BiTree ret = (BiTree)malloc(sizeof(BiTree));
    ret->lchild = NULL;
    ret->rchild = NULL;
    return ret;
}

