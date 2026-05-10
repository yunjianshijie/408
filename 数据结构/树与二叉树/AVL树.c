

#include <stdio.h>
#include <stdlib.h>

// 4种旋转方式
// LL 左左：左孩子的左子树插入 ->右旋
// RR 右右：右孩子的右子树插入 ->左旋
// LR 左右：左孩子的右子树插入 ->先左旋 ，后右旋
// RL 右左：右孩子的左子树插入 → 先右旋、再左旋

//
typedef struct AVLTreeNode
{
    int data;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
    int height; // 高度：左子树高度 - 右子树高度（这个节点的）
} AVLNode;

int getHeight(AVLNode *node)
{
    if (node == NULL)
    {
        // 如果是空节点 ，高低差为0
        return 0;
    }
    return node->height;
}

// 更新高度
void updateHeight(AVLNode *node)
{
    // 左边高度
    int lh = getHeight(node->left);
    int rh = getHeight(node->right);
    // 如果左边更高 ，节点高度 = 左高度 +1
    // 那边更高，哪边就
    if (lh > rh)
    {
        node->height = lh + 1;
    }
    else
    {
        node->height = rh + 1;
    }
}

// 平衡因子
int getBalance(AVLNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    // 平衡因子：左边的高度减去右边的高度
    getHeight(node->left) - getHeight(node->right);
}

// 右旋
AVLNode *rightRotate(AVLNode *x)
{
    AVLNode *y = x->left;
    AVLNode *T3 = y->right;

    y->right = x;
    x->left = T3;

    updateHeight(x);
    updateHeight(y);
    return y;
}

// 左旋
AVLNode *leftRotate(AVLNode *x){
    AVLNode * y = x->right;
    AVLNode * T3 = y ->left;

    y->left = x;
    x->right = T3;

    // 只有xy 这两个节点
    updateHeight(x);
    updateHeight(y);
    return y;
}


// 插入值 更新节点
AVLNode *Insert(AVLNode *node, int data)
{
    // 正常递归
    if (node == NULL)
    {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->data = data;
        newNode->height = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // BST 查找位置插入
    if (data < node->data)
    {
        node->left = Insert(node->left, data);
    }
    else
    {
        node->right = Insert(node->right, data);
    }

    // 更新当前节点高度
    updateHeight(node);

    // 计算平衡因子
    int balance = getBalance(node);

    // 四种处理
    // LL左旋的
    if(balance > 1 && getBalance(node->left) >= 0){
        return rightRotate(node);
    }
    // RR 右旋
    
}
