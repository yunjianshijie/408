
#include <stdio.h>
#include <stdlib.h>

typedef struct Bree_node
{
    int value;
    struct Bree_node *lchild;
    struct Bree_node *rchild;
} Node;

typedef struct BTree
{
    Node *root;
    int size;
} BTree;

BTree *Create_BTree()
{
    BTree *ret = (BTree *)malloc(sizeof(BTree));
    ret->root = NULL;
    ret->size = 0;
    return ret;
}
// 非递归插入
void insert(BTree *t,int v){
    Node *n = (Node *)malloc(sizeof(Node));
    n->lchild =NULL;
    n->rchild =NULL;
    n->value = v;
    if(t->root ==NULL){
        t->root =n;
        return;
    }
    Node * p = t->root;
    while (1)
    {
        if(v <p->value){
            if(p->lchild == NULL){
                p->lchild = n;
                return;
            }
            p=p->lchild;
        }else if(v > p->value ){
            if(p->rchild ==NULL){
                p->rchild =n;
                return;
            }
            p=p->rchild;
        }
    }
    return ;
}
Node *create_node(int v)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->lchild = NULL;
    n->rchild = NULL;
    n->value = v;
    return n;
}
Node * findInsert(Node *p, int v)
{
    if( p == NULL){
        return create_node(v);
    }
    if (v < p->value)
    {
       p->lchild = findInsert(p->lchild,v);
    }
    else if (v > p->value)
    {
     p->rchild =findInsert( p->rchild  ,v);
    }
    return p ; // 这里会返回当前节点的地址，递归调用会将新节点连接到树上
}

void insert_recursion1(BTree *t,int v){
    if(t->root ==NULL){
        t->root = create_node(v);
        return;
    }
    findInsert(t->root,v);
}

// 递归插入
void insert_recursion(BTree *t, Node **p, int v)
{
    if (*p == NULL)
    {
        Node *n = (Node *)malloc(sizeof(Node));
        n->lchild = NULL;
        n->rchild = NULL;
        n->value = v;
        *p = n; //
        return;
    }
    if (v < (*p)->value)
    {
        insert_recursion(t, &((*p)->lchild), v);
    }
    else if (v > (*p)->value)
    {
        insert_recursion(t, &((*p)->rchild), v);
    }
}

//前序遍历
void preOrder(BTree *tree,Node * q){
    if(q == NULL){
        return;
    }
    printf("%d ",q->value);
    preOrder(tree,q->lchild);
    preOrder(tree,q->rchild);
}

int main(){
    //
    BTree * tree = Create_BTree();
    insert(tree,31);
    insert(tree,21);
    insert(tree,41);
    insert(tree,11);
    insert(tree,26);
    insert(tree,35);
    //insert(tree,51);

    //insert_recursion(tree, &tree->root, 51);
    insert_recursion1(tree,  51);
    printf("前序遍历：");
    preOrder(tree, tree->root);
    
    return 0;
}