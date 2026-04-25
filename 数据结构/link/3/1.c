//#include <stdio.h>
//#include <stdlib.h>
//typedef struct Node{
//	int value;
//	struct Node * next;
//}Node;
//void init(Node * head){
//	head->value = -888;
//	head->next = NULL;
//}
//void insert(int v,Node * h){
//	if(h->value == -888){ //处理头节点
//		h->value = v;
//		return ;
//	}
//	Node * n = (Node *)malloc(sizeof(Node));
//	n->value = v;
//	n->next = NULL;
//	Node * last = h;
//	while(last->next!=NULL){
//		last = last->next;
//	}
//	last->next = n;
//}
//void show(Node * head){
//	if(head->value == -888){
//		printf("链表为空\n");
//		return;
//	}
//	while(head!=NULL){
//		printf("%d ",head->value);
//		head = head->next;
//	}
//	printf("\n");
//}
//void del_value(int v,Node * head){
//	if(head->value == -888){
//		return ;
//	}
//	Node * n;
//	if(v == head->value){
//		n = head->next;
//		if(n == NULL){
//			head->value = -888;
//			return ;
//		}
//		head->value = n->value;
//		head->next = n->next;
//		free(n);
//		return ;
//	}
//	Node * del = head->next;
//	Node * prev = head;
//	while(del!=NULL && del->value != v){
//		prev = del;
//		del = del->next;
//	}
//	if(del != NULL){
//		prev->next = del->next;
//		free(del);
//	}
//
//}
//void del_value2(int v,Node * head){
//
//	Node * del = head;
//	Node * prev = NULL;
//	while(del!=NULL && del->value != v){
//		prev = del;
//		del = del->next;
//	}
//	if(prev == NULL){
//		Node * n;
//		n = head->next;
//		if(n == NULL){
//			head->value = -888;
//			return ;
//		}
//		head->value = n->value;
//		head->next = n->next;
//		free(n);
//		return ;
//	}
//	if(del != NULL){
//		prev->next = del->next;
//		free(del);
//	}
//
//}
//
//int main(){
//	Node head;
//	init(&head);
//	insert(11,&head);
//	insert(12,&head);
//	insert(13,&head);
//	insert(14,&head);
//	show(&head);
//	del_value(14,&head);
//	show(&head);
//	del_value(12,&head);
//	show(&head);
//	del_value(11,&head);
//	show(&head);
//	del_value(13,&head);
//	show(&head);
//
//
//
//}
//
//
//
//
//
//
//
//
//
