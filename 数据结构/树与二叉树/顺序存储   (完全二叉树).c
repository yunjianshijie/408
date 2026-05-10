#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
// 完全二叉树是可以使用顺序存储来存储的树(其他使用顺序结构来使用的话需要空0)

typedef struct Tree
{
    int size; // 树的节点数量
    int data[MAX_SIZE]; // 存储树节点的数组
} Tree;

// 创建完全二叉树
Tree *createCompleteBinaryTree()
{
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->size = 0;
    return tree;
}

void insert(Tree *tree, int value)
{
    tree->data[tree->size++] = value; // 将新节点添加到数组末尾
}

// 前序遍历
void preOrder(Tree *tree, int index){
    if(index < tree->size){
        printf("%d ", tree->data[index]);
        preOrder(tree, 2 * index + 1); // 遍历左子树
        preOrder(tree, 2 * index + 2); // 遍历右子树
    }
}

// 中序遍历
void inOrder(Tree *tree, int index){
    if(index < tree->size){
        inOrder(tree, 2 * index + 1); // 遍历左子树
        printf("%d ", tree->data[index]);
        inOrder(tree, 2 * index + 2); // 遍历右子树
    }
}

// 后序遍历
void postOrder(Tree *tree, int index){ 
    if(index < tree->size){
        postOrder(tree, 2 * index + 1); // 遍历左子树
        postOrder(tree, 2 * index + 2); // 遍历右子树
        printf("%d ", tree->data[index]);
    }
}


// 删除需要移元素，就不写了。。。
int main()
{
    Tree *tree = createCompleteBinaryTree();
    insert(tree, 1);
    insert(tree, 2);
    insert(tree, 3);
    insert(tree, 4);
    insert(tree, 5);
    insert(tree, 6);
    insert(tree, 7);

    printf("前序遍历：");
    preOrder(tree, 0);
    printf("\n");

    printf("中序遍历：");
    inOrder(tree, 0);
    printf("\n");

    printf("后序遍历：");
    postOrder(tree, 0);
    printf("\n");

    free(tree);
    return 0;
}
