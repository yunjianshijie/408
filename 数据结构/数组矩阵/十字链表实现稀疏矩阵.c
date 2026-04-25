#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    int row_index;
    int col_index;
    struct Node *right;
    struct Node *down;
} Node;

typedef struct SLink
{
    Node **rows;
    Node **cols;
    int row_count;
    int col_count;
} SLink;

SLink *create_slink(int row_count, int col_count)
{
    SLink *sl = (SLink *)malloc(sizeof(SLink));
    sl->row_count = row_count;
    sl->col_count = col_count;
    sl->rows = (Node **)malloc(sizeof(Node *) * row_count);
    sl->cols = (Node **)malloc(sizeof(Node *) * col_count);
    return sl;
}

void add_row(Node *n, SLink *s)
{
    int row_index = n->row_index;
    if (s->rows[row_index] == NULL)
    {
        s->rows[row_index] = n;
        return;
    }
    Node *in = s->rows[row_index];
    Node *prev = NULL;
    while (in != NULL && n->col_index > in->col_index)
    {
        prev = in;
        in = in->right;
    }
    if (prev == NULL)
    {
        n->right = in;
        s->rows[row_index] = n;
    }
    else
    {
        prev->right = n;
        n->right = in;
    }
}
void add_col(Node *n, SLink *s)
{
    int col_index = n->col_index;
    if (s->cols[col_index] == NULL)
    {
        s->cols[col_index] = n;
        return;
    }
    Node *in = s->cols[col_index];
    Node *prev = NULL;
    while (in != NULL && n->row_index > in->row_index)
    {
        prev = in;
        in = in->down;
    }
    if (prev == NULL)
    {
        n->down = in;
        s->cols[col_index] = n;
    }
    else
    {
        prev->down = n;
        n->down = in;
    }
}
void add(int v, int row_index, int col_index, SLink *sl)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = v;
    n->right = NULL;
    n->down = NULL;
    n->row_index = row_index;
    n->col_index = col_index;
    // 单独处理行
    add_row(n, sl);
    // 单独处理列
    add_col(n, sl);
}

int main()
{
    SLink *sl = create_slink(3, 3);
    add(1, 0, 0, sl);
    add(2, 0, 2, sl);
    add(3, 1, 1, sl);
    add(4, 2, 0, sl);
    add(5, 2, 2, sl);
}