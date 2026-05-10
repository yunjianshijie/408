#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000
// 完全二叉树是可以使用顺序存储来存储的树(其他使用顺序结构来使用的话需要空0)

typedef struct Tree
{
    int size;           // 树的节点数量
    int data[MAX_SIZE]; // 存储树节点的数组
} Tree;

// 创建完全二叉树
Tree *createCompleteBinaryTree()
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->size = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        tree->data[i] = -1; // 初始化为-1，表示空节点
    }
    return tree;
}

void insert(Tree *tree, int value)
{
    // 头插法插入节点
    if (tree->data[0] == -1)
    {
        tree->data[0] = value;
        return;
    }
    int index = 0;
    //
    while (tree->data[index] != -1)
    {
        if (value < tree->data[index])
        {
            index = 2 * index + 1; // 左子树
        }
        else if (value > tree->data[index])
        {
            index = 2 * index + 2; // 右子树
        }
    } tree->data[index] = value; // 插入新节点
        tree->size++;
}

// 前序遍历
void preOrder(Tree *tree, int index)
{
    if (index < MAX_SIZE && tree->data[index] != -1)
    {
        return; // 确保索引在范围内且节点不为空
    }
    printf("%d ", tree->data[index]);
    preOrder(tree, 2 * index + 1); // 遍历左子树
    preOrder(tree, 2 * index + 2); // 遍历右子树
}

// 中序遍历
void inOrder(Tree *tree, int index)
{
    if (index < MAX_SIZE && tree->data[index] != -1)
    {
        inOrder(tree, 2 * index + 1); // 遍历左子树
        printf("%d ", tree->data[index]);
        inOrder(tree, 2 * index + 2); // 遍历右子树
    }
}

// 后序遍历
void postOrder(Tree *tree, int index)
{
    if (index < MAX_SIZE && tree->data[index] != -1)
    {
        postOrder(tree, 2 * index + 1); // 遍历左子树
        postOrder(tree, 2 * index + 2); // 遍历右子树
        printf("%d ", tree->data[index]);
    }
}


int main()
{
    Tree *tree = createCompleteBinaryTree();
    int a[] = {1, 2, 3, 4, 5};
    printf("%d", a[1]);
    for (int i = 0; i < 5; i++)
    {  
        printf("%d", a[i]);      
    }
    printf("前序遍历：");
    preOrder(tree, 0);
    printf("\n");

    // printf("中序遍历：");
    // inOrder(tree, 0);
    // printf("\n");

    // printf("后序遍历：");
    // postOrder(tree, 0);
    // printf("\n");

    // free(tree);
    return 0;
}
