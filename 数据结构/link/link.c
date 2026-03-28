#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 带头节点的单链表 
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

void print(LinkList L){
    //
    LNode * p = L;
    printf("开始：");
    while(p!=NULL && p->next != NULL) {
        p =p->next;
        printf(" -> %d",p->data);
    }
}

bool init_list(LinkList *L){
    *L = (LNode *)malloc(sizeof(LNode)); // 创建头结点
    if(*L == NULL) return false;
    (*L)->next = NULL;
    return true;
}

int Lenght(LinkList L){
    int count = 0;
    LNode * p = L;
    while( p ->next != NULL ){
        count ++;
        p = p->next;
    }
    return count;
}


LNode *GetElem(LinkList L, int i){
    LNode *p = L;
    for(int j =0; j< i;j++){
        if (p==NULL){
            return NULL;
        }
        p = p->next;
    }
    return p;
}

LNode *Locat_elem(LinkList L , int data){
    LNode *p = L;
    while (p!=NULL && p->next != NULL)
    {
        p=p->next;
        if (p->data == data){
            return p;
        } 
    }
    
}

// 
bool ListInsert(LinkList L, int i ,int data){
    LNode *p = L;
    for (int j= 0; j <i-1 ;j++){
        // 找前置节点
        p=p->next;
    }
    if (p== NULL){
        return false;
    }
    LNode *temp = (LNode *)malloc(sizeof(LNode));   
    temp -> data =data;
    temp -> next = p->next;
    p->next = temp;
    return true;    
}



// 头插 (新弄一个链表？)
LinkList List_head_insert(LinkList L,int data){
    LNode * p =L;    
}

//




int main(){
    


}  